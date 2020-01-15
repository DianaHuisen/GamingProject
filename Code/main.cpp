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
    player acacia { window, sf::Vector2f{ 400.0 , 260.0 }, sf::Vector2f( 40 , 40) };
    wall floor { window, sf::Vector2f( 0, 360 ), sf::Vector2f( 640 , 20) };
	wall platform { window, sf::Vector2f( 5, 280 ), sf::Vector2f( 80 , 20) };
	wall object {window, sf::Vector2f(100, 320), sf::Vector2f(20,20)};

    //2 lines below create the view window
    sf::View view;
    view.setSize(sf::Vector2f(400.f, 300.f));

	action actions[] = {
        action( sf::Keyboard::Left,  [&](){ acacia.move( sf::Vector2f( -3.0,  0.0 )); }),
		action( sf::Keyboard::Right, [&](){ acacia.move( sf::Vector2f( +3.0,  0.0 )); }),
        action( sf::Keyboard::Up,    [&](){ acacia.jump( floor); }),
		action( sf::Keyboard::E,	 [&](){ acacia.interact(object); })

	};
    
	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}
        //these 2 lines connect the view window to the player position
        view.setCenter( acacia.position.x, acacia.position.y);
        window.setView(view);
        
		window.clear();
        acacia.draw( window );
        floor.draw( window );
        platform.draw(window);
		object.draw(window);
        
        acacia.update( floor , platform);
        floor.update();
		platform.update();
		object.update();
        
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
