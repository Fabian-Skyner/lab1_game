#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

sf::Texture spritesheet;
sf::Sprite invader;

void Load() {
	if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
		cerr << "Failed to load sprites." << std::endl;
	}
	invader.setTexture(spritesheet);
	invader.setTextureRect( IntRect( Vector2i(0, 0), Vector2i(32, 32) ) );
}

void Render(RenderWindow &window) {
	window.draw(invader);
}

int main() {
	RenderWindow window(VideoMode(100, 100), "AAAAAAAAAAAAAAAAAAAAAA");
	Load();
	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed){
				window.close();
			}
		}
	}
	Render(window);
	window.display();
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