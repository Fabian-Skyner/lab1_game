#include <SFML/Graphics.hpp>
// TODO - Two Player and Validated Moves onward
using namespace sf;
using namespace std;

const Keyboard::Key controls[4] = {
	Keyboard::W,	// Player1 UP
	Keyboard::S,	// Player1 DOWN
	Keyboard::Up,	// Player2 UP
	Keyboard::Down	// Player2 DOWN
};

const Vector2f paddleSize(25.f, 100.f);
const float ballRadius = 10.f;
const int gameWidth = 800;
const int gameHeight = 600;
const float paddleSpeed = 400.f;
const float paddleOffsetWall = 10.f;

Vector2f ballVelocity;
bool player1Serve = false;
const float initalVelocityX = 100.f;
const float initalVelocityY = 60.f;
const float velocityMult = 1.1f;

CircleShape ball;
RectangleShape paddles[2];

void Reset() {
	// reset paddle position
	paddles[0].setPosition(Vector2f(paddleOffsetWall + paddleSize.x / 2.f, gameHeight / 2.f));
	paddles[1].setPosition(Vector2f(gameWidth - paddleOffsetWall - paddleSize.x / 2.f, gameHeight / 2.f));
	// reset ball position
	ball.setPosition(Vector2f(gameWidth / 2.f, gameHeight / 2.f));
	// initialise ball movement
	ballVelocity = { (player1Serve ? initalVelocityX : -initalVelocityX), initalVelocityY };
}

void Load() {
	// set size and origin of paddles
	for (auto &p : paddles) {
		p.setSize(paddleSize);
		p.setOrigin(paddleSize / 2.f);
	}
	// set size and origin of ball
	ball.setRadius(ballRadius);
	ball.setOrigin(ballRadius, ballRadius);
	Reset();
}

void Update(RenderWindow &window) {
	// reset clock, recalculate deltatime
	static Clock clock;
	float dt = clock.restart().asSeconds();
	// check and consume events
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			window.close();
			return;
		}
	}
	
	// quit via ESC key
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}
	
	// handle paddle movement
	float p1direction = 0.0f;
	float p2direction = 0.0f;
	if (Keyboard::isKeyPressed(controls[0])) {
		p1direction--;
	}
	if (Keyboard::isKeyPressed(controls[1])) {
		p1direction++;
	}
	if (Keyboard::isKeyPressed(controls[2])) {
		p2direction--;
	}
	if (Keyboard::isKeyPressed(controls[3])) {
		p2direction++;
	}
	
	paddles[0].move(Vector2f(0.f, p1direction * paddleSpeed * dt));
	paddles[1].move(Vector2f(0.f, p2direction * paddleSpeed * dt));
	
	// calculate ball movement
	ball.move(ballVelocity * dt);
	
	// check ball collision
	const float bx = ball.getPosition().x;
	const float by = ball.getPosition().y;
	if (by > gameHeight) {
		// top wall hit, move down and out of it
		ballVelocity.x *= velocityMult;
		ballVelocity.y *= -velocityMult;
		ball.move(Vector2f(0.f, -10.f));
	} else if (by < 0) {
		// bottom wall hit, move up and out of it
		ballVelocity.x *= velocityMult;
		ballVelocity.y *= -velocityMult;
		ball.move(Vector2f(0.f, 10.f));
	} else if (bx > gameWidth) {
		// right wall hit
		Reset();
	} else if (bx < 0) {
		// left wall hit
		Reset();
	} else if (	bx < paddleSize.x + paddleOffsetWall &&					// is ball inline with or behind paddle,
				by > paddles[0].getPosition().y - (paddleSize.y * 0.5) &&	// below top edge of paddle,
				by < paddles[0].getPosition().y + (paddleSize.y * 0.5))	// and above bottom edge of paddle?
	{
		// left paddle hit, move right and out of it
		ballVelocity.x *= -velocityMult;
		ballVelocity.y *= velocityMult;
		ball.move(Vector2f(10.f, 0.f));
	} else if (	bx > gameWidth - paddleSize.x - paddleOffsetWall &&		// is ball inline with or behind paddle,
				by > paddles[1].getPosition().y - (paddleSize.y * 0.5) &&	// below top edge of paddle,
				by < paddles[1].getPosition().y + (paddleSize.y * 0.5))	// and above bottom edge of paddle?
	{
		// right paddle hit, move left and out of it
		ballVelocity.x *= -velocityMult;
		ballVelocity.y *= velocityMult;
		ball.move(Vector2f(-10.f, 0.f));
	}
	
	
}

void Render(RenderWindow &window) {
	// draw all the things
	window.draw(paddles[0]);
	window.draw(paddles[1]);
	window.draw(ball);
}

int main() {
	RenderWindow window(VideoMode(gameWidth, gameHeight), "PONG");
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}