#ifndef HITBOX_HPP
#define HITBOX_HPP
#include <SFML/Graphics.hpp>

class HitBox
{
private:
    sf::FloatRect rect;

public:
    HitBox();
    setPosition();
    getPosition();

    sf::FloatRect getRect();

};

#endif // HITBOX_HPP
