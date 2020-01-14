#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include "player.hpp"
#include "wall.hpp"

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
	wall test { window, sf::Vector2f( 5, 50 ), sf::Vector2f( 60 , 110) };

	action actions[] = {
        action( sf::Keyboard::Left,  [&](){ square.move( sf::Vector2f( -3.0,  0.0 )); }),
		action( sf::Keyboard::Right, [&](){ square.move( sf::Vector2f( +3.0,  0.0 )); })

	};

    const float maxY = 40;
        const sf::Vector2f gravity(0.0, 1.f);
        sf::Vector2f velocity(0.0, -15.f);
    bool jump = false;
    
	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}
        sf::FloatRect hitbox = square.hitbox;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            jump = true;
            if (hitbox.intersects(wall_bottom.hitbox)){
                velocity.y=-15.f;
            }
            sf::sleep (sf::milliseconds(8));
            square.move(velocity);
            if(velocity.y < maxY) velocity += gravity;
        }
        
        if (hitbox.intersects(wall_bottom.hitbox)==false && jump == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)==false){
             square.move(velocity);
            if(velocity.y < maxY) velocity += gravity;
            sf::sleep (sf::milliseconds(8));
        }
        if (hitbox.intersects(wall_bottom.hitbox) && jump == true){
            jump = false;
            velocity.y=-15.f;
        }

		window.clear();
        square.draw( window );
        wall_bottom.draw( window );
        test.draw(window);
        
        square.update( wall_bottom );
        wall_bottom.update();
		test.update();
        
		window.display();

		sf::sleep( sf::milliseconds( 10 ));

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
