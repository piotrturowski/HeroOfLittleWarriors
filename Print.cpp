#include "Print.hpp"

void Print::addSprite(sf::Sprite sprite)
{
    spriteBuffer.push_back(sprite);
}

bool Print::operatorLess(const sf::Sprite & sprite, const sf::Sprite& sprite2)
{
    if(sprite.getGlobalBounds().top + sprite.getGlobalBounds().height < sprite2.getGlobalBounds().top + sprite2.getGlobalBounds().height)
    {
        std::cout << "porownuje" << std::endl;
        return true;
    }
    return false;
}

void Print::sort()
{
    for(int i=0;i<spriteBuffer.size();i++)

       for(int j=1;j<spriteBuffer.size()-i;j++)
       {
           if(spriteBuffer[j-1].getGlobalBounds().top+spriteBuffer[j-1].getGlobalBounds().height
              < spriteBuffer[j].getGlobalBounds().top+spriteBuffer[j].getGlobalBounds().height)
           {
                std::swap(spriteBuffer[j],spriteBuffer[j-1]);
           }
       }
}


void Print::draw(sf::RenderWindow * window)
{
    for(int i = spriteBuffer.size()-1; i >= 0; i--)
    {
        window->draw(spriteBuffer[i]);
        spriteBuffer.pop_back();
    }
}
