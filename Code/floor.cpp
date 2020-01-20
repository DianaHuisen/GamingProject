#include <SFML/Graphics.hpp>
#include "floor.hpp"
#include <iostream>

floor::floor( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size ) :
    rectangle(window, position, size), position(position), size(size){rect.setFillColor(sf::Color( 0, 200, 0));}

void floor::draw( sf::RenderWindow & window ){
    rect.setSize(sf::Vector2f(size));
    rect.setPosition(position);
    rect.setFillColor(sf::Color( 0, 200, 0));
    window.draw(rect);
}
void floor::update( player & acacia ){

    hitbox = rect.getGlobalBounds();
    if (hitbox.intersects(acacia.hitbox)){
        acacia.velocity.y=0.0;
    }
    
    if (hitbox.intersects(acacia.hitbox)==false && acacia.jumping == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)==false){
        if(acacia.velocity.y < acacia.maxY){
            acacia.velocity += acacia.gravity;
        }
        sf::sleep (sf::milliseconds(8));
//        if (hitbox.intersects(platform.hitbox)){
//            jumping = false;
//            velocity.y=0;
//        }
        acacia.bouncy=acacia.velocity;
    }
    
    if (hitbox.intersects(acacia.hitbox)){
        acacia.onGround=true;
        acacia.acacia.setFillColor(sf::Color::Green);
        acacia.velocity.y = 0.0;
        acacia.move(sf::Vector2f( 0.0, -2.0 ));
        if (acacia.jumping){
            acacia.jumping = false;
            acacia.velocity.y=-15.0;
        }
    }else{
        acacia.onGround=false;
        acacia.acacia.setFillColor(sf::Color::Red);
    }
//    if (hitbox.intersects(platform.hitbox)){
//        bouncy.y = 1;
//        acacia.setFillColor(sf::Color::Blue);
//        move(sf::Vector2f( 0.0, -2.0 ));
//        if (jumping){
//            jumping = false;
//            velocity.y=-15.f;
//        }
//    }
    
}


