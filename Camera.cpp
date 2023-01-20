#include "Camera.hpp"

void Camera::update(sf::Vector2f pos,sf::FloatRect battleArea)
{
    float halfCamWeidth = view.getSize().x/2;

    if(battleArea.left+halfCamWeidth < pos.x && battleArea.left+battleArea.width-halfCamWeidth > pos.x)
    {
        view.setCenter(pos.x,0);
    }
}

void Camera::setSize(sf::Vector2u size)
{
    view.setSize(sf::Vector2f(size.x,size.y));
}

sf::View & Camera::getView()
{
    return view;
}
