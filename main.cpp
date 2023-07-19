#include <SFML/Graphics.hpp>
#include "button.hpp"
#include "Game.hpp"
#include "Sprite.hpp"

int Teammate::teammatesCounter = 0;

int main()
{
    Button startButton, settings, exit;

    startButton.setNameButton("Start");
    settings.setNameButton("Settings");
    exit.setNameButton("Exit");




    startButton.setScale(0.7);
    settings.setScale(0.7);
    exit.setScale(0.7);

    Game game;


    sf::RenderWindow window(sf::VideoMode(1000, 700), "Hero of Little Warriors");
    Print print;
    sf::View view;
    window.setView(view);

    Sprite logo("art/Logo/Logo.png");

    logo.getSprite().setOrigin(logo.getSprite().getGlobalBounds().width/2,logo.getSprite().getGlobalBounds().height/2);
    logo.getSprite().setScale(0.5,0.5);
    logo.getSprite().setPosition(window.getSize().x/2,window.getSize().y*0.4);


    startButton.setPosition(window.getSize().x/2,window.getSize().y*0.8);
    settings.setPosition(window.getSize().x/2, window.getSize().y);
    exit.setPosition(window.getSize().x/2, window.getSize().y*1.2);

    while(window.isOpen())
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

                }
            }
        }
        window.setView(view);
        if(startButton.isPressed(&window))
        {
            game.loop(window,print);
        }
        if(settings.isPressed(&window))
        {

        }
        if(exit.isPressed(&window))
        {
            window.close();
        }

        window.clear(sf::Color::Black);


        window.draw(logo.getSprite());
        window.draw(startButton.getSprite());
        window.draw(settings.getSprite());
        window.draw(exit.getSprite());

        window.display();
    }
    return 0;
}
