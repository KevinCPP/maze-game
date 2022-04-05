#include "TextButton.h"
#include "Engine.h"

TextButton::TextButton(const sf::Vector2f& position, const sf::Color& defaultClr, const sf::Color& hoverClr, const wchar_t* text, const sf::Font& font, const int& fontSize){
    button.setPosition(position);
    button.setFillColor(defaultClr);
    button.setString(text);
    button.setCharacterSize(fontSize);
    button.setFont(font);

    defaultColor = defaultClr;
    hoverColor = hoverClr;
    collision = button.getGlobalBounds();
}

bool TextButton::isHovering(const sf::Vector2f& mousePos){
    if(collision.contains(mousePos)){
        button.setFillColor(hoverColor);
        return true;
    }
    
    button.setFillColor(defaultColor);
    return false; 
    
}

bool TextButton::pollClicked(const sf::Vector2f& mousePos){
    if(isHovering(mousePos) && !mouseClicked){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            mouseClicked = true;
            return true;
        } else {
            mouseClicked = false;
            return false;
        }
    }

    if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
        mouseClicked = false;
    else
        mouseClicked = true;

    return false;
}

void TextButton::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(button, states);
}

void TextButton::setPosition(const float& x, const float& y){
    button.setPosition(x, y);
    collision = button.getGlobalBounds();
}

void TextButton::setPosition(const sf::Vector2f& pos){
    button.setPosition(pos);
    collision = button.getGlobalBounds();
}

void TextButton::setHoverColor(const sf::Color& color){
    hoverColor = color;
}

void TextButton::setColor(const sf::Color& color){
    defaultColor = color;
    button.setFillColor(color);
}

void TextButton::setFont(const sf::Font& font){
    button.setFont(font);
    collision = button.getGlobalBounds();
}

void TextButton::setText(const wchar_t* text){
    button.setString(text);
    collision = button.getGlobalBounds();
}

void TextButton::setWasClicked(bool c){
    mouseClicked = c;
}

sf::FloatRect TextButton::getCollision(){
    return collision;
}

sf::Color TextButton::getDefaultColor(){
    return defaultColor;
}

sf::Vector2f TextButton::getPosition(){
    return button.getPosition();
}

sf::Color TextButton::getHoverColor(){
    return hoverColor;
}

const sf::Font* TextButton::getFont(){
    return button.getFont();
}

std::wstring TextButton::getText(){
    return button.getString();
}

bool TextButton::getWasClicked(){
    return mouseClicked;
}
