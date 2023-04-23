#include "Player.hpp"

Player::Player()
{

}
void Player::addSoldier(Soldier* soldier)
{
    soldier = soldier;
}

bool Player::getTeammateSite()
{
    teammate.getTeamSite();
}

void Player::setTeamSite(bool teamSite)
{
    teammate.setTeamSite(teamSite);
}

const Teammate Player::getTeammate()
{
    return teammate;
}

const Soldier Player::getSoldier()
{
    return *soldier;
}
