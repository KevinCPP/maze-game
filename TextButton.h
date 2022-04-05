#ifndef TEXTBUTTON_H_INCLUDED
#define TEXTBUTTON_H_INCLUDED

#include "Engine.h"
#include <string>

class TextButton : public sf::Drawable{
private:
    sf::Text button;
    sf::FloatRect collision;
    sf::Color defaultColor;
    sf::Color hoverColor;
    bool mouseClicked;
public:
    TextButton(const sf::Vector2f& position,
               const sf::Color& defaultClr,
               const sf::Color& hoverClr,
               const wchar_t* text,
               const sf::Font& font,
               const int& fontSize);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    bool pollClicked(const sf::Vector2f& mousePos);
    bool isHovering(const sf::Vector2f& mousePos);

    //setters:

    void setPosition(const float& x, const float& y);
    void setHoverColor(const sf::Color& color);
    void setPosition(const sf::Vector2f& pos);
    void setColor(const sf::Color& color);
    void setFont(const sf::Font& font);
    void setText(const wchar_t* text);
    void setWasClicked(bool c);

    //getters:
    sf::FloatRect getCollision();
    sf::Color getDefaultColor();
    sf::Vector2f getPosition();
    sf::Color getHoverColor();
    const sf::Font* getFont();
    std::wstring getText();
    bool getWasClicked();
};

#endif // TEXTBUTTON_H_INCLUDED
