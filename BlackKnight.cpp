#include "BlackKnight.hpp"

BlackKnight::BlackKnight()
{
    TextureSheet txtSheet;
    txtSheet.addTexture("art/Knight/PNG/black_knight/1 IDLE_000.png");
    txtSheet.addTexture("art/Knight/PNG/black_knight/1 IDLE_001.png");
    txtSheet.addTexture("art/Knight/PNG/black_knight/1 IDLE_002.png");
    txtSheet.addTexture("art/Knight/PNG/black_knight/1 IDLE_003.png");
    txtSheet.addTexture("art/Knight/PNG/black_knight/1 IDLE_004.png");


    TextureSheet txsheet;

    txsheet.addTexture("art/Knight/PNG/black_knight/2 WALK_000.png");
    txsheet.addTexture("art/Knight/PNG/black_knight/2 WALK_001.png");
    txsheet.addTexture("art/Knight/PNG/black_knight/2 WALK_002.png");
    txsheet.addTexture("art/Knight/PNG/black_knight/2 WALK_003.png");
    txsheet.addTexture("art/Knight/PNG/black_knight/2 WALK_004.png");


    walking = false;
    speed = 4;


    idle.setTextureSheet(txtSheet);
    idle.setSwitchTime(0.1);

    walk.setTextureSheet(txsheet);
    walk.setSwitchTime(0.1);

    sprite.setTexture(idle.getTexture());

    sprite.setScale(0.4,0.4);

    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);
}

sf::Sprite& BlackKnight::getSprite()
{
    return sprite;
}

void BlackKnight::update(sf::Time deltaTime)
{

    if(walking)
    {
        walk.update(deltaTime);
        sprite.setTexture(walk.getTexture(),true);
    }
    else
    {
        idle.update(deltaTime);
        sprite.setTexture(idle.getTexture(),true);
    }
}

void BlackKnight::isWalking()
{
    walking = true;
}
void BlackKnight::stapWalking()
{
    walking = false;
}

void BlackKnight::move(sf::Vector2f moveDir)
{
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


