#include <SFML/Graphics.hpp>
#include "platform.hpp"
#include <iostream>

platform::platform( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size ) :
    rectangle(window, position, size), position(position), size(size){rect.setFillColor(sf::Color( 0, 200, 0));}

void platform::draw( sf::RenderWindow & window ){
    rect.setSize(sf::Vector2f(size));
    rect.setPosition(position);
//    rect.setFillColor(sf::Color( 0, 200, 0));
    window.draw(rect);
}

bool jumping=true;

void platform::update( player & acacia ){
    hitbox = rect.getGlobalBounds();
  
    if (jumping==true && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)==false){

        if(acacia.velocity.y < acacia.maxY){
            acacia.velocity += acacia.gravity;
        }
        acacia.onPlatform = false;
        if (acacia.jumping){
            acacia.jumping = false;
        }
        if(hitbox.intersects(acacia.hitbox)){
            acacia.onPlatform=true;
            acacia.jumping = false;
            acacia.velocity.y= 0.0;
            acacia.position.y = hitbox.top-(acacia.size.y);
        }
    }
    
    if ((hitbox.intersects(acacia.hitbox)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)==true && jumping==true){
        if(acacia.velocity.y < acacia.maxY){
            acacia.velocity += acacia.gravity;
        }
        if (acacia.jumping){
            acacia.jumping = false;
             acacia.velocity.y=-19.0;
        }
        else{
            acacia.velocity.y = 0.0;
        }
    }
}
