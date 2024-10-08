#include "ship.h"
#include "game.h"
using namespace sf;
using namespace std;

// ship stuf
Ship::Ship() {};

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
}