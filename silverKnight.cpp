#include "silverKnight.hpp"

SilverKnight::SilverKnight()
{
    TextureSheet idleSheet;
    TextureSheet walkingSheet;
    TextureSheet attackSheet;

    idleSheet.addTexture("art/Knight/PNG/silver_knight/1 IDLE_000.png");
    idleSheet.addTexture("art/Knight/PNG/silver_knight/1 IDLE_001.png");
    idleSheet.addTexture("art/Knight/PNG/silver_knight/1 IDLE_002.png");
    idleSheet.addTexture("art/Knight/PNG/silver_knight/1 IDLE_003.png");
    idleSheet.addTexture("art/Knight/PNG/silver_knight/1 IDLE_004.png");

    idleAnim.setTextureSheet(idleSheet);

    walkingSheet.addTexture("art/Knight/PNG/silver_knight/2 WALK_000.png");
    walkingSheet.addTexture("art/Knight/PNG/silver_knight/2 WALK_001.png");
    walkingSheet.addTexture("art/Knight/PNG/silver_knight/2 WALK_002.png");
    walkingSheet.addTexture("art/Knight/PNG/silver_knight/2 WALK_003.png");
    walkingSheet.addTexture("art/Knight/PNG/silver_knight/2 WALK_004.png");

    walkAnim.setTextureSheet(walkingSheet);

    attackSheet.addTexture("art/Knight/PNG/silver_knight/5 ATTACK_000.png");
    attackSheet.addTexture("art/Knight/PNG/silver_knight/5 ATTACK_001.png");
    attackSheet.addTexture("art/Knight/PNG/silver_knight/5 ATTACK_002.png");
    attackSheet.addTexture("art/Knight/PNG/silver_knight/5 ATTACK_003.png");
    attackSheet.addTexture("art/Knight/PNG/silver_knight/5 ATTACK_004.png");

    attackAnim.setTextureSheet(attackSheet);


    setup();
}
