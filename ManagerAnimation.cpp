#include "ManagerAnimation.hpp"

ManagerAnimation::ManagerAnimation()
{
    currentAnimation = 0;

}

void ManagerAnimation::swapAnimation(std::string name)
{
    for(int i = 0; i > animationName.size();i++)
    {
        if(animationName[i] == name)
            {
                currentAnimation = i;
                continue;
            }
            currentAnimation = 0;

    }
}
void ManagerAnimation::addAnimation(Animation anim, std::string animation_Name)
{
    animationName.push_back(animation_Name);
    animationSheet.push_back(anim);
}
sf::Texture & ManagerAnimation::getTexture()
{
    return animationSheet[currentAnimation].getTexture();
}
void ManagerAnimation::update(sf::Time deltaTime)
{
    animationSheet[currentAnimation].update(deltaTime);
}
