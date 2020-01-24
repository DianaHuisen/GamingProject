#include "object.hpp"
#include <iostream>

object::object( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size ) :
    drawable(window), position(position), size(size){}

void object::draw( sf::RenderWindow & window ){
    rectangle.setSize(sf::Vector2f(size));
    rectangle.setPosition(position);
    rectangle.setFillColor(sf::Color( 0, 200, 0));
    window.draw(rectangle);
}

void object::interact(player acacia){
    hitbox = rectangle.getGlobalBounds();
    if(hitbox.intersects(acacia.hitbox)){
        text(acacia);
    }
}

void object::text(player acacia){
    sf::Font font;
    sf::Text text;
    text.setFont(font);
    if (!font.loadFromFile("aller.ttf")){
    // error...
    }
    else{
        text.setString("Grabbed item");
        text.setCharacterSize(10);
        text.setFillColor(sf::Color::Blue);
        text.setStyle(sf::Text::Bold);
        text.setPosition((acacia.position.x + 50.f), (acacia.position.y - 20.f));
        window.draw(text);
    }
}


void object::update( player acacia ){
    hitbox = rectangle.getGlobalBounds();
}