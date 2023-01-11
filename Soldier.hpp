#ifndef SOLDIER_HPP
#define SOLDIER_HPP
#include <SFML/Graphics.hpp>
#include "Animation.hpp"

class Soldier
{
protected:
    bool walking;
    bool attacking;
    bool hurting;
    Animation idleAnim;
    Animation walkAnim;
    Animation attackAnim;
    Animation hurtAnim;
    float speed;
    sf::Sprite sprite;
    void isWalking();
    void setup();
    void setCenter();


public:
    Soldier();
    sf::Sprite& getSprite();
    void update(sf::Time deltaTime);
    void move(sf::Vector2f moveDir);
    void stapWalking();
    void isAttacking();
    void stapAttacking();
    void attack();
    void isHurting();
    void stopHurting();




};
#endif // SOLDIER_HPP
