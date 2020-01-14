#include <SFML/Graphics.hpp>
#include "player.hpp"

player::player( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size ) :
    drawable(window), position(position), size(size){}

void player::draw( sf::RenderWindow & window ) {
    square.setSize(sf::Vector2f(size));
	square.setPosition(position);
	window.draw(square);
}

void player::move( sf::Vector2f delta ){
	position += delta;
}


void player::update(){
    hitbox = square.getGlobalBounds();
}
