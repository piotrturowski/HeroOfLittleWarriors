#include "BlackKnight.hpp"

BlackKnight::BlackKnight()
{
    TextureSheet idleSheet;
    TextureSheet walkSheet;
    TextureSheet attackSheet;
    TextureSheet hurtSheet;

    idleSheet.addTexture("art/Knight/PNG/black_knight/1 IDLE_000.png");
    idleSheet.addTexture("art/Knight/PNG/black_knight/1 IDLE_001.png");
    idleSheet.addTexture("art/Knight/PNG/black_knight/1 IDLE_002.png");
    idleSheet.addTexture("art/Knight/PNG/black_knight/1 IDLE_003.png");
    idleSheet.addTexture("art/Knight/PNG/black_knight/1 IDLE_004.png");

    walkSheet.addTexture("art/Knight/PNG/black_knight/2 WALK_000.png");
    walkSheet.addTexture("art/Knight/PNG/black_knight/2 WALK_001.png");
    walkSheet.addTexture("art/Knight/PNG/black_knight/2 WALK_002.png");
    walkSheet.addTexture("art/Knight/PNG/black_knight/2 WALK_003.png");
    walkSheet.addTexture("art/Knight/PNG/black_knight/2 WALK_004.png");

    attackSheet.addTexture("art/Knight/PNG/black_knight/5 ATTACK_000.png");
    attackSheet.addTexture("art/Knight/PNG/black_knight/5 ATTACK_001.png");
    attackSheet.addTexture("art/Knight/PNG/black_knight/5 ATTACK_002.png");
    attackSheet.addTexture("art/Knight/PNG/black_knight/5 ATTACK_003.png");
    attackSheet.addTexture("art/Knight/PNG/black_knight/5 ATTACK_004.png");

    hurtSheet.addTexture("art/Knight/PNG/black_knight/6 HURT_000.png");
    hurtSheet.addTexture("art/Knight/PNG/black_knight/6 HURT_001.png");
    hurtSheet.addTexture("art/Knight/PNG/black_knight/6 HURT_002.png");
    hurtSheet.addTexture("art/Knight/PNG/black_knight/6 HURT_003.png");
    hurtSheet.addTexture("art/Knight/PNG/black_knight/6 HURT_004.png");



    idleAnim.setTextureSheet(idleSheet);
    walkAnim.setTextureSheet(walkSheet);
    attackAnim.setTextureSheet(attackSheet);
    hurtAnim.setTextureSheet(hurtSheet);
    setup();

    weponHitBox.setSize(sf::Vector2f(730,300));

}
