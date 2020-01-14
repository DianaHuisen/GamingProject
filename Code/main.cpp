#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include "player.hpp"
#include "wall.hpp"
//#include <Time.hpp>
//#include "stdlib.h"

class action {
private:
	std::function< bool() > condition;
	std::function< void() > work;
public:
	action(
	   std::function< bool() > condition, 
	   std::function< void() > work
	) : condition( condition ), 
		work( work ) 
	{}

	action(
		sf::Keyboard::Key key,
		std::function< void() > work
	) :
		condition(
			[ key ]()->bool { return sf::Keyboard::isKeyPressed( key ); }
		),
		work(work)
	{}

	void operator()(){
		if( condition() ){
			work();
		}
	}
};

int main( int argc, char *argv[] ){
	std::cout << "Starting application 01-05 array of actions\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
    player square { window, sf::Vector2f{ 400.0 , 260.0 }, sf::Vector2f( 40 , 40) };
    wall wall_bottom { window, sf::Vector2f( 0, 360 ), sf::Vector2f( 640 , 20) };

	action actions[] = {
        action( sf::Keyboard::Left,  [&](){ square.move( sf::Vector2f( -3.0,  0.0 )); }),
		action( sf::Keyboard::Right, [&](){ square.move( sf::Vector2f( +3.0,  0.0 )); })

	};

    const float maxY = 50;
        const sf::Vector2f gravity(0.f, 1.f);
        sf::Vector2f velocity(2.f, -30.f);

    
	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
//            jumpStop=false;
            square.move(velocity);
//            std::cout<<velocity.y<<"\n";
            if(velocity.y < maxY) velocity += gravity;
            sf::FloatRect hitbox = square.hitbox;
            if (hitbox.intersects(wall_bottom.hitbox)){
//                velocity.y=0;
//                velocity.y=-30.f;
//                square.move(sf::Vector2f(0.0,0.0));
                //square.position.y += -1;
                sf::sleep(sf::seconds(5));
//            bouncy.y = 0;
//            square.setFillColor(sf::Color::Red);
            }
        }
//        sf::FloatRect hitbox = square.hitbox;
//        if (hitbox.intersects(wall_bottom.hitbox)){
//            velocity.y=0;
////            bouncy.y = 0;
////            square.setFillColor(sf::Color::Red);
//        }
    

		window.clear();
        square.draw( window );
        wall_bottom.draw( window );
        
        
        square.update( wall_bottom );
        wall_bottom.update();
        
		window.display();

		sf::sleep( sf::milliseconds( 20 ));

        sf::Event event;		
	    while( window.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				window.close();
			}
		}	
	}

	std::cout << "Terminating application\n";
	return 0;
}
