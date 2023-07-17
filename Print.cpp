#include "Print.hpp"

void Print::addSprite(sf::Sprite sprite)
{
    spriteBuffer.push_back(sprite);
}

void Print::addSprite(std::vector <sf::Sprite> sprite)
{
    for(int i = 0; i < sprite.size();i++)
        spriteBuffer.push_back(sprite[i]);
}

void Print::addSprite(std::queue <sf::Sprite> sprite)
{
    while(!sprite.empty())
        spriteBuffer.push_back(sprite.back());
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
