#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Engine.h"
#include "Button.h"
#include <vector>

class Menu{    
    std::vector<Button> buttons; //all of the buttons in the menu

    sf::RectangleShape background; //the background to be drawn behind the buttons.
        
    sf::Vector2f backgroundPos; //position of background
    sf::Color backgroundColor; //color of the background
    sf::Color buttonColor; //color of the buttons
    sf::Color selectColor; //color of the currently selected button
    unsigned int fontSize; //size of the button fonts
        

    const unsigned int padding = 10; //space between buttons and edges of background
    unsigned int Height = 0; //how tall should background be?
    unsigned int Width = 0; //how wide should background be?
public:
    Menu(const sf::Vector2f& pos, const sf::Color& backgroundClr, const sf::Color& buttonClr, const sf::Color& selectClr, unsigned int fontsize);
    
    void addButton(const std::string& content);

    void draw();
};

#endif
