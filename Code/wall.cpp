#include "wall.hpp"
#include <iostream>

wall::wall( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size ) :
    rectangle(window, position, size), position(position), size(size){rect.setFillColor(sf::Color( 200, 0, 0 ));}

void wall::draw( sf::RenderWindow & window ){
    rect.setSize(sf::Vector2f(size));
    rect.setPosition(position);
    window.draw(rect);
}

void wall::update( player & acacia ){
    hitbox = rect.getGlobalBounds();
    
    if (hitbox.intersects(acacia.hitbox)){
        if (acacia.left){
            acacia.move(sf::Vector2f(10.0, 0.0));
//            rect.setFillColor(sf::Color( 0, 100, 0 ));
        }else{
            acacia.move(sf::Vector2f(-10.0, 0.0));
//            rect.setFillColor(sf::Color( 0, 0, 100 ));
        }
//        }else if (!acacia.left){
//            acacia.move(sf::Vector2f(5.0, 0.0));
//            rect.setFillColor(sf::Color( 100, 0, 0 ));
//        }
//        else{
//            rect.setFillColor(sf::Color( 0, 0, 200 ));
//        }
        
    }else{
        rect.setFillColor(sf::Color( 200, 0, 0 ));
    }

//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)==false){
//
//        if(acacia.velocity.y < acacia.maxY){
//            acacia.velocity += acacia.gravity;
//        }
//        if (acacia.jumping){
//            acacia.jumping = false;
//        }
//        if(hitbox.intersects(acacia.hitbox)){
//            acacia.jumping = false;
//            acacia.velocity.y= 0.0;
//            acacia.position.y = hitbox.top-(acacia.size.y);
//        }
//    }
//
//    if ((hitbox.intersects(acacia.hitbox)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)==true){
//        if(acacia.velocity.y < acacia.maxY){
//            acacia.velocity += acacia.gravity;
//        }
//        if (acacia.jumping){
//            acacia.jumping = false;
//             acacia.velocity.y=-19.0;
//        }
//        else{
//            acacia.velocity.y = 0.0;
//        }
//    }
}
