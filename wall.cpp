#include <SFML/Graphics.hpp>
#include "wall.hpp"
#include <iostream>

wall::wall( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size ) :
    drawable(window), position(position), size(size){}

void wall::draw( sf::RenderWindow & window ){
    rectangle.setSize(sf::Vector2f(size));
    rectangle.setPosition(position);
    rectangle.setFillColor(sf::Color( 0, 200, 0));
//    sf::Texture texture;
//    if (!texture.loadFromFile("brickWallTexture.jpg"))
////        if (!texture.loadFromFile("brickWallTexture.jpg",sf::IntRect(position.x,position.y,size.x,size.y)))
//        {
//            // error...
//        }
//        else{
//            sf::Sprite sprite;
//            sprite.setTexture(texture);
//            sprite.setTextureRect(sf::IntRect(position.x,position.y,size.x,size.y));
//            sprite.setPosition(position);
//            window.draw(sprite);
//        }
    window.draw(rectangle);
}
void wall::update(){
    hitbox = rectangle.getGlobalBounds();
}


