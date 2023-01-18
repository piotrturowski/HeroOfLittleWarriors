#include "Soldier.hpp"



Soldier::Soldier()
: hitBox(sf::Vector2f(270,300))
, weponHitBox(sf::Vector2f(200,200))
{
    setup();
    hitBoxUpdate();

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
    hitBoxUpdate();
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

void Soldier::move(sf::Vector2f moveDir,sf::FloatRect battleArea)
{
    if(battleArea.top < sprite.getPosition().y&&battleArea.top+battleArea.height > sprite.getPosition().y)
    {
        if(battleArea.left < sprite.getPosition().x&& battleArea.left+battleArea.width > sprite.getPosition().x)
        {
            move(moveDir);
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
    sprite.setOrigin(sprite.getGlobalBounds().width,sprite.getGlobalBounds().height);
    hitBox.setOrigin(hitBox.getGlobalBounds().width,sprite.getGlobalBounds().height);
    weponHitBox.setOrigin(weponHitBox.getGlobalBounds().width,weponHitBox.getGlobalBounds().height);
}

void Soldier::isHurting()
{
    hurting = true;
}

void Soldier::stopHurting()
{
    hurting = false;
}
sf::FloatRect Soldier::getWeponHitBox()
{
    if(attacking)
    {
        return weponHitBox.getGlobalBounds();
    }
    return sf::FloatRect(0,0,0,0);
}

void Soldier::onCollision(sf::FloatRect enemyHitBox)
{
    if(hitBox.getGlobalBounds().intersects(enemyHitBox))
    {
         isHurting();
         //std::cout << "is Collsion" << std::endl;
    }
    else
    {
        //std::cout << "not is Collsion" << std::endl;


    }
}




void Soldier::hitBoxUpdate()
{
    hitBox.setPosition(sprite.getPosition());
    hitBox.move(-hitBox.getOrigin().x/2*hitBox.getScale().x,hitBox.getOrigin().y*hitBox.getScale().y);
    hitBox.setScale(sprite.getScale());

    weponHitBox.setPosition(sprite.getPosition());

    weponHitBox.move(hitBox.getOrigin().x*hitBox.getScale().x,0);
    weponHitBox.setScale(sprite.getScale());
    weponHitBox.setFillColor(sf::Color::Red);

}
