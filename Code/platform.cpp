#include "platform.hpp"
#include <iostream>

platform::platform( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size ) :
    rectangle(window, position, size), position(position), size(size){rect.setFillColor(sf::Color( 0, 200, 0));}

void platform::draw( sf::RenderWindow & window ){
    rect.setSize(sf::Vector2f(size));
    rect.setPosition(position);
    window.draw(rect);
    
    sf::Texture texture;
    texture.loadFromFile("sprites/wood-platform.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,size.x,size.y));
    sprite.move(sf::Vector2f(position.x,position.y));
    window.draw(sprite);
}

void platform::update( player & acacia ){
    
    hitbox = rect.getGlobalBounds();
    hitboxBigger = rect.getGlobalBounds();
    hitboxBigger.top = hitboxBigger.top - 2;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)==false){
//        if(acacia.velocity.y < acacia.maxY){
//            acacia.velocity += acacia.gravity;
//        }
        if (acacia.jumping){
            acacia.jumping = false;
        }
        if(hitboxBigger.intersects(acacia.hitbox)){
            acacia.jumping = false;
            acacia.velocity.y= 0.0;
            acacia.position.y = hitbox.top-(acacia.size.y);
        }
    }

    if ((hitbox.intersects(acacia.hitbox)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)==true){
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
