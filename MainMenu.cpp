#include "MainMenu.hpp"

void MainMenu::setup(sf::View & view, sf::Vector2u windowSize)
{
    backgroundSetup(view.getSize());
    buttonSetup(windowSize);
    logoSetup(windowSize);
}

void MainMenu::input(sf::RenderWindow& window,sf::View& view)
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
                        view.zoom(2);
                        break;
                    }
                    case sf::Keyboard::O:
                    {
                        view.zoom(0.5);
                        break;
                    }
                    case sf::Keyboard::F1:
                    {
                        break;
                    }
                }
            }
        }
}

void MainMenu::logic(sf::RenderWindow& window,sf::View& view)
{
    window.setView(view);
    animatedBackground.move();
}

void MainMenu::collision(sf::RenderWindow& window,Print& print, Game& game)
{
    if(startButton.isPressed(&window))
    {
        game.run(window,print);
    }
    if(settings.isPressed(&window))
    {

    }
    if(exit.isPressed(&window))
    {
        window.close();
    }
}

void MainMenu::draw(sf::RenderWindow& window)
{
    window.clear(sf::Color::Black);

    drawBackground(window);
    drawLogo(window);
    drawButtons(window);

    window.display();
}




void MainMenu::backgroundSetup(sf::Vector2f viewSize)
{
    animatedBackground.loadImage("art/Backgrounds/game_Background_3/game_Background_3.png");
    animatedBackground.setWindowSize(viewSize);
}

void MainMenu::buttonSetup(sf::Vector2u windowSize)
{
    startButton.setNameButton("Start");
    settings.setNameButton("Settings");
    exit.setNameButton("Exit");

    startButton.setScale(0.7);
    settings.setScale(0.7);
    exit.setScale(0.7);

    startButton.setPosition(windowSize.x/2,windowSize.y*0.8);
    settings.setPosition(windowSize.x/2, windowSize.y);
    exit.setPosition(windowSize.x/2, windowSize.y*1.2);
}

void MainMenu::logoSetup(sf::Vector2u windowSize)
{
    logo.setTexture("art/Logo/Logo.png");
    logo.getSprite().setOrigin(logo.getSprite().getGlobalBounds().width/2,logo.getSprite().getGlobalBounds().height/2);
    logo.getSprite().setScale(0.5,0.5);
    logo.getSprite().setPosition(windowSize.x/2,windowSize.y*0.4);
}

void MainMenu::drawBackground(sf::RenderWindow& window)
{
    window.draw(animatedBackground.getSprite());
    window.draw(animatedBackground.getSecondSprite());
}

void MainMenu::drawButtons(sf::RenderWindow& window)
{
   window.draw(startButton.getSprite());
    window.draw(settings.getSprite());
    window.draw(exit.getSprite());
}

void MainMenu::drawLogo(sf::RenderWindow& window)
{
    window.draw(logo.getSprite());
}





void MainMenu::loop(sf::RenderWindow & window,sf::View & view,Game& game, Print& print)
{
    while(window.isOpen())
    {
        input(window,view);
        logic(window,view);
        collision(window,print,game);
        draw(window);
    }
}

void MainMenu::run()
{
    Game game;
    sf::RenderWindow window(sf::VideoMode(1000, 700), "Hero of Little Warriors");\
    Print print;
    sf::View view;
    window.setView(view);

    setup(view,window.getSize());
    loop(window,view,game,print);
}
