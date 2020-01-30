#ifndef _RECTANGLE_HPP
#define _RECTANGLE_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

/// @file

/// Brief, this class is to help create rectangle shapes
/*
    The class sets up the variables needed to draw a rectangle: 
    the cooridinate of the top corner(position), the size and a bigger hitbox for jumping.
*/
class rectangle: public drawable {
public:
    sf::RectangleShape rect;
    
    rectangle( sf::RenderWindow & window ):
        drawable( window ){}

protected:
    sf::FloatRect hitboxBigger;
	sf::Vector2f position;
	sf::Vector2f size;
};

#endif