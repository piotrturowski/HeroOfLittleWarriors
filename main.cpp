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


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 700), "Hero of Little Warriors");

    sf::View view;
    view.setSize(window.getSize().x,window.getSize().y);
    window.setView(view);

    Map map;
    map.setWindowSize(window.getSize());
    map.setPosition();

    Background grass;
    grass.loadBackground("art/Backgrounds/game_background_2/layers/front_decor.png");

    grass.setWindowSize(window.getSize());
    BronzeSoldier bronzeSoldier;
    BlackKnight blackKnight;
    SilverKnight silverKnight;




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

        view.setCenter(bronzeSoldier.getSprite().getPosition());
        window.setView(view);

        window.clear(sf::Color::Cyan);

        std::vector <sf::Sprite> sprite = map.getSprite();
        for(int i = 0; i <= 3; i++)
        {

            window.draw(sprite[i]);
        }


        window.draw(bronzeSoldier.getSprite());
        window.draw(blackKnight.getSprite());
        window.draw(silverKnight.getSprite());



        window.draw(grass.getSprite());




        window.display();
    }

    return 0;
}
