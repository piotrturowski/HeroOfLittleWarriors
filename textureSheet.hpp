#ifndef TEXTURESHEET_HPP
#define TEXTURESHEET_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

class TextureSheet
{
public:
    TextureSheet();
    void addTexture(std::string path);
    sf::Texture& getCurrentTexture();
    void resetIteratorPosition();
    void nextPositionOfIterator();
private:
    unsigned short size;
    unsigned short it;
    sf::Texture textureSheet[8];
};
#endif // TEXTURESHEET_HPP
