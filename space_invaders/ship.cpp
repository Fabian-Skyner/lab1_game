#include "ship.h"
#include "game.h"
using namespace sf;
using namespace std;

// ship stuf
Ship::Ship() {};
bool Invader::direction;
float Invader::speed;

Ship::Ship(IntRect ir) : Sprite() {
	_sprite = ir;
	setTexture(spritesheet);
	setTextureRect(_sprite);
};

void Ship::Update(const float &dt) {}

// defines the ship deconstructor, despite being pure virtual
Ship::~Ship() = default;

// invader stuf
Invader::Invader() : Ship() {}

Invader::Invader(IntRect ir, sf::Vector2f pos) : Ship(ir) {
	setOrigin( Vector2f(16.f, 16.f) );
	setPosition(pos);
}

void Invader::Update(const float &dt) {
	Ship::Update(dt);
	// move horizontally in a direction with speed over time, do nothing vertically
	move(Vector2f(dt * (direction ? 1.0f : -1.0f) * speed , 0.0f));
	
	if ((direction && getPosition().x > gameWidth - 16) || (!direction && getPosition().x < 16)) {
		direction = !direction;
		for (int i = 0; i < ships.size(); ++i){
			ships[i]->move(Vector2f(0.0f, 24.0f));
		}
	}

}