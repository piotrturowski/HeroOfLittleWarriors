#ifndef TEAM_HPP
#define TEAM_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Teammate.hpp"
#include "Tower.hpp"
#include "Base.hpp"


class Team
{
private:
    static bool TeamID;
    std::vector <Teammate*> teamSquad;
    std::vector <Tower*> towers;
    Base * base;
    bool basePointerIsEmpty();
    void writeInConsole(std::string word);
public:
    Team();
    void addTower(Tower tower);
    void addTeammate(Teammate teammate);
    bool addBase(Base base);
    void showTeamSquad();
};
#endif // TEAM_HPP
