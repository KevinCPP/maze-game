#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

//header includes
#include "Engine.h"

//std includes
#include <vector>
#include <memory>
#include <string>

class Button{
    sf::Text            drawableText; //the actual text object to be drawn    
    sf::Color           defaultColor; //the default color of the button
    sf::Color           altColor;     //alternative color of button (can switch to this color from default, for example, when the button is "selected" in a menu)
    
    unsigned int        fontSize; //size of the font used in the button text
    bool                selected; //whether to use the alternate color or not

public:
    
    //constructor
    Button(const sf::Vector2f& position,
            const sf::Color& defaultClr,
            const sf::Color& altClr,
            const std::string& text,
            unsigned int fontSize);

    //get the current position of the button   
    sf::Vector2f getPosition();

    //get collision bounds of the button
    sf::FloatRect getBounds();

    //set selected and update sf::Text color
    void setSelected(bool sel);
    
    //change the position of the button:
    void setPosition(const sf::Vector2f& position);

    //draw the button toe the screen.
    void draw();
};

#endif
