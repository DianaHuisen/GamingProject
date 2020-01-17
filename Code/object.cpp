#include <SFML/Graphics.hpp>
#include "floor.hpp"
#include <iostream>

wall::wall( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size ) :
    drawable(window), position(position), size(size){}

void wall::draw( sf::RenderWindow & window ){
    rectangle.setSize(sf::Vector2f(size));
    rectangle.setPosition(position);
    rectangle.setFillColor(sf::Color( 0, 200, 0));
    window.draw(rectangle);
}
void wall::update( player acacia ){
    hitbox = rectangle.getGlobalBounds();
}