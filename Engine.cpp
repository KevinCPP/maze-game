//header includes
#include "Engine.h"

//standard includes
#include <iostream>

namespace Engine{
    std::unique_ptr<sf::Clock>           gpFramerateClock;
    std::unique_ptr<sf::RenderWindow>    gpWindow;
    std::unique_ptr<sf::Font>            gpFont;    
    
    const unsigned int xResolution = 1280, yResolution = 720;    

    bool Initialize(){
        gpWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(xResolution, yResolution), "SFML Window!");
        gpFramerateClock = std::make_unique<sf::Clock>();
        gpFont = std::make_unique<sf::Font>();
        if(!gpFont->loadFromFile("assets/default.ttf")){
            std::cout << "couldn't load font\n";
            return false;
        }        

        return true;
    }
    
    inline double getFramerate(){
        double T = gpFramerateClock->getElapsedTime().asMicroseconds();
        double framerate = 1000000/T;
        gpFramerateClock->restart();
        return framerate;
    }

    sf::Vector2f getMousePos(){
        sf::Vector2i mousePos2i = sf::Mouse::getPosition(*gpWindow);
        sf::Vector2f mousePos2f;
        mousePos2f.x = (float)mousePos2i.x;
        mousePos2f.y = (float)mousePos2i.y;
        return mousePos2f;
    }
}
