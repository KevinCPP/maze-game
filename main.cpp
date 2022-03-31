//header includes
#include "Engine.h"

//SFML includes
#include <SFML/Graphics.hpp>

int main()
{
    //initialize global variables that we are going to use
    Engine::Initialize();

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    
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

        //begin game's code
        
        
        //end game's code

        Engine::gpWindow->clear();
        Engine::gpWindow->draw(shape);
        Engine::gpWindow->display();
    }

    return 0;
}

