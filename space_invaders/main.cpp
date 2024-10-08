#include <SFML/Graphics.hpp>
#include <iostream>
#include "ship.h"
#include "game.h"
using namespace sf;
using namespace std;

sf::Texture spritesheet;
//sf::Sprite invader;
std::vector<Ship *> ships;

void Load() {
	if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
		cerr << "Failed to load sprites." << std::endl;
	}
	//invader.setTexture(spritesheet);
	//invader.setTextureRect( IntRect( Vector2i(0, 0), Vector2i(32, 32) ) );
	
	Invader* inv = new Invader(sf::IntRect( Vector2i(0, 0), Vector2i(32, 32) ), {100, 100});
	ships.push_back(inv);
}

void Update() {
	// reset clock, recalculate deltatime
	static Clock clock;
	float dt = clock.restart().asSeconds();

	for (auto &s : ships) {
		s->Update(dt);
	};
}

void Render(RenderWindow &window) {
	//window.draw(invader);
	for (const auto &s : ships) {
		window.draw(*s);
	};
}

int main() {
	RenderWindow window(VideoMode(gameWidth, gameHeight), "Space Invaders");
	Load();
	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed){
				window.close();
			}
		}
		window.clear();
		Update();
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