#include "Button.h"

Button::Button(const sf::Vector2f& position, const sf::Color& defaultClr, const sf::Color& altClr, const std::string& text, unsigned int fontSize) {
    //initializing the sf::Text object
    drawableText = sf::Text(text, *Engine::gpFont, fontSize);
    drawableText.setFillColor(defaultColor);    

    //set other private variables
    selected = false;
    defaultColor = defaultClr;
    altColor = altClr;
}

sf::Vector2f Button::getPosition(){
    return drawableText.getPosition();
}

sf::FloatRect Button::getBounds(){
    return drawableText.getGlobalBounds();
}

void Button::setSelected(bool sel){
    selected = sel;
    
    if(sel)
        drawableText.setFillColor(altColor);
    else
        drawableText.setFillColor(defaultColor);
}

void Button::setPosition(const sf::Vector2f& position){
    drawableText.setPosition(position);
}


void Button::draw(){
    Engine::gpWindow->draw(drawableText);
}
