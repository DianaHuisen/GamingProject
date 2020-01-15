#ifndef _WALL_HPP
#define _WALL_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class wall: public drawable {
public:
    sf::RectangleShape rectangle;
//    sf::FloatRect hitbox;
    
    wall( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f(size) );
    
    void draw( sf::RenderWindow & window ) override;
    void update();

private:
	sf::Vector2f position;
	sf::Vector2f size;
};

#endif