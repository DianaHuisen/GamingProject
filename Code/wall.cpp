#include "wall.hpp"
#include <iostream>

wall::wall( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, bool sidewall ) :
    rectangle(window, position, size), position(position), size(size), sidewall(sidewall){}

void wall::draw( sf::RenderWindow & window ){
    rect.setSize(sf::Vector2f(size));
    rect.setPosition(position);
    window.draw(rect);
    
    if (!sidewall){
        rect.setFillColor(sf::Color( 0, 0, 0, 0));
        sf::Texture texture;
        texture.loadFromFile("sprites/wallPlantTall.png");
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0,0,size.x,size.y));
        sprite.move(sf::Vector2f(position.x,position.y));
        window.draw(sprite);
    }else{
        rect.setFillColor(sf::Color( 110, 60, 30));
    }
}

void wall::update( player & acacia ){
    hitbox = rect.getGlobalBounds();
    
    if (hitbox.intersects(acacia.hitbox)){
        if (acacia.left){
            acacia.move(sf::Vector2f(10.0, 0.0));
        }else{
            acacia.move(sf::Vector2f(-10.0, 0.0));
        }
    }
}
