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
	platform level1_1{ window, sf::Vector2f( 250, 700 ), sf::Vector2f( 80 , 20) };
	platform level1_2{ window, sf::Vector2f( 120, 550 ), sf::Vector2f( 80 , 20) };
    platform level1_3{ window, sf::Vector2f( 250, 400 ), sf::Vector2f( 80 , 20) };
    platform level1_4{ window, sf::Vector2f( 500, 450 ), sf::Vector2f( 80 , 20) };
    platform level1_5{ window, sf::Vector2f( 750, 500 ), sf::Vector2f( 80 , 20) };
    platform level1_6{ window, sf::Vector2f( 80, 320 ), sf::Vector2f( 80 , 20) };
    wall wall1_1 { window, sf::Vector2f( 250, 700 ), sf::Vector2f( 50 , 900) };
    wall wall1_2 { window, sf::Vector2f( 750, 500 ), sf::Vector2f( 50 , 900) };
    wall left { window, sf::Vector2f( 2000, 0 ), sf::Vector2f( 50 , 900) };
    wall right { window, sf::Vector2f( -50, 0 ), sf::Vector2f( 50 , 900) };
	object item {window, sf::Vector2f(100, 300), sf::Vector2f(20,20)};

	platform level2_1{ window, sf::Vector2f( 0, 700 ), sf::Vector2f( 80 , 20) };
	platform level2_2{ window, sf::Vector2f( 150, 550 ), sf::Vector2f( 80 , 20) };
    platform level2_3{ window, sf::Vector2f( 300, 450 ), sf::Vector2f( 80 , 20) };
    platform level2_4{ window, sf::Vector2f( 450, 550 ), sf::Vector2f( 80 , 20) };
    platform level2_5{ window, sf::Vector2f( 700, 500 ), sf::Vector2f( 80 , 20) };
    platform level2_6{ window, sf::Vector2f( 850, 350 ), sf::Vector2f( 80 , 20) };
	platform level2_7{ window, sf::Vector2f( 700, 200 ), sf::Vector2f( 80 , 20) };
	platform level2_8{ window, sf::Vector2f( 550, 150 ), sf::Vector2f( 80 , 20) };
	platform level2_9{ window, sf::Vector2f( 300, 170 ), sf::Vector2f( 80 , 20) };
	platform level2_10{ window, sf::Vector2f( 150, 150 ), sf::Vector2f( 80 , 20) };
	platform level2_11{ window, sf::Vector2f( 850, 570 ), sf::Vector2f( 80 , 20) };
	platform level2_12{ window, sf::Vector2f( 930, 570 ), sf::Vector2f( 80 , 20) };
	wall wall2_1 { window, sf::Vector2f(850, 570 ), sf::Vector2f( 20 , 280) };
	wall wall2_2 { window, sf::Vector2f(990, 570 ), sf::Vector2f( 20 , 280) };
	object item2_1 {window, sf::Vector2f(170, 130), sf::Vector2f(20,20)};
	object item2_2 {window, sf::Vector2f(900, 830), sf::Vector2f(20,20)};

    //  BACKGROUND TEXTURE
    sf::Texture texture;
    texture.loadFromFile("bg-3000x1500.jpg");
    sf::Sprite bg;
    bg.move(sf::Vector2f(-400,-400));
    bg.setTexture(texture);

    //2 lines below create the view window
	sf::View view;
	view.setSize(sf::Vector2f(500.f, 400.f));

	action actions[] = {
        action( sf::Keyboard::Left,  [&](){ acacia.move( sf::Vector2f( -5.0,  0.0 )); }),
		action( sf::Keyboard::Right, [&](){ acacia.move( sf::Vector2f( +5.0,  0.0 )); }),
        action( sf::Keyboard::Up,    [&](){ acacia.jump( ); }),
		action( sf::Keyboard::E,	 [&](){ 
			if (level == 1){item.interact(acacia);} else{item2_1.interact(acacia);}})

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

	while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == false){
		window.display();	
		sf::Event event; 	
		while( window.pollEvent(event) ){	
			if( event.type == sf::Event::Closed ){	
				window.close();	
			}	
		} 	
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
            window.draw(bg);
			acacia.draw( window );
			wall1_1.draw( window );
			wall1_2.draw( window );
			bump.draw( window );
			Floor.draw( window );
			left.draw( window );
			right.draw( window );
			level1_1.draw(window);
			level1_2.draw(window);
			level1_3.draw(window);
			level1_4.draw(window);
			level1_5.draw(window);
			level1_6.draw(window);
			item.draw(window);
        }
		else{
            window.draw(bg);
            acacia.draw( window );
			if(item2_1.pickedUp == false){
		    	wall2_1.draw( window );
				wall2_2.draw( window );
			}
            Floor.draw( window ); 
			level2_1.draw(window);
			level2_2.draw(window);
			level2_3.draw(window);
			level2_4.draw(window);
			level2_5.draw(window);
			level2_6.draw(window);
			level2_7.draw(window);
			level2_8.draw(window);
			level2_9.draw(window);
			level2_10.draw(window);
			level2_11.draw(window);
			level2_12.draw(window);
			item2_1.draw(window);
			item2_2.draw(window);
        }
        
		for( auto & action : actions ){
			action();
		}
        
        if (level==1){
			acacia.update( );
			wall1_1.update(acacia);
			wall1_2.update(acacia);
			level1_1.update(acacia);
			level1_2.update(acacia);
			level1_3.update(acacia);
			level1_4.update(acacia);
			level1_5.update(acacia);
			level1_6.update(acacia);
			left.update( acacia );
			right.update(acacia);
			bump.update( acacia );
			Floor.update( acacia );
			item.update(acacia);
        }
		else{
            acacia.update();
			if(item2_1.pickedUp == false){
				wall2_1.update(acacia);
				wall2_2.update(acacia);
			}
            Floor.update(acacia);
			level2_1.update(acacia);
			level2_2.update(acacia);
			level2_3.update(acacia);
			level2_4.update(acacia);
			level2_5.update(acacia);
			level2_6.update(acacia);
			level2_7.update(acacia);
			level2_8.update(acacia);
			level2_9.update(acacia);
			level2_10.update(acacia);
			level2_11.update(acacia);
			level2_12.update(acacia);
			item2_1.update(acacia);
			item2_2.update(acacia);
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
