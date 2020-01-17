#include <SFML/Graphics.hpp>
#include "rectangle.hpp"
#include <iostream>

rectangle::rectangle( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size ) :
    drawable(window), position(position), size(size){}

void rectangle::draw( sf::RenderWindow & window ){
    rect.setSize(sf::Vector2f(size));
    rect.setPosition(position);
//    rect.setFillColor(sf::Color( 0, 200, 0));
    window.draw(rect);
}
void rectangle::update( ){
    hitbox = rect.getGlobalBounds();
}