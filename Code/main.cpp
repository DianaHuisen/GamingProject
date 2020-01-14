#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include "player.hpp"


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

	action actions[] = {
        action( sf::Keyboard::Left,  [&](){ square.move( sf::Vector2f( -3.0,  0.0 )); }),
		action( sf::Keyboard::Right, [&](){ square.move( sf::Vector2f( +3.0,  0.0 )); })

	};

	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}

		window.clear();
        square.draw( window );
       
        square.update();

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
