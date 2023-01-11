#include "BronzeSoldier.hpp"

BronzeSoldier::BronzeSoldier()
{
    TextureSheet idleSheet;
    TextureSheet walkSheet;
    TextureSheet attackSheet;

    idleSheet.addTexture("art/Knight/PNG/bronze_knight/1 IDLE_000.png");
    idleSheet.addTexture("art/Knight/PNG/bronze_knight/1 IDLE_001.png");
    idleSheet.addTexture("art/Knight/PNG/bronze_knight/1 IDLE_002.png");
    idleSheet.addTexture("art/Knight/PNG/bronze_knight/1 IDLE_003.png");
    idleSheet.addTexture("art/Knight/PNG/bronze_knight/1 IDLE_004.png");

    walkSheet.addTexture("art/Knight/PNG/bronze_knight/2 WALK_000.png");
    walkSheet.addTexture("art/Knight/PNG/bronze_knight/2 WALK_001.png");
    walkSheet.addTexture("art/Knight/PNG/bronze_knight/2 WALK_002.png");
    walkSheet.addTexture("art/Knight/PNG/bronze_knight/2 WALK_003.png");
    walkSheet.addTexture("art/Knight/PNG/bronze_knight/2 WALK_004.png");

    attackSheet.addTexture("art/Knight/PNG/bronze_knight/5 ATTACK_000.png");
    attackSheet.addTexture("art/Knight/PNG/bronze_knight/5 ATTACK_001.png");
    attackSheet.addTexture("art/Knight/PNG/bronze_knight/5 ATTACK_002.png");
    attackSheet.addTexture("art/Knight/PNG/bronze_knight/5 ATTACK_003.png");
    attackSheet.addTexture("art/Knight/PNG/bronze_knight/5 ATTACK_004.png");

    idleAnim.setTextureSheet(idleSheet);
    walkAnim.setTextureSheet(walkSheet);
    attackAnim.setTextureSheet(attackSheet);

    setup();
}
