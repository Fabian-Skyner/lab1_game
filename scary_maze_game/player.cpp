#include "player.h"

using namespace std;
using namespace sf;

void Player::Update(double dt) {
	//MOVE, DAMMIT
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		Entity::move(Vector2f(0, _speed));	//y+ 
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		Entity::move(Vector2f(- _speed, 0));	//x- 
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		Entity::move(Vector2f(0, - _speed));	//y- 
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		Entity::move(Vector2f(_speed, 0));	//x+ 
	}
	
	Entity::Update(dt);
}

Player::Player() : _speed(200.0f), Entity( make_unique<CircleShape>(25.f) ) {
	_shape -> setFillColor(Color::Magenta);
	_shape -> setOrigin( Vector2f(25.f, 25.f) );
}

void Player::Render(sf::RenderWindow &window) const {
	window.draw(* _shape);
}