#ifndef _DRAWABLE_HPP
#define _DRAWABLE_HPP

/// @file

/// Brief, this class is to help create drawable objects
/*
    The class makes sure that all objects have an interactable hitbox and gravity where needed.
*/

class drawable {
protected:
   sf::RenderWindow & window;
   
public:
    sf::FloatRect hitbox;
    sf::Vector2f gravity;

    drawable( sf::RenderWindow & window ):
        window( window ){}      
   
    virtual void draw( sf::RenderWindow & window ) = 0;
};


#endif