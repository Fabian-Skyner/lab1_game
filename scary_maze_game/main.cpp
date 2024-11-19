#include <SFML/Graphics.hpp>
#include <iostream>
#include "entity.h"
#include "player.h"
#include "game.h"

using namespace std;
using namespace sf;

//const int gameWidth = 800;
//const int gameHeight = 600;

std::unique_ptr<Player> player; // note to self - this is not even close to corr- nevermind it works?

void Reset() {
	player = std::make_unique<Player>();
	player -> setPosition(Vector2f(gameWidth / 2.f, gameHeight / 2.f));
}

void Load() {
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
	
	// update the player
	player -> Update(dt);
}

void Render(RenderWindow &window) {
	// draw all the things
	player -> Render(window);
}

int main() {
	RenderWindow window(VideoMode(gameWidth, gameHeight), "Completely Normal Maze Game");
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}

/*
int main(){
  sf::RenderWindow window(sf::VideoMode({200, 200}), "SFML works!");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen()){
      sf::Event event;
      while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed){
        window.close();
      }
    }
    window.clear();
    window.draw(shape);
    window.display();
  }
  return 0;
}
*/