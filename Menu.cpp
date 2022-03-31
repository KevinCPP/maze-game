#include "Menu.h"

Menu::Menu(const sf::Vector2f& pos, const sf::Color& backgroundClr, const sf::Color& buttonClr, const sf::Color& selectClr, unsigned int fontsize){
    //set variables
    backgroundPos = pos;
    backgroundColor = backgroundClr;
    buttonColor = buttonClr;
    selectColor = selectClr;
    fontSize = fontsize;    


    background.setPosition(backgroundPos);
    background.setFillColor(backgroundColor);

    background.setSize(sf::Vector2f(10, 10));
}

void Menu::addButton(const std::string& content){
    //figure out what the x and y position of our new button should be
    sf::Vector2f buttonPosition;
    buttonPosition.x = backgroundPos.x + padding;
    buttonPosition.y = Height;
    
    //create the actual button object
    Button b(buttonPosition, buttonColor, selectColor, content, fontSize);
    
    //add the button to the list
    buttons.push_back(b);
    
    //y position for the next button
    Height += b.getBounds().height + padding;
    
    //if this button is too wide and would go off the edge
    //of the background, expand the background
    unsigned int thisWidth = b.getBounds().width + padding*2;

    if(thisWidth > Width)
        Width = thisWidth;
    
    background.setSize(sf::Vector2f(Width, Height));
}

void Menu::draw(){
    Engine::gpWindow->draw(background);

    for(auto& p : buttons){
        p.draw();
    }
}
