#include <SFML/Graphics.hpp>
#include "button.hpp"
#include "Game.hpp"
#include "Sprite.hpp"
#include "AnimatedBackground.hpp"

#ifndef MAINMENU_HPP
#define MAINMENU_HPP



class MainMenu
{
    Button startButton, settings, exit;
    AnimatedBackground animatedBackground;
    Sprite logo;

    void setup(sf::View & view, sf::Vector2u windowSize);
    void loop(sf::RenderWindow & window,sf::View &view,Game& game,Print& print);
    void input(sf::RenderWindow& window,sf::View& view);
    void logic(sf::RenderWindow& window,sf::View& view);
    void collision(sf::RenderWindow& window,Print& print, Game& game);
    void draw(sf::RenderWindow& window);

    void backgroundSetup(sf::Vector2f viewSize);
    void buttonSetup(sf::Vector2u windowSize);
    void logoSetup(sf::Vector2u windowSize);

    void drawBackground(sf::RenderWindow& window);
    void drawLogo(sf::RenderWindow& window);
    void drawButtons(sf::RenderWindow& window);
public:
    void run();
};
#endif // MAINMENU_HPP
