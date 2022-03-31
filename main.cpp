//header includes
#include "Engine.h"

//SFML includes
#include <SFML/Graphics.hpp>

//standard includes
#include <iostream>

void testMenu();

int main()
{
    //initialize the engine
    if(!Engine::Initialize()){
        std::cout << "failed to initialize engine.\n";
        return -1;
    }
   
    //main loop
    while (Engine::gpWindow->isOpen())
    {
        //event handling
        sf::Event event;
        while (Engine::gpWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Engine::gpWindow->close();
        }

        Engine::gpWindow->clear();
        //begin rendering
        
        testMenu();
        
        //end rendering
        Engine::gpWindow->display();
    }

    return 0;
}

#include "Menu.h"

void testMenu(){
    Menu m(sf::Vector2f(20, Engine::yResolution/3), sf::Color::Black, sf::Color::White, sf::Color::Yellow, 32);

    m.addButton("Play");
    m.addButton("Options");
    m.addButton("Information");
    m.addButton("quit");
    
    m.draw();
}
