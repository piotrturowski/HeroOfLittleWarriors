#include "Phisics.hpp"
float phisics::distanceBetweenTwoPoints(sf::Vector2f point1, sf::Vector2f point2)
{
    float distance = (pow(point1.x-point2.x,2))+(pow(point1.y-point2.y,2));
    return distance;
}
