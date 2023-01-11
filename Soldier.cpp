#include "Soldier.hpp"

Soldier::Soldier()
{
    setup();
}

sf::Sprite& Soldier::getSprite()
{
    return sprite;
}

void Soldier::update(sf::Time deltaTime)
{
    if(walking)
    {
        walkAnim.update(deltaTime);
        sprite.setTexture(walkAnim.getTexture(),true);
    }
    else if(attacking)
    {
        attackAnim.update(deltaTime);
        sprite.setTexture(attackAnim.getTexture(),true);
    }
    else if(hurting)
    {
        hurtAnim.update(deltaTime);
        sprite.setTexture(hurtAnim.getTexture(),true);
        if(hurtAnim.getTextureSheet().isEndOfSheet())
        {
            stopHurting();
        }
    }
    else
    {
        idleAnim.update(deltaTime);
        sprite.setTexture(idleAnim.getTexture(),true);
    }
    setCenter();
}

void Soldier::isWalking()
{
    walking = true;
}

void Soldier::stapWalking()
{
    walking = false;
}

void Soldier::isAttacking()
{
    attacking = true;
}
void Soldier::stapAttacking()
{
    attacking = false;
}

void Soldier::move(sf::Vector2f moveDir)
{
    if(moveDir.y != 0 || moveDir.x != 0)
    {
        isWalking();
        moveDir = sf::Vector2f(moveDir.x*speed,moveDir.y*speed);
        sprite.move(moveDir);

        if(moveDir.x >0)
        {
            sprite.setScale(0.4,0.4);
        }
        else if(moveDir.x < 0)
        {
            sprite.setScale(-0.4,0.4);
        }
    }
}

void Soldier::attack()
{
    isAttacking();

}

void Soldier::setup()
{
    walking = false;
    attacking = false;
    hurting = false;
    speed = 4;

    idleAnim.setSwitchTime(0.1);
    walkAnim.setSwitchTime(0.1);
    attackAnim.setSwitchTime(0.1);
    hurtAnim.setSwitchTime(0.1);

    sprite.setTexture(idleAnim.getTexture());
    sprite.setScale(0.4,0.4);
    setCenter();
}

void Soldier::setCenter()
{
    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);
}

void Soldier::isHurting()
{
    hurting = true;
}

void Soldier::stopHurting()
{
    hurting = false;
}
