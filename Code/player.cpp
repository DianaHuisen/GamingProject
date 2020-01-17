#include <SFML/Graphics.hpp>
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
//        velocity = sf::Vector2f (0.0, -15.0);
        }

void player::draw( sf::RenderWindow & window ) {
    acacia.setSize(sf::Vector2f(size));
	acacia.setPosition(position);
	window.draw(acacia);
}

void player::move( sf::Vector2f delta ){
	position += delta;
}

//void player::interact(wall object){
//    hitbox = acacia.getGlobalBounds();
//    if(hitbox.intersects(object.hitbox)){
//        std::cout << "Poke\n";
//        sf::sleep (sf::milliseconds(15));
//    }
//}
//
void player::jump( ){
    hitbox = acacia.getGlobalBounds();
//    if (firstJump){
//        acacia.setFillColor(sf::Color::Cyan);
        jumping = true;
//        firstJump=false;
     
//    acacia.setFillColor(sf::Color::Blue);
//    if (hitbox.intersects(floor.hitbox)){
//        velocity.y=-5;
//    }
//    sf::sleep (sf::milliseconds(8));
//    move(velocity);
    if(velocity.y < maxY) {
        velocity += gravity;
//        acacia.setFillColor(sf::Color::Cyan);
    }
//    }
}

void player::update(){
    hitbox = acacia.getGlobalBounds();
//    move(bouncy);
    move(velocity);
//    if(jumping){
//        acacia.setFillColor(sf::Color::Cyan);
//    }else{
//        acacia.setFillColor(sf::Color::Green);
//    }
//    if(velocity.y>0){
//        acacia.setFillColor(sf::Color::Cyan);
//    }else if (velocity.y==0){
//        acacia.setFillColor(sf::Color::Green);
//    }else{
//        acacia.setFillColor(sf::Color::Yellow);
//    }
}
//
//void player::update( wall floor , wall platform){
//    hitbox = acacia.getGlobalBounds();
//    
//    if (hitbox.intersects(floor.hitbox)==false && jumping == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)==false){
//        if(velocity.y < maxY){
//            velocity += gravity;
//        }
//        sf::sleep (sf::milliseconds(8));
////        if (hitbox.intersects(platform.hitbox)){
////            jumping = false;
////            velocity.y=0;
////        }
//        bouncy=velocity;
//    }
//    
//    if (hitbox.intersects(floor.hitbox)){
//        bouncy.y = 0;
//        move(sf::Vector2f( 0.0, -2.0 ));
//        if (jumping){
//            jumping = false;
//            velocity.y=-15.f;
//        }
//    }
//    if (hitbox.intersects(platform.hitbox)){
//        bouncy.y = 1;
//        acacia.setFillColor(sf::Color::Blue);
//        move(sf::Vector2f( 0.0, -2.0 ));
//        if (jumping){
//            jumping = false;
//            velocity.y=-15.f;
//        }
//    }
//
//    
//    move(bouncy);
//}
