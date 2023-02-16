#ifndef TOWER_HPP
#define TOWER_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include "GameObject.hpp"
#include "MagicBall.hpp"
#include "Phisics.hpp"


class Tower : public GameObject
{
protected:
    MagicBall magicBallOriginal;
    std::vector <MagicBall> magicBall;
    float range;
    void spawnMagicBall();
    sf::Time spawnBallTime;
    sf::Time totalTime;
    bool spawnCooldown;
    void checkCooldownIsDown(sf::Time deltaTime);
public:
    Tower();
    void setHitBox();
    void setPosition(sf::Vector2f pos);
    bool onCollision(sf::FloatRect enemyHitBox);
    sf::RectangleShape hitBox;
    void setOrigin();
    void enemyIsUderTower(const sf::Vector2f *heroPos);
    std::vector <sf::Sprite> getMagicBallSprite();
    void update(sf::Time deltaTime);
    bool magicBallOnCollision(sf::FloatRect enemyHitBox);




};
#endif // TOWER_HPP
