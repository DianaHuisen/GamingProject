#include <SFML/Graphics.hpp>
#include "player.hpp"

player::player( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size ) :
    drawable(window), position(position), size(size){
        bouncy = sf::Vector2f( 0.0, 2.0 );
        }

void player::draw( sf::RenderWindow & window ) {
    square.setSize(sf::Vector2f(size));
	square.setPosition(position);
	window.draw(square);
}

void player::move( sf::Vector2f delta ){
	position += delta;
}


void player::update( wall wall_bottom ){
    move(bouncy);
    hitbox = square.getGlobalBounds();
    if (hitbox.intersects(wall_bottom.hitbox)){
        bouncy.y = 0;
        move(sf::Vector2f( 0.0, -2.0 ));
        square.setFillColor(sf::Color::Red);
    }
}
