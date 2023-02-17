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
    isWalking();
    moveDir = sf::Vector2f(moveDir.x*speed,moveDir.y*speed);

    sprite.move(moveDir);

    if(moveDir.x >0)
    {
        sprite.setScale(sprite.getScale().y,sprite.getScale().y);
    }
    else if(moveDir.x < 0)
    {
        //on scale X is included y because he return always positive number and
        sprite.setScale(-sprite.getScale().y,sprite.getScale().y);
    }
}

void Soldier::move(sf::Vector2f moveDir,sf::FloatRect battleArea)
{
    blokadeMove(moveDir,battleArea);
    move(moveDir);
}

void Soldier::blokadeMove(sf::Vector2f& moveDir,sf::FloatRect battleArea)
{
    if(battleArea.top > hitBox.getGlobalBounds().top+hitBox.getGlobalBounds().height&& moveDir.y < 0)
    {
        moveDir.y = 0;
    }
    else if(battleArea.top+battleArea.height < hitBox.getGlobalBounds().top+hitBox.getGlobalBounds().height&& moveDir.y > 0)
    {
        moveDir.y = 0;
    }
    else if(battleArea.left > hitBox.getGlobalBounds().left&& moveDir.x < 0)
    {
        moveDir.x = 0;
    }
    else if(battleArea.left+battleArea.width < hitBox.getGlobalBounds().left+hitBox.getGlobalBounds().width&& moveDir.x > 0)
    {
        moveDir.x = 0;
    }
}

void Soldier::attack()
{
    if(hurting)
    {
        stapAttacking();
    }
    else
    {
        isAttacking();
        stapWalking();
    }
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
    setCenter();

}

void Soldier::setCenter()
{
    sprite.setOrigin(sprite.getLocalBounds().width/2,sprite.getLocalBounds().height/2);
    hitBox.setOrigin(hitBox.getLocalBounds().width/2,sprite.getLocalBounds().height/2);
    weponHitBox.setOrigin(weponHitBox.getLocalBounds().width/2,weponHitBox.getLocalBounds().height/2);
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

bool Soldier::onCollision(sf::FloatRect enemyHitBox)
{
    if(hitBox.getGlobalBounds().intersects(enemyHitBox))
    {
         isHurting();
         //std::cout << "is Collsion" << std::endl;

        return true;
    }
    else
    {
        //std::cout << "not is Collsion" << std::endl;

        return false;

    }
}

sf::FloatRect Soldier::getHitBox()
{
    return hitBox.getGlobalBounds();
}


void Soldier::setScale(sf::Vector2u size)
{
    float scale;
    scale = size.y/5;
    scale = scale/520;
    sprite.setScale(scale,scale);
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

void Soldier::getDamage()
{

}


