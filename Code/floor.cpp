#include "floor.hpp"

floor::floor( sf::RenderWindow & window, sf::Vector2f Position, sf::Vector2f Size ) :
    rectangle(window){
        rect.setFillColor(sf::Color(110, 60, 30));
        position = Position;
        size = Size;
    }

void floor::draw( sf::RenderWindow & window ){
    rect.setSize(sf::Vector2f(size));
    rect.setPosition(position);
    window.draw(rect);
}

void floor::update( player & acacia ){
    hitbox = rect.getGlobalBounds();
    hitboxBigger = rect.getGlobalBounds();
    hitboxBigger.top = hitboxBigger.top - 2 ;

    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if(acacia.velocity.y < acacia.maxY){
            acacia.velocity += acacia.gravity;
        }
        if(acacia.jumping){
            acacia.jumping = false;
        }
        if(hitboxBigger.intersects(acacia.hitbox)){
            acacia.jumping = false;
            acacia.velocity.y = 0.0;
            acacia.position.y = hitbox.top - acacia.size.y;
        }
    }

    if((hitbox.intersects(acacia.hitbox)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if(acacia.velocity.y < acacia.maxY){
            acacia.velocity += acacia.gravity;
        }
        if(acacia.jumping){
            acacia.jumping = false;
            acacia.velocity.y = -19.0;
        }
        else{
            acacia.velocity.y = 0.0;
        }
    }
}


