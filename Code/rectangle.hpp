#ifndef _RECTANGLE_HPP
#define _RECTANGLE_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"


class rectangle: public drawable {
public:
    sf::RectangleShape rect;
    
    rectangle( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f(size) );
    
    void draw( sf::RenderWindow & window ) override;
    void update( );

protected:
	sf::Vector2f position;
	sf::Vector2f size;
};

#endif