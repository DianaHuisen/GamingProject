#ifndef _PLATFORM_HPP
#define _PLATFORM_HPP

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "rectangle.hpp"


class platform: public rectangle {
public:
    
    platform( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size );
    
    void draw( sf::RenderWindow & window ) override;
    void update( player & acacia );

private:
	sf::Vector2f position;
	sf::Vector2f size;
};

#endif