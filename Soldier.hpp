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
    void hitBoxUpdate();
    sf::RectangleShape hitBox;
    sf::RectangleShape weponHitBox;


public:
    Soldier();
    sf::Sprite& getSprite();
    void update(sf::Time deltaTime);
    void move(sf::Vector2f moveDir);
    void move(sf::Vector2f moveDir,sf::FloatRect battleArea);
    void stapWalking();
    void isAttacking();
    void stapAttacking();
    void attack();
    void isHurting();
    void stopHurting();
    void onCollision(sf::FloatRect enemyHitBox);
    sf::FloatRect getWeponHitBox();



};
#endif // SOLDIER_HPP
