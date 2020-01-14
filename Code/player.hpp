#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class player: public drawable {
public:
    sf::RectangleShape square;
    sf::FloatRect hitbox;

    player( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f(size) );
    
    void draw( sf::RenderWindow & window ) override;

	void move( sf::Vector2f delta );

    void update();


private:
	sf::Vector2f position;
	sf::Vector2f size;
};

#endif
