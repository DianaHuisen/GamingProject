#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "wall.hpp"
#include "drawable.hpp"

class player: public drawable {
public:
    sf::RectangleShape acacia;
//    sf::FloatRect hitbox;
    sf::Vector2f position;
    player( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f(size) );
    
    void draw( sf::RenderWindow & window ) override;

	void move( sf::Vector2f delta );
    
    void jump( wall floor );

    void update( wall wall_bottom, wall test);


private:
    bool jumping;
    float maxY;
    sf::Vector2f velocity;
	sf::Vector2f size;
    sf::Vector2f bouncy;
};

#endif
