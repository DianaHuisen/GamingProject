#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

/// @file

/// Brief, this class is to create the player and it's mechanics
/*
    The player needs the following parameters: the window, a starting position using the Vector2f method, and an offset of it's size.
    The class also implements all necessary functions to move, jump and it's walking animation. 
*/
class player: public drawable {
public:
    sf::RectangleShape acacia;
    sf::Vector2f position;
    bool jumping;
    float maxY;
    sf::Vector2f velocity;
	sf::Vector2f size;

    player( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f(size) );

    /// Brief, this function sets the player up to be drawn in the window    
    /*
        Draw enables the window to draw the character. It also sets up it's complete animations.
        Needs to be used between a window.clear() and a window.display() in conjunction with a player.update()
    */
    void draw( sf::RenderWindow & window ) override;

    /// Brief, this function enables the player to move across the level
    /*
        Move enables the player to, well, move. It uses the Vector2f method as an offset compared to the player's location.
        It moves the player on the X and/or Y axis depending on the entered Vecto2f
    */
	void move( sf::Vector2f delta );
  
    /// Brief, this function enables the player to jump upwards and come back down
    /*
        Jump uses the maxY float as a maximum jump height. It also uses the velocity to implement a gravity kind of mechanic.
        It sets up the jumping bool for different functions, such as how the floor and platforms react to the player  
    */
    void jump( );

    /// Brief, this updates the player
    /*
        Needs to be put after the player is drawn using the draw function, in between a window.clear() and a window.display().
        Uses the move function to move the player to its new position.
    */
    void update();
    
private:
    int animCount=0;
};

#endif
