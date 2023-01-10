#ifndef BRONZESOLDIER_HPP
#define BRONZESOLDIER_HPP
#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "textureSheet.hpp"

class BronzeSoldier
{
public:
    BronzeSoldier();
    sf::Sprite& getSprite();
    void update(sf::Time deltaTime);
    void move(sf::Vector2f moveDir);
    void isWalking();
    void stapWalking();
    void isAttacking();
    void stapAttacking();
    void attack();

private:
    bool walking;
    bool attacking;
    Animation idleAnim;
    Animation walkAnim;
    Animation attackAnim;
    float speed;
    sf::Sprite sprite;
};
#endif // BRONZESOLDIER_HPP
