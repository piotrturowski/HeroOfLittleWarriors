#include "textureSheet.hpp"
TextureSheet::TextureSheet()
{
    it=0;
    size=0;
    endOfSheet = false;
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
    endOfSheet = false;
    it++;
    if(it==size)
    {
        resetIteratorPosition();
    }
}

void TextureSheet::resetIteratorPosition()
{
    it = 0;
    endOfSheet = true;
}

bool TextureSheet::isEndOfSheet()
{
    return endOfSheet;
}
