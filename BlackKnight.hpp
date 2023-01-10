 #ifndef BLACKKNIGHT_HPP
 #define BLACKKNIGHT_HPP
 #include <SFML/Graphics.hpp>
 #include "Animation.hpp"

 class BlackKnight
 {
    public:
    BlackKnight();
    sf::Sprite& getSprite();
    void update(sf::Time deltaTime);
    void move(sf::Vector2f moveDir);
    void isWalking();
    void stapWalking();

    private:
    bool walking;
    Animation idle;
    Animation walk;
    float speed;
    sf::Sprite sprite;
 };
 #endif // BLACKKNIGHT_HPP
