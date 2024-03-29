#include "Game.hpp"


void Game::setup(sf::RenderWindow & window)
{
    cam.setSize(window.getSize());
    window.setView(cam.getView());

    player.setTeamSite(1);
    player2.setTeamSite(1);
    greenTeam.addTeammate(player.getTeammate());
    greenTeam.addTeammate(player2.getTeammate());


    map.setWindowSize(window.getSize());
    map.setPosition();
    map.setScale(window.getSize().y);

    player.addSoldier(&bronzeSoldier);

    //smallTower.setHitBox();

    silverKnight.getSprite().setPosition(600,100);
    blackKnight.getSprite().setPosition(500,0);
    bronzeSoldier.getSprite().setPosition(sf::Vector2f(0,0));

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
}

void Game::input(sf::RenderWindow & window)
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
                    break;
                }
                case sf::Keyboard::Num2:
                {
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
}

void Game::logic(sf::RenderWindow & window)
{
    time = clock.getElapsedTime();

    silverKnight.update(time);
    bronzeSoldier.update(time);
    blackKnight.update(time);
    map.getSmallTower()->update(time);

    clock.restart();

    map.getSmallTower()->enemyIsUderTower(&bronzeSoldier.getSprite().getPosition());

    cam.update(bronzeSoldier.getSprite().getPosition(), map.getRectOfBattleArea());
    window.setView(cam.getView());
}

void Game::collision()
{
    blackKnight.onCollision(bronzeSoldier.getWeponHitBox());
    silverKnight.onCollision(bronzeSoldier.getWeponHitBox());
    if(map.getSmallTower()->onCollision(bronzeSoldier.getWeponHitBox()))
    {
        bronzeSoldier.getDamage();
    }
    if(map.getSmallTower()->magicBallOnCollision(bronzeSoldier.getHitBox()))
    {
        bronzeSoldier.getDamage();
    }
}

void Game::draw(sf::RenderWindow & window,Print & print)
{
    window.clear(sf::Color::Black);

    print.addSprite(map.getBase()->getSprite());
    print.addSprite(map.getSmallTower()->getSprite());
    print.addSprite(map.getMediumTower()->getSprite());

    print.addSprite(map.getBackgroundSprite());
    print.draw(&window);

    print.addSprite(bronzeSoldier.getSprite());
    print.addSprite(blackKnight.getSprite());
    print.addSprite(silverKnight.getSprite());

    print.addSprite(map.getSmallTower()->getMagicBallSprite());

    print.sort();
    print.draw(&window);

    print.addSprite(map.getGrassSprite());
    print.draw(&window);

    window.display();
}

void Game::run(sf::RenderWindow & window,Print print)
{
    setup(window);
    while (window.isOpen())
    {
        input(window);
        logic(window);
        collision();
        draw(window,print);
    }
}
