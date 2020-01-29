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
	sf::ContextSettings settings = window.getSettings();
	std::cout << "version: " << settings.majorVersion << " . " << settings.minorVersion << std::endl;

	player acacia { window, sf::Vector2f{ 0 , 780 }, sf::Vector2f( 30 , 68) };
	floor Floor { window, sf::Vector2f( 0, 850 ), sf::Vector2f( 2400 , 20) };
	wall left { window, sf::Vector2f( -50, -400 ), sf::Vector2f( 50 , 1600),1 }; 
	wall right { window, sf::Vector2f( 2350, 500 ), sf::Vector2f( 50 , 350) };

	platform level1_1{ window, sf::Vector2f( 250, 700 ), sf::Vector2f( 80 , 20) };
	platform level1_2{ window, sf::Vector2f( 120, 550 ), sf::Vector2f( 80 , 20) };
	platform level1_3{ window, sf::Vector2f( 250, 400 ), sf::Vector2f( 80 , 20) };
	platform level1_4{ window, sf::Vector2f( 500, 450 ), sf::Vector2f( 80 , 20) };
	platform level1_5{ window, sf::Vector2f( 750, 500 ), sf::Vector2f( 80 , 20) };
	//second part
	platform level1_6{ window, sf::Vector2f( 80, 250 ), sf::Vector2f( 80 , 20) };
	platform level1_7{ window, sf::Vector2f( 950, 450 ), sf::Vector2f( 80 , 20) };
	platform level1_8{ window, sf::Vector2f( 1150, 550 ), sf::Vector2f( 80 , 20) };
	platform level1_9{ window, sf::Vector2f( 1350, 450 ), sf::Vector2f( 80 , 20) };
	platform level1_10{ window, sf::Vector2f( 1550, 700 ), sf::Vector2f( 80 , 20) };
	platform level1_11{ window, sf::Vector2f( 1700, 550 ), sf::Vector2f( 80 , 20) };
	platform level1_12{ window, sf::Vector2f( 1850, 380 ), sf::Vector2f( 80 , 20) };
	platform level1_13{ window, sf::Vector2f( 1650, 250 ), sf::Vector2f( 80 , 20) };
	wall wall1_1 { window, sf::Vector2f( 750, 520 ), sf::Vector2f( 50 , 330) };
	wall wall1_2 { window, sf::Vector2f( 780, 200 ), sf::Vector2f( 500 , 300) };
	object item1_1 {window, sf::Vector2f(100, 220), sf::Vector2f(30,30), 3}; // connected to platform 1_6
	object item1_2 {window, sf::Vector2f( 850, 830), sf::Vector2f(20,20), 1}; // connected to floor
	object item1_3 {window, sf::Vector2f(1650, 230), sf::Vector2f(20,20), 1}; // connected to platform 1_13

	platform level2_1{ window, sf::Vector2f( 0, 700 ), sf::Vector2f( 80 , 20) };
	platform level2_2{ window, sf::Vector2f( 150, 550 ), sf::Vector2f( 80 , 20) };
	platform level2_3{ window, sf::Vector2f( 300, 450 ), sf::Vector2f( 80 , 20) };
	platform level2_4{ window, sf::Vector2f( 450, 550 ), sf::Vector2f( 80 , 20) };
	platform level2_5{ window, sf::Vector2f( 700, 500 ), sf::Vector2f( 80 , 20) };
	platform level2_6{ window, sf::Vector2f( 850, 350 ), sf::Vector2f( 80 , 20) };
	platform level2_7{ window, sf::Vector2f( 700, 200 ), sf::Vector2f( 80 , 20) };
	platform level2_8{ window, sf::Vector2f( 550, 150 ), sf::Vector2f( 80 , 20) };
	platform level2_9{ window, sf::Vector2f( 300, 160 ), sf::Vector2f( 80 , 20) };
	platform level2_10{ window, sf::Vector2f( 150, 150 ), sf::Vector2f( 80 , 20) };
	platform level2_11{ window, sf::Vector2f( 850, 560 ), sf::Vector2f( 80 , 20) };
	platform level2_12{ window, sf::Vector2f( 930, 560 ), sf::Vector2f( 80 , 20) };
	platform level2_13{ window, sf::Vector2f( 1080, 720 ), sf::Vector2f( 80 , 20) };
	platform level2_14{ window, sf::Vector2f( 1230, 570 ), sf::Vector2f( 80 , 20) };
	platform level2_15{ window, sf::Vector2f( 1380, 720 ), sf::Vector2f( 80 , 20) };
	platform level2_16{ window, sf::Vector2f( 1530, 570 ), sf::Vector2f( 80 , 20) };
	platform level2_17{ window, sf::Vector2f( 1680, 420 ), sf::Vector2f( 80 , 20) };
	platform level2_18{ window, sf::Vector2f( 1530, 270), sf::Vector2f( 80 , 20) };
	platform level2_19{ window, sf::Vector2f( 1380, 120 ), sf::Vector2f( 80 , 20) };
	platform level2_20{ window, sf::Vector2f( 1230, 120 ), sf::Vector2f( 80 , 20) };
	wall wall2_1 { window, sf::Vector2f(850, 560 ), sf::Vector2f( 50 , 290) };
	wall wall2_2 { window, sf::Vector2f(970, 560 ), sf::Vector2f( 50 , 290) };
	wall wall2_3 { window, sf::Vector2f(1230, 590 ), sf::Vector2f( 50 , 260) };
	wall wall2_3ext { window, sf::Vector2f(1230, 280 ), sf::Vector2f( 50 , 300) };
	object item2_1 {window, sf::Vector2f(170, 120), sf::Vector2f(30,30), 3}; // connected to platform 2_10
	object item2_2 {window, sf::Vector2f(900, 820), sf::Vector2f(30,30), 2}; // connected to floor
	object item2_3 {window, sf::Vector2f(1230, 16), sf::Vector2f(80,104), 4}; // connected to platform 2_20

	platform level3_1{ window, sf::Vector2f( 200, 700 ), sf::Vector2f( 80 , 20) };
	platform level3_2{ window, sf::Vector2f( 500, 700 ), sf::Vector2f( 80 , 20) };
	platform level3_3{ window, sf::Vector2f( 800, 700 ), sf::Vector2f( 80 , 20) };
	platform level3_4{ window, sf::Vector2f( 50, 550 ), sf::Vector2f( 80 , 20) };
	platform level3_5{ window, sf::Vector2f( 350, 550 ), sf::Vector2f( 80 , 20) };
	platform level3_6{ window, sf::Vector2f( 650, 550 ), sf::Vector2f( 80 , 20) };
	platform level3_7{ window, sf::Vector2f( 950, 550 ), sf::Vector2f( 80 , 20) };
	platform level3_8{ window, sf::Vector2f( 200, 400 ), sf::Vector2f( 80 , 20) };
	platform level3_9{ window, sf::Vector2f( 800, 400 ), sf::Vector2f( 80 , 20) };
	platform level3_10{ window, sf::Vector2f( 50, 250 ), sf::Vector2f( 80 , 20) };
	platform level3_11{ window, sf::Vector2f( 500, 250 ), sf::Vector2f( 80 , 20) };
	platform level3_12{ window, sf::Vector2f( 950, 250 ), sf::Vector2f( 80 , 20) };
	platform level3_13{ window, sf::Vector2f( 200, 100 ), sf::Vector2f( 80 , 20) };
	platform level3_14{ window, sf::Vector2f( 800, 100 ), sf::Vector2f( 80 , 20) };
	platform level3_15{ window, sf::Vector2f( 1100, 400 ), sf::Vector2f( 80 , 20) };
	platform level3_16{ window, sf::Vector2f( 1250, 250 ), sf::Vector2f( 80 , 20) };
	platform level3_17{ window, sf::Vector2f( 1400, 100 ), sf::Vector2f( 80 , 20) };
	platform level3_18{ window, sf::Vector2f( 1550, 200 ), sf::Vector2f( 80 , 20) };
	platform level3_19{ window, sf::Vector2f( 1700, 250 ), sf::Vector2f( 80 , 20) };
	platform level3_20{ window, sf::Vector2f( 1850, 400 ), sf::Vector2f( 80 , 20) };
	platform level3_21{ window, sf::Vector2f( 1700, 550 ), sf::Vector2f( 80 , 20) };
	platform level3_22{ window, sf::Vector2f( 1850, 700 ), sf::Vector2f( 80 , 20) };
	platform level3_23{ window, sf::Vector2f( 2000, 250 ), sf::Vector2f( 80 , 20) };
	platform level3_24{ window, sf::Vector2f( 2150, 100 ), sf::Vector2f( 80 , 20) };
    platform level3_25{ window, sf::Vector2f( 2230, 100 ), sf::Vector2f( 80 , 20) };
	object item3_1 {window, sf::Vector2f(230, 680), sf::Vector2f(20,20), 1}; // connected to platform 3_1
	object item3_2 {window, sf::Vector2f(230, 80), sf::Vector2f(20,20), 1}; // connected to platform 3_13
	object item3_3 {window, sf::Vector2f(2180, 80), sf::Vector2f(20,20), 1}; // connected to platform 3_24
	object item3_4 {window, sf::Vector2f(2000, 820), sf::Vector2f(30,30), 2}; // connected to floor
	wall wall3_11 { window, sf::Vector2f(980, -100 ), sf::Vector2f( 50 , 350 ) };
    wall wall3_12 { window, sf::Vector2f(980, 270 ), sf::Vector2f( 50 , 280) };
    wall wall3_13 { window, sf::Vector2f(980,  570), sf::Vector2f( 50 , 280) };
	wall wall3_2 { window, sf::Vector2f(1700, 570 ), sf::Vector2f( 50 , 280) };
    wall wall3_3 { window, sf::Vector2f(2260, -250 ), sf::Vector2f( 50 , 350) };

	// BACKGROUND TEXTURE
	sf::Texture texture;
	texture.loadFromFile("sprites/bg-3000x1500.jpg");
	sf::Sprite bg;
	bg.move(sf::Vector2f(-400,-400));
	bg.setTexture(texture);

	//2 lines below create the view window
	sf::View view;
	view.setSize(sf::Vector2f(500.f, 400.f));

	action actions[] = {
		action( sf::Keyboard::Left, [&](){ acacia.move( sf::Vector2f( -5.0, 0.0 )); }),
		action( sf::Keyboard::Right, [&](){ acacia.move( sf::Vector2f( +5.0, 0.0 )); }),
		action( sf::Keyboard::Up, [&](){ acacia.jump( ); }),
		action( sf::Keyboard::E, [&](){
			if (level == 1){
				item1_1.interact(acacia);
				item1_2.interact(acacia);
				item1_3.interact(acacia);
			} 
			else if(level==2){
				item2_1.interact(acacia);
				item2_2.interact(acacia);
				item2_3.interact(acacia);
			}
			else if(level==3){
				item3_1.interact(acacia);
				item3_2.interact(acacia);
				item3_3.interact(acacia);
				item3_4.interact(acacia);
			}
		})
	};

	window.clear();

	///Text setup
	sf::Font font;
	sf::Text story1;
	sf::Text story2;
	sf::Text contin;
	sf::Text movement;
	sf::Text lvl1;
	sf::Text lvl2;
	sf::Text lvl3;
	sf::Text ending;
	story1.setFont(font);
	story2.setFont(font);
	contin.setFont(font);
	movement.setFont(font);
	lvl1.setFont(font);
	lvl2.setFont(font);
	lvl3.setFont(font);
	ending.setFont(font);

	if (!font.loadFromFile("aller.ttf")){
		// error...
	}
	else{
		//Storytext
		story1.setString("You've fallen from the tree!");
		story1.setPosition(sf::Vector2f( 450.0, 100.0 ));
		story1.setCharacterSize(30);
		story1.setFillColor(sf::Color::White);
		story2.setString("Find your way back home by jumping through the branches and collecting items.");
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

		//Level 1 storytext
		lvl1.setString("Collect the two berries");
		lvl1.setCharacterSize(15);
		lvl1.setFillColor(sf::Color::White);

		//Level 2 storytext
		lvl2.setString("Find the key and open the gate");
		lvl2.setCharacterSize(15);
		lvl2.setFillColor(sf::Color::White);
		
		//Level 3 storytext
		lvl3.setString("Collect three berries and find the hidden key");
		lvl3.setCharacterSize(15);
		lvl3.setFillColor(sf::Color::White);
		
		//Ending storytext
		ending.setString("Thank you for playing!\nMore levels coming soon...");
		ending.setCharacterSize(15);
		ending.setFillColor(sf::Color::White);

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
		lvl1.setPosition(view.getCenter() + sf::Vector2f( -240.0, -190.0 ));
		lvl2.setPosition(view.getCenter() + sf::Vector2f( -240.0, -190.0 ));
		lvl3.setPosition(view.getCenter() + sf::Vector2f( -240.0, -190.0 ));
		ending.setPosition(view.getCenter() + sf::Vector2f( -70.0, -50.0 ));

		window.draw(bg);

		///Draws per level
		if (level==1){
			acacia.draw( window );
			left.draw( window );
			right.draw( window );
			Floor.draw( window );

			wall1_1.draw( window );
			if(item1_1.pickedUp == false){
				wall1_2.draw(window);
			}
			level1_1.draw(window);
			level1_2.draw(window);
			level1_3.draw(window);
			level1_4.draw(window);
			level1_5.draw(window);
			level1_6.draw(window);
			item1_1.draw(window);
			item1_2.draw(window);
			item1_3.draw(window);
			if(item1_1.pickedUp){
				level1_7.draw(window);
				level1_8.draw(window);
				level1_9.draw(window);
				level1_10.draw(window);
				level1_11.draw(window);
				level1_12.draw(window);
				level1_13.draw(window);
			}
			if (item1_2.pickedUp && item1_3.pickedUp){
				level=2;
				acacia.position=sf::Vector2f{ 0 , 780 };
			}
			window.draw(lvl1);
		}
		else if(level == 2){
            item2_3.draw(window);
            
			acacia.draw( window );
			Floor.draw( window );
			left.draw( window );
			right.draw( window ); 
			if(item2_1.pickedUp == false){
				wall2_1.draw( window );
			}
			if(item2_2.pickedUp == false){
				wall2_2.draw( window );
				wall2_3.draw(window);
				wall2_3ext.draw(window);
			}

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
			level2_13.draw(window);
			level2_14.draw(window);
			level2_15.draw(window);
			level2_16.draw(window);
			level2_17.draw(window); 
			level2_18.draw(window);
			level2_19.draw(window);
			level2_20.draw(window); 
			item2_1.draw(window);
			item2_2.draw(window);
//			item2_3.draw(window);
			if (item2_3.pickedUp){
				level=3;
				acacia.position=sf::Vector2f{ 800 , 780 };
			}
			window.draw(lvl2);
		}
		else if(level == 3){
			acacia.draw( window );
			Floor.draw( window );
			left.draw( window );
			right.draw( window );
			level3_1.draw(window);
			level3_2.draw(window);
			level3_3.draw(window);
			level3_4.draw(window);
			level3_5.draw(window);
			level3_6.draw(window);
			level3_7.draw(window);
			level3_8.draw(window);
			level3_9.draw(window);
			level3_10.draw(window);
			level3_11.draw(window);
			level3_12.draw(window);
			level3_13.draw(window);
			level3_14.draw(window);
			level3_15.draw(window);
			level3_16.draw(window);
			level3_17.draw(window);
			level3_18.draw(window);
			level3_19.draw(window);
			level3_20.draw(window);
			level3_21.draw(window);
			level3_22.draw(window);
			level3_23.draw(window);
			level3_24.draw(window);
            level3_25.draw(window);
			item3_1.draw(window);
			item3_2.draw(window);
			item3_3.draw(window);
            wall3_3.draw(window);
			if(item3_3.pickedUp == true){
				item3_4.draw(window);
			}
			if(!(item3_1.pickedUp == true && item3_2.pickedUp == true)){
				wall3_11.draw(window);
                wall3_12.draw(window);
                wall3_13.draw(window);
			}
			wall3_2.draw(window);
			if(item3_4.pickedUp == false){
				window.draw(lvl3);
			}
			else{
				window.draw(ending);
			}
		}

		for( auto & action : actions ){
			action();
		}

		///Updates per level
		if (level==1){
			acacia.update( );
			left.update( acacia );
			right.update(acacia);
			Floor.update( acacia );

			wall1_1.update(acacia);
			if(item1_1.pickedUp == false){
				wall1_2.update(acacia);
			}
			level1_1.update(acacia);
			level1_2.update(acacia);
			level1_3.update(acacia);
			level1_4.update(acacia);
			level1_5.update(acacia);
			//second part
			level1_6.update(acacia);
			level1_7.update(acacia);
			level1_8.update(acacia);
			level1_9.update(acacia);
			level1_10.update(acacia);
			level1_11.update(acacia);
			level1_12.update(acacia);
			level1_13.update(acacia);
			item1_1.update(acacia);
			item1_2.update(acacia);
			item1_3.update(acacia); 
		}

		else if(level == 2){
			acacia.update();
			Floor.update(acacia);
			left.update( acacia );
			right.update(acacia);

			if(item2_1.pickedUp == false){
				wall2_1.update(acacia);
			}

			if(item2_2.pickedUp == false){
				wall2_2.update(acacia);
				wall2_3.update(acacia);
				wall2_3ext.update(acacia);
			}

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
			level2_13.update(acacia);
			level2_14.update(acacia);
			level2_15.update(acacia);
			level2_16.update(acacia);
			level2_17.update(acacia);
			level2_18.update(acacia);
			level2_19.update(acacia);
			level2_20.update(acacia);
			item2_1.update(acacia);
			item2_2.update(acacia);
			item2_3.update(acacia);
		}

		else if(level == 3){
			acacia.update();
			Floor.update(acacia);
			left.update( acacia );
			right.update(acacia);

			level3_1.update(acacia);
			level3_2.update(acacia);
			level3_3.update(acacia);
			level3_4.update(acacia);
			level3_5.update(acacia);
			level3_6.update(acacia);
			level3_7.update(acacia);
			level3_8.update(acacia);
			level3_9.update(acacia);
			level3_10.update(acacia);
			level3_11.update(acacia);
			level3_12.update(acacia);
			level3_13.update(acacia);
			level3_14.update(acacia);
			level3_15.update(acacia);
			level3_16.update(acacia);
			level3_17.update(acacia);
			level3_18.update(acacia);
			level3_19.update(acacia);
			level3_20.update(acacia);
			level3_21.update(acacia);
			level3_22.update(acacia);
			level3_23.update(acacia);
			level3_24.update(acacia);
            level3_25.update(acacia);
			item3_1.update(acacia);
			item3_2.update(acacia);
			item3_3.update(acacia);
            wall3_3.update(acacia);
			if(item3_3.pickedUp == true){
				item3_4.update(acacia);
			}
			if(!(item3_1.pickedUp == true && item3_2.pickedUp == true)){
				wall3_11.update(acacia);
                wall3_12.update(acacia);
                wall3_13.update(acacia);
			}
			wall3_2.update(acacia);
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