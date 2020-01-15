#include <SFML/Graphics.hpp>
#include "player.hpp"

player::player( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size ) :
    drawable(window), position(position), size(size){
        bouncy = sf::Vector2f( 0.0, 2.5 );
        }

void player::draw( sf::RenderWindow & window ) {
    acacia.setSize(sf::Vector2f(size));
	acacia.setPosition(position);
	window.draw(acacia);
}

void player::move( sf::Vector2f delta ){
	position += delta;
}


void player::update( wall floor , wall platform){
    move(bouncy);
    hitbox = acacia.getGlobalBounds();
    if (hitbox.intersects(floor.hitbox)){
        bouncy.y = 0;
        move(sf::Vector2f( 0.0, -2.0 ));
        acacia.setFillColor(sf::Color::Red);
    }
    if (hitbox.intersects(platform.hitbox)){
        bouncy.y = 1;
        move(sf::Vector2f( 0.0, -2.0 ));
        acacia.setFillColor(sf::Color::Red);
    }
}
