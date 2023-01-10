#include "BronzeSoldier.hpp"

BronzeSoldier::BronzeSoldier()
{
    TextureSheet txtSheet;
    txtSheet.addTexture("art/Knight/PNG/bronze_knight/1 IDLE_000.png");
    txtSheet.addTexture("art/Knight/PNG/bronze_knight/1 IDLE_001.png");
    txtSheet.addTexture("art/Knight/PNG/bronze_knight/1 IDLE_002.png");
    txtSheet.addTexture("art/Knight/PNG/bronze_knight/1 IDLE_003.png");
    txtSheet.addTexture("art/Knight/PNG/bronze_knight/1 IDLE_004.png");


    TextureSheet txsheet;

    txsheet.addTexture("art/Knight/PNG/bronze_knight/2 WALK_000.png");
    txsheet.addTexture("art/Knight/PNG/bronze_knight/2 WALK_001.png");
    txsheet.addTexture("art/Knight/PNG/bronze_knight/2 WALK_002.png");
    txsheet.addTexture("art/Knight/PNG/bronze_knight/2 WALK_003.png");
    txsheet.addTexture("art/Knight/PNG/bronze_knight/2 WALK_004.png");

    TextureSheet attackSheet;

    attackSheet.addTexture("art/Knight/PNG/bronze_knight/5 ATTACK_000.png");
    attackSheet.addTexture("art/Knight/PNG/bronze_knight/5 ATTACK_001.png");
    attackSheet.addTexture("art/Knight/PNG/bronze_knight/5 ATTACK_002.png");
    attackSheet.addTexture("art/Knight/PNG/bronze_knight/5 ATTACK_003.png");
    attackSheet.addTexture("art/Knight/PNG/bronze_knight/5 ATTACK_004.png");



    walking = false;
    attacking = false;
    speed = 4;


    idleAnim.setTextureSheet(txtSheet);
    idleAnim.setSwitchTime(0.1);

    walkAnim.setTextureSheet(txsheet);
    walkAnim.setSwitchTime(0.1);

    attackAnim.setTextureSheet(attackSheet);
    attackAnim.setSwitchTime(0.1);

    sprite.setTexture(idleAnim.getTexture());

    sprite.setScale(0.4,0.4);

    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);
}

sf::Sprite& BronzeSoldier::getSprite()
{
    return sprite;
}

void BronzeSoldier::update(sf::Time deltaTime)
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
    else
    {
        idleAnim.update(deltaTime);
        sprite.setTexture(idleAnim.getTexture(),true);
    }

}

void BronzeSoldier::isWalking()
{
    walking = true;
}
void BronzeSoldier::stapWalking()
{
    walking = false;
}

void BronzeSoldier::isAttacking()
{
    attacking = true;
}
void BronzeSoldier::stapAttacking()
{
    attacking = false;
}

void BronzeSoldier::move(sf::Vector2f moveDir)
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

void BronzeSoldier::attack()
{
    isAttacking();

}


