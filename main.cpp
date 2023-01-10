#include <SFML/Graphics.hpp>
#include "Soldier.hpp"
#include "textureSheet.hpp"
#include "Animation.hpp"
#include "BronzeSoldier.hpp"
#include "BlackKnight.hpp"
#include "silverKnight.hpp"



int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");

    BronzeSoldier bronzeSoldier;
    BlackKnight blackKnight;
    SilverKnight silverKnight;

    silverKnight.getSprite().setPosition(1000,100);
    blackKnight.getSprite().setPosition(600,600);
    bronzeSoldier.getSprite().setPosition(sf::Vector2f(100,100));


    sf::Clock clock;
    sf::Time time;
    clock.restart();
    sf::Vector2f s;
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

                case sf::Keyboard::Up:
                    {
                        blackKnight.isWalking();
                        break;
                    }
                case sf::Keyboard::Down:
                    {
                        blackKnight.isWalking();
                        break;
                    }
                case sf::Keyboard::Left:
                    {
                        blackKnight.isWalking();
                        break;
                    }
                case sf::Keyboard::Right:
                    {
                        blackKnight.isWalking();
                        break;
                    }
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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::J))
        {
            bronzeSoldier.attack();
        }
        else
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                bronzeSoldier.move(sf::Vector2f(1,0));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                bronzeSoldier.move(sf::Vector2f(-1,0));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                bronzeSoldier.move(sf::Vector2f(0,-1));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                bronzeSoldier.move(sf::Vector2f(0,1));
            }
        }


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            blackKnight.move(sf::Vector2f(1,0));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            blackKnight.move(sf::Vector2f(-1,0));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            blackKnight.move(sf::Vector2f(0,-1));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            blackKnight.move(sf::Vector2f(0,1));
        }

        silverKnight.update(time);
        bronzeSoldier.update(time);
        blackKnight.update(time);
        clock.restart();

        window.clear(sf::Color::Cyan);

        window.draw(bronzeSoldier.getSprite());
        window.draw(blackKnight.getSprite());
        window.draw(silverKnight.getSprite());

        window.display();
    }

    return 0;
}
