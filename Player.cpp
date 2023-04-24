#include "Player.hpp"

Player::Player()
{
    soldier=NULL;
}
void Player::addSoldier(Soldier* soldier)
{
    if(pointerSoldierIsEmpty())
    {
        this->soldier = soldier;
    }
}

bool Player::getTeammateSite()
{
    teammate.getTeamSite();
}

void Player::setTeamSite(bool teamSite)
{
    teammate.setTeamSite(teamSite);
}

Teammate Player::getTeammate()
{
    return teammate;
}

Soldier Player::getSoldier()
{
    return *soldier;
}

bool Player::pointerSoldierIsEmpty()
{
    if(soldier==NULL)
    {
        return true;
    }
    return false;
}


