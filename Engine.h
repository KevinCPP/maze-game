#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

//standard includes
#include <iostream>
#include <memory>

//sfml includes
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Engine {
    sf::RenderWindow    window;         //window object that everything will be drawn to
    sf::Clock           framerateClock; //clock used to keep track of framerate
    sf::Clock           logicClock;     //clock used to keep track of logic cycles / ticks
    sf::Font            defaultFont;    //default font to be used for text
    uint32_t            ticksPerSecond; //how many logic ticks should happen every second
    double              lastFPS;        //last framerate calculated by calculateFPS()
    double              lastLC;         //last logic cycles calculated by calculateLC()
     
    double calculateFPS(); //calculates the FPS
    double calculateLC();  //calculates how many logic cycles have elapsed
public:
    //constructor
    Engine(const sf::VideoMode& videoMode = sf::VideoMode(1280, 720),
            const std::string& title = "Title",
            const uint32_t style = sf::Style::Default,
            const uint32_t TPS = 60);
            
    //draw something to the render window
    void draw(const sf::Drawable& drawable, const sf::RenderStates& states = sf::RenderStates::Default);
    
    bool pollEvent(sf::Event& event);   //poll for any events happening in the window, put them in event
    bool windowIsOpen();                //check if the render window is currently open
    void display();                     //display everything to the screen. should be called each frame after all draw() calls
    void clear();                       //clear the screen before the next frame. should be called before all draw() calls
    void close();                       //close the render window and exit the engine

    //getters
    sf::Vector2u getResolution();       //returns the resolution of window
    sf::Vector2f getMousePos();         //returns the position of the mouse in window
    double getLogicCycles();            //returns how many ticks have passed since the last display() statement
    double getFramerate();              //returns the current framerate  
    sf::Font getFont();                 //returns the default font    
   
    //setters
    void setResolution(uint32_t x, uint32_t y); //changes the resolution of window
    void setTitle(const std::string& title);    //changes the title of window
    void setTPS(uint32_t tps);                  //sets how many ticks per second logic should be
};

#endif
