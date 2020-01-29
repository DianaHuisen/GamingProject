#include "object.hpp"
#include <iostream>

object::object( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, int type ) :
    drawable(window), position(position), size(size), type(type){pickedUp=false;}

void object::draw( sf::RenderWindow & window ){
    rectangle.setSize(sf::Vector2f(size));
    rectangle.setPosition(position);
//    rectangle.setFillColor(sf::Color( 0, 200, 200));
    window.draw(rectangle);
    
    sf::Texture texture;
    sf::Sprite sprite;
    
    if (type==1 and !pickedUp){
        texture.loadFromFile("sprites/berry-small.png");
    }else if(type==2 and !pickedUp){
        texture.loadFromFile("sprites/keySmall.png");
    }else if(type==3){
        if (pickedUp){
            texture.loadFromFile("sprites/shroomDownSmall.png");
        }else{
            texture.loadFromFile("sprites/shroomSmall.png");
        }
    }else if(type==4){
        texture.loadFromFile("sprites/gateSmalll.png");
    }else{
        texture.loadFromFile("sprites/empty.png");
    }
    rectangle.setFillColor(sf::Color( 0, 0, 0, 0));
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,size.x,size.y));
    sprite.move(sf::Vector2f(position.x,position.y));
    window.draw(sprite);
}

void object::interact(player acacia){
    hitbox = rectangle.getGlobalBounds();
    if(hitbox.intersects(acacia.hitbox) and !pickedUp){
        text(acacia);
        pickedUp=true;
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
//        for(int i=0;i<10;i++){
        if (type<3){
        text.setString("Grabbed item");
        }else if(type==3){
            text.setString("Pressed mushroom");
        }else if(type==4){
            text.setString("Opened Gate");
        }
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::White);
        text.setStyle(sf::Text::Bold);
        text.setPosition((acacia.position.x + 50.f), (acacia.position.y - 20.f));
        window.draw(text);
        window.display();
        sf::sleep(sf::milliseconds(1000));
        
//        }
    }
}


void object::update( player acacia ){
    hitbox = rectangle.getGlobalBounds();
}