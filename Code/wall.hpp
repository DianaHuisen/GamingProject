#ifndef _WALL_HPP
#define _WALL_HPP

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "rectangle.hpp"

/// @file

/// Brief, this class is to create walls
/* 
    To use this class the variable needs to be given a window and the X and Y coordinate using the Vector2f method. 
    Lastly it needs the size using the Vector2f method, this is an offset of the first coordinate, not an end coordinate.
*/
class wall: public rectangle {
public:
    
    wall( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, bool treeTrunk=false);
    
    /// Brief, draw function sets up the wall for the window
    /* 
        Every wall needs to be drawn first to be visible, this requires a wall.draw(window) to be put in between
        a window.clear() and a window.display() 
        The draw function also sets the wall's texture
    */
    void draw( sf::RenderWindow & window ) override;

    /// Brief, the update function checks for intersects
    /*
        An update is needed for every wall that needs to interact with the player. It requires the player to be given as a parameter.
        It checks whether it intersects with the player and reacts accordingly. 
        This needs to be put in between a window.clear() and a window.display, after the wall.draw(window)
    */
    void update( player & acacia );

private:
    bool treeTrunk;
};

#endif