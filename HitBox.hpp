#ifndef HITBOX_HPP
#define HITBOX_HPP
#include <SFML/Graphics.hpp>

class HitBox
{
private:
    sf::RectangleShape hitBox;
    void hitBoxUpdate();
public:
    HitBox();

};

#endif // HITBOX_HPP
