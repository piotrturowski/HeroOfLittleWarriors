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
    void addSprite(sf::Sprite sprite);
    void addSprite(std::vector <sf::Sprite> sprite);
    void sort();
    void draw(sf::RenderWindow * window);

};
#endif // PRINT_HPP
