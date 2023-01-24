#ifndef PRINT_HPP
#define PRINT_HPP
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Print
{
private:
    std::vector <sf::Sprite> spriteBuffer;
public:
    bool operatorLess(const sf::Sprite& sprite,const sf::Sprite& sprite2);
    void addSprite(sf::Sprite sprite);
    void sort();
    void draw(sf::RenderWindow * window);

};
#endif // PRINT_HPP
