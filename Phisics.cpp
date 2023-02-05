#include "Phisics.hpp"
float phisics::distanceBetweenTwoPoints(sf::Vector2f point1, sf::Vector2f point2)
{
    sf::Vector2f pos(point2.x-point1.x,point2.y-point1.y);
    float distance = sqrt(pow(pos.x,2)+pow(pos.y,2));
    return distance;
}
