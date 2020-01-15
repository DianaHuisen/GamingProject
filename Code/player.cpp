#include <SFML/Graphics.hpp>
#include "player.hpp"

player::player( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size ) :
    drawable(window), position(position), size(size){
        bouncy = sf::Vector2f( 0.0, 2.5 );
        }

void player::draw( sf::RenderWindow & window ) {
    player.setSize(sf::Vector2f(size));
	player.setPosition(position);
	window.draw(player);
}

void player::move( sf::Vector2f delta ){
	position += delta;
}


void player::update( wall floor , wall platform){
    move(bouncy);
    hitbox = player.getGlobalBounds();
    if (hitbox.intersects(floor.hitbox)){
        bouncy.y = 0;
        move(sf::Vector2f( 0.0, -2.0 ));
        player.setFillColor(sf::Color::Red);
    }
    if (hitbox.intersects(platform.hitbox)){
        bouncy.y = 1;
        move(sf::Vector2f( 0.0, -2.0 ));
        player.setFillColor(sf::Color::Red);
    }
}
