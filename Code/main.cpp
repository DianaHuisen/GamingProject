#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include "player.hpp"
#include "floor.hpp"
#include "platform.hpp" 
#include "object.hpp"
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
    int level=1;
	std::cout << "Starting application 01-05 array of actions\n";

	sf::RenderWindow window{ sf::VideoMode{ 1280, 900 }, "SFML window" };
    player acacia { window, sf::Vector2f{ 0 , 780 }, sf::Vector2f( 30 , 68) };
    floor Floor { window, sf::Vector2f( 0, 850 ), sf::Vector2f( 2000 , 20) };
    floor bump { window, sf::Vector2f( 540, 800 ), sf::Vector2f( 640 , 20) };
	platform One{ window, sf::Vector2f( 250, 700 ), sf::Vector2f( 80 , 20) };
	platform Two{ window, sf::Vector2f( 120, 550 ), sf::Vector2f( 80 , 20) };
    platform Three{ window, sf::Vector2f( 250, 400 ), sf::Vector2f( 80 , 20) };
    platform Four{ window, sf::Vector2f( 500, 450 ), sf::Vector2f( 80 , 20) };
    platform Five{ window, sf::Vector2f( 750, 500 ), sf::Vector2f( 80 , 20) };
    platform Six{ window, sf::Vector2f( 80, 320 ), sf::Vector2f( 80 , 20) };
    wall first { window, sf::Vector2f( 250, 700 ), sf::Vector2f( 50 , 900) };
    wall second { window, sf::Vector2f( 750, 500 ), sf::Vector2f( 50 , 900) };
    wall left { window, sf::Vector2f( 2000, 0 ), sf::Vector2f( 50 , 900) };
    wall right { window, sf::Vector2f( -50, 0 ), sf::Vector2f( 50 , 900) };
	object item {window, sf::Vector2f(100, 300), sf::Vector2f(20,20)};



    //2 lines below create the view window
	sf::View view;
	view.setSize(sf::Vector2f(500.f, 400.f));

	action actions[] = {
        action( sf::Keyboard::Left,  [&](){ acacia.move( sf::Vector2f( -5.0,  0.0 )); }),
		action( sf::Keyboard::Right, [&](){ acacia.move( sf::Vector2f( +5.0,  0.0 )); }),
        action( sf::Keyboard::Up,    [&](){ acacia.jump( ); }),
		action( sf::Keyboard::E,	 [&](){ item.interact(acacia);})

	};
	
	window.clear();

	///Startingscreen setup
	sf::Font font;
	sf::Text story1;
	sf::Text story2;
	sf::Text contin;
	sf::Text movement;
	story1.setFont(font);
	story2.setFont(font);
	contin.setFont(font);
	movement.setFont(font);
	if (!font.loadFromFile("aller.ttf")){
		// error...
	}
	else{
		//Storytext
		story1.setString("You've fallen from the tree!");
		story1.setPosition(sf::Vector2f( 450.0, 100.0 ));
		story1.setCharacterSize(30);
		story1.setFillColor(sf::Color::White);
		story2.setString("Find your way back home by jumping through the branches and learning new skills.");
		story2.setPosition(sf::Vector2f( 50.0, 140.0 ));
		story2.setCharacterSize(30);
		story2.setFillColor(sf::Color::White);

		//Movement
		movement.setString("Use the arrowkeys to move around\nUse the \"E\" to interact with objects");
		movement.setPosition(sf::Vector2f( 450.0, 550.0 ));
		movement.setCharacterSize(20);
		movement.setStyle(sf::Text::Italic);
		movement.setFillColor(sf::Color::White);

		//Spacebar text
		contin.setString("Press spacebar to continue");
		contin.setPosition(sf::Vector2f( 430.0, 700.0 ));
		contin.setCharacterSize(30);
		contin.setFillColor(sf::Color::White);

		window.draw(contin); 
		window.draw(story1);
		window.draw(story2);
		window.draw(movement);
	}


    
	while (window.isOpen()) {
		window.clear();
		
        //these 2 lines connect the view window to the player position
		view.setCenter( acacia.position.x, acacia.position.y);
		window.setView(view);
  
        if (item.pickedUp){
            level=2;
        }
        if (level==1){
        acacia.draw( window );
        first.draw( window );
        second.draw( window );
        bump.draw( window );
        Floor.draw( window );
        left.draw( window );
        right.draw( window );
        One.draw(window);
        Two.draw(window);
        Three.draw(window);
        Four.draw(window);
        Five.draw(window);
        Six.draw(window);
		item.draw(window);
        
        }else{
           acacia.draw( window );
            Floor.draw( window ); 
        }
        
		for( auto & action : actions ){
			action();
		}
        
        if (level==1){
        acacia.update( );
        first.update(acacia);
        second.update(acacia);
		One.update(acacia);
        Two.update(acacia);
        Three.update(acacia);
        Four.update(acacia);
        Five.update(acacia);
        Six.update(acacia);
        left.update( acacia );
        right.update(acacia);
        bump.update( acacia );
        Floor.update( acacia );
		item.update(acacia);
        
        }else{
            acacia.update();
            Floor.update(acacia);
        }
        
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
