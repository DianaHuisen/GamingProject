//#include <SFML/Graphics.hpp>
#include "player.hpp"
#include <iostream>

player::player( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size ) :
    drawable(window), position(position), size(size){
        bouncy = sf::Vector2f( 0.0, 2.5 );
        jumping=false;
        firstJump=true;
        maxY = 40;
        gravity = sf::Vector2f (0.0, 1.0);
        velocity = sf::Vector2f (0.0, 2.5);
        }

void player::draw( sf::RenderWindow & window ) {
    acacia.setSize(sf::Vector2f(size));
	acacia.setPosition(position);
	window.draw(acacia);
}

void player::move( sf::Vector2f delta ){
	position += delta;
}

void player::jump( ){
    hitbox = acacia.getGlobalBounds();
    jumping = true;

    if(velocity.y < maxY) {
        velocity += gravity;
    }
}

void player::update(){
    hitbox = acacia.getGlobalBounds();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        firstJump=false;
    }else{
        firstJump=true;
    }
    move(velocity);
}

