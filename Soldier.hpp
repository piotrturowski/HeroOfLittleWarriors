#ifndef SOLDIER_HPP
#define SOLDIER_HPP
#include <SFML/Graphics.hpp>
#include "Animation.hpp"

class Soldier
{
protected:
    bool walking;
    bool attacking;
    Animation idleAnim;
    Animation walkAnim;
    Animation attackAnim;
    float speed;
    sf::Sprite sprite;
    void isWalking();
    void setup();



public:
    Soldier();
    sf::Sprite& getSprite();
    void update(sf::Time deltaTime);
    void move(sf::Vector2f moveDir);
    void stapWalking();
    void isAttacking();
    void stapAttacking();
    void attack();




};
#endif // SOLDIER_HPP
