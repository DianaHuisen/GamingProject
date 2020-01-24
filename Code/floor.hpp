#ifndef _FLOOR_HPP
#define _FLOOR_HPP

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "rectangle.hpp"


class floor: public rectangle {
public:
    
    floor( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f(size) );
    
    void draw( sf::RenderWindow & window ) override;
    void update( player & acacia );

private:
	sf::Vector2f position;
	sf::Vector2f size;
};

#endif
