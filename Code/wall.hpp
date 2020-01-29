#ifndef _WALL_HPP
#define _WALL_HPP

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "rectangle.hpp"


class wall: public rectangle {
public:
    
    wall( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f(size), bool sidewall=false);
    
    void draw( sf::RenderWindow & window ) override;
    void update( player & acacia );

private:
	sf::Vector2f position;
	sf::Vector2f size;
    bool sidewall;
};

#endif