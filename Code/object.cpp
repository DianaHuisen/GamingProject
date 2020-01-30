#include "object.hpp"

object::object( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, int type ) :
    drawable(window), position(position), size(size), type(type){pickedUp = false;}

void object::draw( sf::RenderWindow & window ){
    rect.setSize(sf::Vector2f(size));
    rect.setPosition(position);
    
    sf::Texture texture;
    sf::Sprite sprite;
    if(type == 1 && !pickedUp){
        texture.loadFromFile("assets/berry-small.png");
    }
    else if(type == 2 && !pickedUp){
        texture.loadFromFile("assets/keySmall.png");
    }
    else if(type == 3){
        if(pickedUp){
            texture.loadFromFile("assets/shroomDownSmall.png");
        }
        else{
            texture.loadFromFile("assets/shroomSmall.png");
        }
    }
    else if(type == 4){
        texture.loadFromFile("assets/gateSmalll.png");
    }
    else{
        texture.loadFromFile("assets/empty.png");
    }
    rect.setFillColor(sf::Color(0, 0, 0, 0));
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
    sprite.move(sf::Vector2f(position.x, position.y));
    window.draw(sprite);
}

void object::interact( player acacia ){
    hitbox = rect.getGlobalBounds();
    if(hitbox.intersects(acacia.hitbox) && !pickedUp){
        text(acacia);
        pickedUp = true;
    }
}

void object::text( player acacia ){
    sf::Font font;
    sf::Text text;
    text.setFont(font);
    if(font.loadFromFile("assets/aller.ttf")){
        if(type == 1){
            text.setString("Ate berry");
        }
        else if(type == 2){
            text.setString("Grabbed key");
        }
        else if(type == 3){
            text.setString("Pressed mushroom");
        }
        else if(type == 4){
            text.setString("Opened Gate");
        }
        else{
            text.setString("Grabbed item");
        }
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::White);
        text.setStyle(sf::Text::Bold);
        text.setPosition((acacia.position.x + 50), (acacia.position.y - 20));
        window.draw(text);
        window.display();
        sf::sleep(sf::milliseconds(1000));
    }
}
