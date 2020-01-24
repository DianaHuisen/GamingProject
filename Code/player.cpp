#include "player.hpp"
#include <iostream>

player::player( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size ) :
    drawable(window), position(position), size(size){
        acacia.setFillColor(sf::Color(0, 0, 0, 0));
        jumping=false;
        maxY = 40;
        gravity = sf::Vector2f (0.0, 1.0);
        velocity = sf::Vector2f (0.0, 2.5);
    }

void player::draw( sf::RenderWindow & window ) {
    acacia.setSize(sf::Vector2f(size));
	acacia.setPosition(position);
	window.draw(acacia);
    
    sf::Texture texture;
    texture.loadFromFile("SpriteSheetAcaciaMediumSmall.png");
    sf::IntRect rectSourceSprite(204, 153, 68, 153);
    sf::Sprite sprite(texture,rectSourceSprite);
    sprite.setScale(sf::Vector2f(0.45f, 0.45f));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        animCount+=1;
        sf::IntRect rectSourceSprite(0, 0, 68, 153);
        if (animCount < 30 && animCount >= 27){
            rectSourceSprite.left = 136;
            rectSourceSprite.top=153;
            if (animCount == 29){
                animCount=0;
            }
        }
        if (animCount < 27 && animCount >= 24){
            rectSourceSprite.left = 68;
            rectSourceSprite.top=153;
        }
        if (animCount < 24 && animCount >= 21){
            rectSourceSprite.left=0;
            rectSourceSprite.top=153;
        }
        if (animCount < 21 && animCount >= 18){
            rectSourceSprite.left = 408;
        }
        if (animCount < 18 && animCount >= 15){
            rectSourceSprite.left = 340;
        }
        if (animCount < 15 && animCount >= 12){
            rectSourceSprite.left = 272;
        }
        if (animCount < 12 && animCount >= 9){
            rectSourceSprite.left = 204;
        }
        if (animCount < 9 && animCount >= 6){
            rectSourceSprite.left = 136;
        }
        if (animCount < 6 && animCount >= 3){
            rectSourceSprite.left = 68;
        }
        if (animCount <3 && animCount >= 0){
            rectSourceSprite.left =0;
            rectSourceSprite.top=0;
        }
      sprite.setTextureRect(rectSourceSprite);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        animCount+=1;
        sf::IntRect rectSourceSprite(0, 0, 68, 153);
        if (animCount < 30 && animCount >= 27){
            rectSourceSprite.left = 408;
            rectSourceSprite.top = 306;
            if (animCount == 29){
                animCount=0;
            }
        }
        if (animCount < 27 && animCount >= 24){
            rectSourceSprite.left = 340;
            rectSourceSprite.top = 306;
        }
        if (animCount < 24 && animCount >= 21){
            rectSourceSprite.left=272;
            rectSourceSprite.top = 306;
        }
        if (animCount < 21 && animCount >= 18){
            rectSourceSprite.left = 204;
            rectSourceSprite.top = 306;
        }
        if (animCount < 18 && animCount >= 15){
            rectSourceSprite.left = 136;
            rectSourceSprite.top = 306;
        }
        if (animCount < 15 && animCount >= 12){
            rectSourceSprite.left = 68;
            rectSourceSprite.top = 306;
        }
        if (animCount < 12 && animCount >= 9){
            rectSourceSprite.left = 0;
            rectSourceSprite.top = 306;
        }
        if (animCount < 9 && animCount >= 6){
            rectSourceSprite.left = 408;
            rectSourceSprite.top = 153;
        }
        if (animCount < 6 && animCount >= 3){
            rectSourceSprite.left = 340;
            rectSourceSprite.top = 153;
        }
        if (animCount <3 && animCount >= 0){
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
    move(velocity);
}

