#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Teammate.hpp"
#include "Soldier.hpp"


class Player
{
private:
    Soldier* soldier;
    Teammate teammate;
    bool pointerSoldierIsEmpty();
public:
    Player();
    void addSoldier(Soldier* soldier);
    bool getTeammateSite();
    void setTeamSite(bool teamSite);
    Soldier getSoldier();
    Teammate getTeammate();
};
#endif // PLAYER_HPP
