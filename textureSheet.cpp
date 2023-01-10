#include "textureSheet.hpp"
TextureSheet::TextureSheet()
{
    it=0;
    size=0;
}

void TextureSheet::addTexture(std::string path)
{
    textureSheet[size].loadFromFile(path);
    size++;
}

sf::Texture& TextureSheet::getCurrentTexture()
{
    return textureSheet[it];
}

void TextureSheet::nextPositionOfIterator()
{
    if(it==size-1)
    {
        it= 0;
    }
    it++;
}

void TextureSheet::resetIteratorPosition()
{
    it = 0;
}
