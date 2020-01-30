#include "platform.hpp"

platform::platform( sf::RenderWindow & window, sf::Vector2f Position, sf::Vector2f Size ) :
    rectangle(window){
        position = Position;
        size = Size;
    }

void platform::draw( sf::RenderWindow & window ){
    rect.setSize(sf::Vector2f(size));
    rect.setPosition(position);
    
    sf::Texture texture;
    texture.loadFromFile("assets/wood-platform.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
    sprite.move(sf::Vector2f(position.x, position.y));
    window.draw(sprite);
}

void platform::update( player & acacia ){
    
    hitbox = rect.getGlobalBounds();
    hitboxBigger = rect.getGlobalBounds();
    hitboxBigger.top = hitboxBigger.top - 2;
    
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if(acacia.jumping){
            acacia.jumping = false;
        }
        if(hitboxBigger.intersects(acacia.hitbox)){
            acacia.jumping = false;
            acacia.velocity.y = 0.0;
            acacia.position.y = hitbox.top - acacia.size.y;
        }
    }

    if((hitbox.intersects(acacia.hitbox)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if(acacia.velocity.y < acacia.maxY){
            acacia.velocity += acacia.gravity;
        }
        if(acacia.jumping){
            acacia.jumping = false;
            acacia.velocity.y = -19.0;
        }
        else{
            acacia.velocity.y = 0.0;
        }
    }
}
