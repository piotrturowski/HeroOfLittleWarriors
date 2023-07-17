#include <SFML/Graphics.hpp>
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

int Teammate::teammatesCounter = 0;

int main()
{
    Button startButton;
    startButton.setNameButton("Start");

    startButton.block();

    sf::RenderWindow window(sf::VideoMode(1000, 700), "Hero of Little Warriors");

    Print print;
    Camera cam;
    cam.setSize(window.getSize());
    window.setView(cam.getView());
    {

    Team greenTeam;
    Player player, player2;
    player.setTeamSite(1);
    player2.setTeamSite(1);
    greenTeam.addTeammate(player.getTeammate());
    greenTeam.addTeammate(player2.getTeammate());



    Map map;
    map.setWindowSize(window.getSize());
    map.setPosition();

    BronzeSoldier bronzeSoldier;
    BlackKnight blackKnight;
    SilverKnight silverKnight;

    player.addSoldier(&bronzeSoldier);

    map.setScale(window.getSize().y);


    //smallTower.setHitBox();

    silverKnight.getSprite().setPosition(600,100);
    blackKnight.getSprite().setPosition(500,0);
    bronzeSoldier.getSprite().setPosition(sf::Vector2f(0,0));


    sf::Clock clock;
    sf::Time time;
    clock.restart();
    time = clock.getElapsedTime();

    bronzeSoldier.setScale(window.getSize());
    blackKnight.setScale(window.getSize());
    silverKnight.setScale(window.getSize());

    greenTeam.addTower(*map.getMediumTower());
    greenTeam.addTower(*map.getMediumTower());
    greenTeam.addBase(*map.getBase());

    greenTeam.showTeamSquad();

    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                switch(event.key.code)
                {
                    case sf::Keyboard::Escape:
                    {
                        window.close();
                        break;
                    }
                    case sf::Keyboard::P:
                        {
                            cam.getView().zoom(2);
                            break;
                        }
                    case sf::Keyboard::O:
                        {
                            cam.getView().zoom(0.5);
                            break;
                        }
                    case sf::Keyboard::F1:
                        {

                            break;
                        }
                    case sf::Keyboard::Num1:
                        {
                            startButton.unlock();
                            break;
                        }
                    case sf::Keyboard::Num2:
                        {
                            startButton.block();
                            break;
                        }

                }
            }
            else if(event.type == sf::Event::KeyReleased)
            {
                switch(event.key.code)
                {
                    case sf::Keyboard::J:
                    {
                        bronzeSoldier.stapAttacking();
                        break;
                    }
                case sf::Keyboard::A:
                    {
                        bronzeSoldier.stapWalking();
                        break;
                    }
                case sf::Keyboard::D:
                    {
                        bronzeSoldier.stapWalking();
                        break;
                    }
                case sf::Keyboard::W:
                    {
                        bronzeSoldier.stapWalking();
                        break;
                    }
                case sf::Keyboard::S:
                    {
                        bronzeSoldier.stapWalking();
                        break;
                    }
                case sf::Keyboard::Up:
                    {
                        blackKnight.stapWalking();
                        break;
                    }
                case sf::Keyboard::Down:
                    {
                        blackKnight.stapWalking();
                        break;
                    }
                case sf::Keyboard::Left:
                    {
                        blackKnight.stapWalking();
                        break;
                    }
                case sf::Keyboard::Right:
                    {
                        blackKnight.stapWalking();
                        break;
                    }
                }

            }
        }
        time = clock.getElapsedTime();
        blackKnight.onCollision(bronzeSoldier.getWeponHitBox());
        silverKnight.onCollision(bronzeSoldier.getWeponHitBox());

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::J))
        {
            bronzeSoldier.attack();
        }
        else
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                bronzeSoldier.move(sf::Vector2f(1,0),map.getRectOfBattleArea());
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                bronzeSoldier.move(sf::Vector2f(-1,0),map.getRectOfBattleArea());
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                bronzeSoldier.move(sf::Vector2f(0,-1),map.getRectOfBattleArea());
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                bronzeSoldier.move(sf::Vector2f(0,1),map.getRectOfBattleArea());
            }
        }


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            blackKnight.move(sf::Vector2f(1,0),map.getRectOfBattleArea());
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            blackKnight.move(sf::Vector2f(-1,0),map.getRectOfBattleArea());
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            blackKnight.move(sf::Vector2f(0,-1),map.getRectOfBattleArea());
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            blackKnight.move(sf::Vector2f(0,1),map.getRectOfBattleArea());
        }



        silverKnight.update(time);
        bronzeSoldier.update(time);
        blackKnight.update(time);
        map.getSmallTower()->update(time);
        clock.restart();

        cam.update(bronzeSoldier.getSprite().getPosition(), map.getRectOfBattleArea());
        window.setView(cam.getView());

        if(map.getSmallTower()->onCollision(bronzeSoldier.getWeponHitBox()))
        {
            bronzeSoldier.getDamage();
        }
        if(map.getSmallTower()->magicBallOnCollision(bronzeSoldier.getHitBox()))
        {
            bronzeSoldier.getDamage();
        }

        startButton.isPressed(&window);
        map.getSmallTower()->enemyIsUderTower(&bronzeSoldier.getSprite().getPosition());

        window.clear(sf::Color::Black);

        print.addSprite(map.getBase()->getSprite());
        print.addSprite(map.getSmallTower()->getSprite());
        print.addSprite(map.getMediumTower()->getSprite());

        print.addSprite(map.getBackgroundSprite());
        print.draw(&window);

        print.addSprite(bronzeSoldier.getSprite());
        print.addSprite(blackKnight.getSprite());
        print.addSprite(silverKnight.getSprite());

        print.addSprite(startButton.getSprite());

        print.addSprite(map.getSmallTower()->getMagicBallSprite());

        print.sort();
        print.draw(&window);

        print.addSprite(map.getGrassSprite());
        print.draw(&window);


        window.display();
    }
    }
    return 0;
}
