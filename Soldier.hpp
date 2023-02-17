#ifndef SOLDIER_HPP
#define SOLDIER_HPP
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Animation.hpp"

class Soldier
{
protected:
    float speed;
    bool walking;
    bool attacking;
    bool hurting;
    Animation idleAnim;
    Animation walkAnim;
    Animation attackAnim;
    Animation hurtAnim;
    sf::Sprite sprite;
    void isWalking();
    void setup();
    void setCenter();
    void hitBoxUpdate();
    void move(sf::Vector2f moveDir);
    void blokadeMove(sf::Vector2f& moveDir,sf::FloatRect battleArea);
    sf::RectangleShape hitBox;
    sf::RectangleShape weponHitBox;



public:
    Soldier();
    sf::Sprite& getSprite();
    void update(sf::Time deltaTime);
    void setScale(sf::Vector2u size);
    void move(sf::Vector2f moveDir,sf::FloatRect battleArea);
    void stapWalking();
    void isAttacking();
    void stapAttacking();
    void attack();
    void isHurting();
    void stopHurting();
    bool onCollision(sf::FloatRect enemyHitBox);
    sf::FloatRect getWeponHitBox();
    sf::FloatRect getHitBox();
    void getDamage();


};
#endif // SOLDIER_HPP
