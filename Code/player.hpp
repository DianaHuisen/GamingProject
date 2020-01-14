#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "wall.hpp"
#include "drawable.hpp"

class player: public drawable {
public:
    sf::RectangleShape square;
    sf::FloatRect hitbox;
    sf::Vector2f position;
    player( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f(size) );
    
    void draw( sf::RenderWindow & window ) override;

	void move( sf::Vector2f delta );

    void update( wall wall_bottom);


private:

	sf::Vector2f size;
    sf::Vector2f bouncy;
};

#endif
