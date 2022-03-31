#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <memory>

namespace Engine{
    extern std::unique_ptr<sf::Clock>          gpFramerateClock;
    extern std::unique_ptr<sf::RenderWindow>   gpWindow;
    extern std::unique_ptr<sf::Font>           gpFont;
    extern const uint32_t xResolution, yResolution;
    

    bool Initialize();
    
    inline double getFramerate();    
    sf::Vector2f getMousePos();
}


#endif
