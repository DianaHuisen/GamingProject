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
    acacia.setFillColor(sf::Color(0, 0, 0, 0));
	window.draw(acacia);
    
    sf::Texture texture;

    texture.loadFromFile("SpriteSheetAcaciaMediumSmall.png");
    sf::IntRect rectSourceSprite(204, 153, 68, 153);
    sf::Sprite sprite(texture,rectSourceSprite);
    sprite.setScale(sf::Vector2f(0.45f, 0.45f));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        counter+=1;
        sf::IntRect rectSourceSprite(0, 0, 68, 153);
        if (counter < 50 && counter >= 45){
            rectSourceSprite.left = 136;
            rectSourceSprite.top=153;
            if (counter == 49){
                counter=0;
            }
        }
        if (counter < 45 && counter >= 40){
            rectSourceSprite.left = 68;
            rectSourceSprite.top=153;
        }
        if (counter < 40 && counter >= 35){
            rectSourceSprite.left=0;
            rectSourceSprite.top=153;
        }
        if (counter < 35 && counter >= 30){
            rectSourceSprite.left = 408;
        }
        if (counter < 30 && counter >= 25){
            rectSourceSprite.left = 340;
        }
        if (counter < 25 && counter >= 20){
            rectSourceSprite.left = 272;
        }
        if (counter < 20 && counter >= 15){
            rectSourceSprite.left = 204;
        }
        if (counter < 15 && counter >= 10){
            rectSourceSprite.left = 136;
        }
        if (counter < 10 && counter >= 5){
            rectSourceSprite.left = 68;
        }
        if (counter <5 && counter >= 0){
            rectSourceSprite.left =0;
            rectSourceSprite.top=0;
        }
      sprite.setTextureRect(rectSourceSprite);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        counter+=1;
        sf::IntRect rectSourceSprite(0, 0, 68, 153);
        if (counter < 50 && counter >= 45){
            rectSourceSprite.left = 408;
            rectSourceSprite.top = 306;
            if (counter == 49){
                counter=0;
            }
        }
        if (counter < 45 && counter >= 40){
            rectSourceSprite.left = 340;
            rectSourceSprite.top = 306;
        }
        if (counter < 40 && counter >= 35){
            rectSourceSprite.left=272;
            rectSourceSprite.top = 306;
        }
        if (counter < 35 && counter >= 30){
            rectSourceSprite.left = 204;
            rectSourceSprite.top = 306;
        }
        if (counter < 30 && counter >= 25){
            rectSourceSprite.left = 136;
            rectSourceSprite.top = 306;
        }
        if (counter < 25 && counter >= 20){
            rectSourceSprite.left = 68;
            rectSourceSprite.top = 306;
        }
        if (counter < 20 && counter >= 15){
            rectSourceSprite.left = 0;
            rectSourceSprite.top = 306;
        }
        if (counter < 15 && counter >= 10){
            rectSourceSprite.left = 408;
            rectSourceSprite.top = 153;
        }
        if (counter < 10 && counter >= 5){
            rectSourceSprite.left = 340;
            rectSourceSprite.top = 153;
        }
        if (counter <5 && counter >= 0){
            rectSourceSprite.left =272;
            rectSourceSprite.top = 153;
        }
      sprite.setTextureRect(rectSourceSprite);
    }
    else{
         sprite.setTextureRect(rectSourceSprite);
    }
    sprite.move(sf::Vector2f(position.x,position.y));
    window.draw(sprite);  
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

