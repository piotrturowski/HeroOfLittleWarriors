#include "button.hpp"

Button::Button()
{
    sf::String name = "";
    setNameButton(name);
    textSetup();
    loadTexture();
    swapTexture(0);
    textSetupUpdate();
    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);

    unlock();

}

void Button::textSetup()
{
    text.setCharacterSize(60);
    font.loadFromFile("art/Buttons/Super Foods.ttf");
    text.setFont(font);
    PressedColor = sf::Color(153,102,51);
    unpressedColor = sf::Color(175,117,59);
    text.setColor(unpressedColor);
}

void Button::textSetupUpdate()
{

    text.setOrigin(text.getGlobalBounds().width/2, text.getGlobalBounds().height/2);

    text.setPosition(sprite.getGlobalBounds().width/1.4,sprite.getGlobalBounds().height/2);
}

bool Button::loadTexture()
{
    texture[0].loadFromFile("art/Buttons/NormalButton.png");
    texture[1].loadFromFile("art/Buttons/ActivedButton.png");
    texture[2].loadFromFile("art/Buttons/PressedButton.png");
    texture[3].loadFromFile("art/Buttons/LockedButton.png");
}

void Button::swapTexture(int swapingStatus = 0)
{
    if(swapingStatus < 0 || swapingStatus > 3)
    {
        swapingStatus = 0;
    }
    tex.clear(sf::Color::Transparent);
    sf::Vector2u size(texture[0].getSize().x,texture[0].getSize().y);
    tex.create(size.x,size.y);
    tex.draw(sf::Sprite(texture[swapingStatus]));
    tex.draw(text);
    tex.display();
    sprite.setTexture(tex.getTexture());
    textSetupUpdate();
}

bool Button::isPressed(sf::RenderWindow * window)
{

    if(!isBlocked())
    {
        update(window);
        if(mouseIsInside(window)&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            swapTexture(2);
            return true;
        }
    }
    return false;
}

bool Button::mouseIsInside(sf::RenderWindow * window)
{
    return sprite.getGlobalBounds().contains(getTransformedMousePosition(window));
}

sf::Vector2f Button::getTransformedMousePosition(sf::RenderWindow * window)
{
    return window->mapPixelToCoords(sf::Mouse::getPosition(*window),window->getView());
}

sf::Sprite & Button::getSprite()
{
    return sprite;
}

void Button::setNameButton(sf::String name)
{
    text.setString(name);
    textSetupUpdate();
}

void Button::update(sf::RenderWindow * window)
{
    if(mouseIsInside(window))
    {
        swapTexture(1);
    }
    else
    {
        swapTexture(0);
    }

}


void Button::block()
{
    swapTexture(3);
    blocked = true;
}
void Button::unlock()
{
    blocked = false;
    swapTexture(0);
}

bool Button::isBlocked()
{
    if(blocked)
    {
        return true;
    }
    return false;
}

void Button::setScale(float x)
{
    sprite.setScale(x,x);
}


void Button::setPosition(float x, float y)
{
    setPosition(sf::Vector2f(x,y));
}

template <typename T>
void Button::setPosition(sf::Vector2<T> pos)
{
    sprite.setPosition(pos);
}

