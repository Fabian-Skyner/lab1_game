#include <SFML/Graphics.hpp>
#include <iostream>
#include "lib_ecm/ecm.h"
#include "cmp_sprite.h"

// TODO: fix CMakeLists to include ecm and cmp_sprite, continue from "Shape Component" in Pacman lab 2

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