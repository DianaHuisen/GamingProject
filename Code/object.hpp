#ifndef _OBJECT_HPP
#define _OBJECT_HPP

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "drawable.hpp"

/// @file

/// Brief, this class is to create the objects
/*
    The object needs the following parameters: the window, a starting position using the Vector2f method, an offset of it's size and a type.
    The class also implements all necessary functions to interact with the player. 
*/
class object: public drawable {
public:
    bool pickedUp;
    sf::RectangleShape rect;
    
    object( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, int type = 0 );
    
    /// Brief, this function sets the object up to be drawn in the window    
    /*
        Draw enables the window to draw the object. It also checks the type of object and sets the correct sprite.
        Needs to be used between a window.clear() and a window.display() in conjunction with a object.update()
    */
    void draw( sf::RenderWindow & window ) override;
    
    /// Brief, this enables the player to interact with an object
    /*
        An interaction is needed for the object in order to react to the player. It requires the player to be given as a parameter.
        It checks when "E" is pressed whether it intersects with the player and reacts accordingly. 
    */
    void interact( player acacia );
    
    /// Brief, this enables text to apear when interacting
    /*
        During an interaction, the object will show text to descripe the kind of interaction the player has with it.
        It requires the player to be given as a parameter.
    */
    void text( player acacia );

private:
	sf::Vector2f position;
	sf::Vector2f size;
    int type;
//    type 0 = undefined
//    type 1 = berry
//    type 2 = key
//    type 3 = mushroom
//    type 4 = gate
};

#endif