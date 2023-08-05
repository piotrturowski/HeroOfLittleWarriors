#ifndef GAME_HPP
#define GAME_HPP

#include "Soldier.hpp"
#include "textureSheet.hpp"
#include "Animation.hpp"
#include "BronzeSoldier.hpp"
#include "BlackKnight.hpp"
#include "silverKnight.hpp"
#include "HitBox.hpp"
#include "Background.hpp"
#include "Map.hpp"
#include "Camera.hpp"
#include "Print.hpp"
#include "Tower.hpp"
#include "SmallTower.hpp"
#include "MediumTower.hpp"
#include "Base.hpp"
#include "MagicBall.hpp"
#include "Team.hpp"
#include "Player.hpp"
#include "Button.hpp"




class Game
{
public:
    Camera cam;
    Team greenTeam;
    Player player, player2;
    Map map;
    BronzeSoldier bronzeSoldier;
    BlackKnight blackKnight;
    SilverKnight silverKnight;
    sf::Clock clock;
    sf::Time time;


    Game();
    void run(sf::RenderWindow & window, Print print);
};
#endif // GAME_HPP
