#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include "player.hpp"
#include "floor.hpp"
#include "platform.hpp" 
#include "object.hpp"
#include "rectangle.hpp"

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

	sf::RenderWindow window{ sf::VideoMode{ 1280, 900 }, "SFML window" };
    player acacia { window, sf::Vector2f{ 400.0 , 40.0 }, sf::Vector2f( 30 , 68) };
    floor Floor { window, sf::Vector2f( 0, 850 ), sf::Vector2f( 2000 , 20) };
    floor test { window, sf::Vector2f( 540, 830 ), sf::Vector2f( 640 , 20) };
	platform One{ window, sf::Vector2f( 5, 700 ), sf::Vector2f( 80 , 20) };
	platform Two{ window, sf::Vector2f( 120, 550 ), sf::Vector2f( 80 , 20) };
	object item {window, sf::Vector2f(100, 320), sf::Vector2f(20,20)};


    //2 lines below create the view window
	sf::View view;
	view.setSize(sf::Vector2f(500.f, 400.f));

	action actions[] = {
        action( sf::Keyboard::Left,  [&](){ acacia.move( sf::Vector2f( -5.0,  0.0 )); }),
		action( sf::Keyboard::Right, [&](){ acacia.move( sf::Vector2f( +5.0,  0.0 )); }),
        action( sf::Keyboard::Up,    [&](){ acacia.jump( ); }),
		action( sf::Keyboard::E,	 [&](){ item.interact(acacia);})

	};
	
//	window.clear();
//
//	///Starting story
//	sf::Font font;
//    sf::Text text;
//    text.setFont(font);
//    if (!font.loadFromFile("aller.ttf")){
//   		// error...
//    }
//    else{
//		text.setString("You've fallen from the tree!\nFind your way back home by jumping\nthrough the branches and learning\nnew skills.");
//		text.setPosition(sf::Vector2f( 450.0,  100.0 ));
//        text.setCharacterSize(30);
//        text.setFillColor(sf::Color::White);
//		window.draw(text);
//	}
//
//	window.display();
//
//	sf::sleep(sf::seconds(5));
    
	while (window.isOpen()) {
		window.clear();
		
        //these 2 lines connect the view window to the player position
		view.setCenter( acacia.position.x, acacia.position.y);
		window.setView(view);
  
        acacia.draw( window );
        Floor.draw( window );
        test.draw( window );
        One.draw(window);
        Two.draw(window);
		item.draw(window);
        
		for( auto & action : actions ){
			action();
		}

        acacia.update( );
        
		One.update(acacia);
        Two.update(acacia);
        test.update( acacia );
        Floor.update( acacia );
		item.update(acacia);
        
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
