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

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 700), "Hero of Little Warriors");

    Print print;
    Camera cam;
    cam.setSize(window.getSize());
    window.setView(cam.getView());

    Map map;
    map.setWindowSize(window.getSize());
    map.setPosition();

    BronzeSoldier bronzeSoldier;
    BlackKnight blackKnight;
    SilverKnight silverKnight;

    Tower tower;
    Tower tower2;
    tower.loadFromFile("art/Tower/small Tower.png");
    tower2.loadFromFile("art/Tower/high Tower.png");
    tower.setScale(window.getSize().y);
    tower2.setScale(window.getSize().y);
    tower.setPosition(sf::Vector2f(map.getRectOfBattleArea().width/3,map.getRectOfBattleArea().top));
    tower2.setPosition(sf::Vector2f(map.getRectOfBattleArea().width/4,map.getRectOfBattleArea().top));


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
        clock.restart();

        cam.update(bronzeSoldier.getSprite().getPosition(), map.getRectOfBattleArea());
        window.setView(cam.getView());


        window.clear(sf::Color::Black);
        print.addSprite(tower2.getSprite());
        print.addSprite(tower.getSprite());
        print.addSprite(map.getBackgroundSprite());
        print.draw(&window);

        print.addSprite(bronzeSoldier.getSprite());
        print.addSprite(blackKnight.getSprite());
        print.addSprite(silverKnight.getSprite());

        print.sort();
        print.draw(&window);

        print.addSprite(map.getGrassSprite());
        print.draw(&window);

        window.display();
    }

    return 0;
}
