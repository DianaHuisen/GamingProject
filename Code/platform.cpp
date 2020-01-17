#include <SFML/Graphics.hpp>
#include "platform.hpp"
#include <iostream>

platform::platform( sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size ) :
    rectangle(window, position, size), position(position), size(size){rect.setFillColor(sf::Color( 0, 200, 0));}

void platform::draw( sf::RenderWindow & window ){
    rect.setSize(sf::Vector2f(size));
    rect.setPosition(position);
//    rect.setFillColor(sf::Color( 0, 200, 0));
    window.draw(rect);
}

void platform::update( player & acacia ){
    hitbox = rect.getGlobalBounds();
    std::cout << acacia.velocity.y << "\n";
    
//    if (hitbox.intersects(acacia.hitbox)==false && acacia.jumping == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)==false){
//        if(acacia.velocity.y < acacia.maxY){
//            acacia.velocity += acacia.gravity;
//        }
//        sf::sleep (sf::milliseconds(8));
////        if (hitbox.intersects(platform.hitbox)){
////            jumping = false;
////            velocity.y=0;
////        }
//        acacia.bouncy=acacia.velocity;
//    }
    
    if (hitbox.intersects(acacia.hitbox)){
        if(acacia.velocity.y>3){
            std::cout << "GOINGDOWN\n";
            
        }
        acacia.velocity.y = 0.0;
        std::cout << "RESET\n";
        acacia.move(sf::Vector2f( 0.0, -2.0 ));
        if (acacia.jumping){
            std::cout << "EXJUMP\n";
            acacia.jumping = false;
            acacia.velocity.y=-15.0;
        }
    }
}

//void platform::update( player & acacia ){
//
//    hitbox = rect.getGlobalBounds();
//    if (hitbox.intersects(acacia.hitbox)){
////        acacia.velocity.y=0.0;
//    std::cout << acacia.velocity.y << "\n";
//    }
//    
//    if (hitbox.intersects(acacia.hitbox)==false && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)==false){
//        if(acacia.jumping){
//            
//            if(acacia.velocity.y < acacia.maxY){
//                acacia.velocity += acacia.gravity;
//                std::cout << "+1\n";
//            }
//            sf::sleep (sf::milliseconds(8));
////        if (hitbox.intersects(platform.hitbox)){
////            jumping = false;
////            velocity.y=0;
////        }
////            acacia.bouncy=acacia.velocity;
//        }
//    }
//                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)==true){
//            acacia.jumping=true;
//            std::cout << "KEY_IS_UP\n";
//        }
//    
//    if (hitbox.intersects(acacia.hitbox) && acacia.velocity.y>5 && acacia.jumping){
//        
////        acacia.bouncy.y = acacia.bouncy.y *0.99;
////        acacia.velocity += acacia.gravity;
//        acacia.velocity.y = 0;
//        acacia.move(sf::Vector2f( 0.0, -2.0 ));
//        if (acacia.jumping){
//            
//            acacia.jumping = false;
////            acacia.velocity.y=-15.0;
////            acacia.velocity.y = 0;
//            
//        }
//        acacia.acacia.setFillColor(sf::Color::Blue);
////        acacia.move(acacia.velocity);
//    }else if(hitbox.intersects(acacia.hitbox)&& acacia.velocity.y==0){
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)==true){
//            acacia.jumping=true;
//            std::cout << "TEST\n";
//        }
//        if (acacia.jumping){
//            std::cout << "JUMP\n";
////            acacia.jumping = false;
//            acacia.move(sf::Vector2f( 0.0, -55.0 ));
//            acacia.velocity.y=-15.0;
////            sf::sleep( sf::milliseconds( 1000 ));        }else{
////        }
////            acacia.velocity.y = 0;
//            acacia.move(sf::Vector2f( 0.0, -2.0 ));
//        }
//
//        acacia.acacia.setFillColor(sf::Color::Magenta);
//    }else if(hitbox.intersects(acacia.hitbox)&& acacia.velocity.y<0){
//        acacia.acacia.setFillColor(sf::Color::Cyan);
//    }
//    
//    
//    if(acacia.jumping){
//        rect.setFillColor(sf::Color::Green);
////        acacia.bouncy.y = acacia.bouncy.y *1.01;
//    }else{
//        rect.setFillColor(sf::Color::Red);
//    }
////    if (hitbox.intersects(platform.hitbox)){
////        bouncy.y = 1;
////        acacia.setFillColor(sf::Color::Blue);
////        move(sf::Vector2f( 0.0, -2.0 ));
////        if (jumping){
////            jumping = false;
////            velocity.y=-15.f;
////        }
////    }
//    
//}


