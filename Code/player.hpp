#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class player: public drawable {
public:
    sf::RectangleShape acacia;
    sf::Vector2f position;
    bool jumping;
    bool left;
    float maxY;
    sf::Vector2f velocity;
	sf::Vector2f size;

    player( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f(size) );
    
    void draw( sf::RenderWindow & window ) override;

	void move( sf::Vector2f delta );
  
    void jump( );

    void update();
    
private:
    int animCount=0;
};

#endif
