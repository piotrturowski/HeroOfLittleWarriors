#include "button.hpp"

Button::Button()
{
    sf::String name = "";
    setNameButton(name);
    textSetup();
    loadTexture();
    textSetupUpdate();
    swapTexture(0);
    unlock();

}

void Button::textSetup()
{
    text.setCharacterSize(60);
    font.loadFromFile("art/Buttons/Super Foods.ttf");
    text.setFont(font);
    PressedColor = sf::Color(153,102,51);
    unpressedColor = sf::Color(175,117,59);
}

void Button::textSetupUpdate()
{
    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);
    text.setOrigin(-text.getGlobalBounds().width*3/5,-text.getGlobalBounds().height);
    sprite.setPosition(0,0);
    text.setPosition(0,0);
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
    sprite.setOrigin(0,0);
    sf::Vector2u size(texture[0].getSize().x,texture[0].getSize().y);
    tex.create(size.x,size.y);
    switch(swapingStatus)
    {
    case 0:
        {
            sprite.setTexture(texture[0]);
            text.setColor(unpressedColor);
            break;
        }
    case 1:
        {
            sprite.setTexture(texture[1]);
            text.setColor(unpressedColor);
            break;
        }
    case 2:
        {
            sprite.setTexture(texture[2]);
            text.setColor(PressedColor);
            break;
        }
    case 3:
        {
            sprite.setTexture(texture[3]);
            break;
        }
    default:
        {
            sprite.setTexture(texture[0]);
            break;
        }
    }
    tex.draw(sprite);
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
    word = name;
    text.setString(word);
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


