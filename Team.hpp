#ifndef TEAM_HPP
#define TEAM_HPP
#include <iostream>
#include <vector>
#include "Teammate.hpp"


class Team
{
private:
    static bool TeamID;
    std::vector <Teammate*> teamSquad;
public:
    void addTeammate(Teammate teammate);
    void showTeamSquad();
};
#endif // TEAM_HPP
