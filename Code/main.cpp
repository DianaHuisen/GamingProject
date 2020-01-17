#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include "player.hpp"
#include "floor.hpp"
#include "platform.hpp" 

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
    player acacia { window, sf::Vector2f{ 400.0 , 40.0 }, sf::Vector2f( 40 , 40) };
    floor Floor { window, sf::Vector2f( 0, 360 ), sf::Vector2f( 640 , 20) };
    floor test { window, sf::Vector2f( 540, 320 ), sf::Vector2f( 640 , 20) };
	platform One{ window, sf::Vector2f( 5, 280 ), sf::Vector2f( 80 , 20) };
//	wall object {window, sf::Vector2f(100, 320), sf::Vector2f(20,20)};

    //2 lines below create the view window
//    sf::View view;
//    view.setSize(sf::Vector2f(400.f, 300.f));

	action actions[] = {
        action( sf::Keyboard::Left,  [&](){ acacia.move( sf::Vector2f( -3.0,  0.0 )); }),
		action( sf::Keyboard::Right, [&](){ acacia.move( sf::Vector2f( +3.0,  0.0 )); }),
        action( sf::Keyboard::Up,    [&](){ acacia.jump( ); }),
//		action( sf::Keyboard::E,	 [&](){ acacia.interact(object); })

	};
    
	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}
        //these 2 lines connect the view window to the player position
//        view.setCenter( acacia.position.x, acacia.position.y);
//        window.setView(view);
//        
		window.clear();
        acacia.draw( window );
        Floor.draw( window );
        test.draw( window );
        One.draw(window);
//		object.draw(window);
        
        acacia.update( );
        
		One.update(acacia);
        test.update( acacia );
        Floor.update( acacia );
//		object.update(acacia);
        
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
