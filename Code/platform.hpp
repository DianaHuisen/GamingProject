#ifndef _PLATFORM_HPP
#define _PLATFORM_HPP

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "rectangle.hpp"

/// @file

/// Brief, this class is to create platforms
/* 
    To use this class the variable needs to be given a window and the X and Y coordinate using the Vector2f method. 
    Lastly it needs the size using the Vector2f method, this is an offset of the first coordinate, not an end coordinate.
*/
class platform: public rectangle {
public:
    
    platform( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size );

    /// Brief, the draw function sets up the platform for the window
    /* 
        Every platform needs to be drawn first to be visible, this requires a platform.draw(window) to be put in between
        a window.clear() and a window.display() 
        It also gives the texture to the window. 
    */
    void draw( sf::RenderWindow & window ) override;

    /// Brief, the update function checks for intersects
    /*
        An update is needed for every platform that needs to interact with the player. It requires the player to be given as a parameter.
        It checks whether it intersects with the player and reacts accordingly. 
        This needs to be put in between a window.clear() and a window.display, after the platform.draw(window)
    */
    void update( player & acacia );

private:
	sf::Vector2f position;
	sf::Vector2f size;
};

#endif