#ifndef _DRAWABLE_HPP
#define _DRAWABLE_HPP

class drawable {
protected:
   sf::RenderWindow & window;
   
public:
    drawable( sf::RenderWindow & window):
      window( window ){}      
   
   virtual void draw( sf::RenderWindow & window ) = 0;
};


#endif