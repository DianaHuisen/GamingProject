#ifndef _OBJECT_HPP
#define _OBJECT_HPP

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "drawable.hpp"


class object: public drawable {
public:
    bool pickedUp;
    sf::RectangleShape rectangle;
    
    object( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f(size), int type=0 );
    
    void draw( sf::RenderWindow & window ) override;
    void update( player acacia );
    void interact(player acacia);
    void text(player acacia);

private:
	sf::Vector2f position;
	sf::Vector2f size;
    int type;
};

#endif