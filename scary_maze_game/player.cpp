#include "player.h"
#include "game.h"
#include <cmath> // needed for square root function

using namespace std;
using namespace sf;

void Player::Update(double dt) {
	// the vast majority of this code was generously donated by Hannah Vanderstraeten
	const float moveSpeed = 200.f;	// movement speed (units/second)
	
	sf::Vector2f position = getPosition();
	
	// handle horizontal movement
	float moveX = 0.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		moveX -= moveSpeed * dt;
	}	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		moveX += moveSpeed * dt;
	}
	
	// handle vertical movement
	float moveY = 0.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		moveY -= moveSpeed * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		moveY += moveSpeed * dt;
	}
	
	// nomralize diagonal move speed
	if (moveX != 0 && moveY != 0) {
		float diagonalSpeedFactor = std::sqrt(2.f); // scale speed by root 2 when moving diagonally because a^2 + b^2 = c^2
		moveX /= diagonalSpeedFactor;
		moveY /= diagonalSpeedFactor;
	}
	
	// update position
	position.x += moveX;
	position.y += moveY;
	
	// nudge player into bounds of screen if out of them
	if (position.x < 25) {
		position.x = 25;
	} else if (position.x > gameWidth - 25) {
		position.x = gameWidth - 25;
	}
	if (position.y < 25) {
		position.y = 25;
	} else if (position.y > gameHeight - 25) {
		position.y = gameHeight - 25;
	}
	
	setPosition(position);
	
	Entity::Update(dt);
}

Player::Player() : _speed(200.0f), Entity( make_unique<CircleShape>(25.f) ) {
	_shape -> setFillColor(Color::Magenta);
	_shape -> setOrigin( Vector2f(25.f, 25.f) );
}

void Player::Render(sf::RenderWindow &window) const {
	window.draw(* _shape);
}