#include "Team.hpp"

void Team::addTeammate(Teammate teammate)
{
    teamSquad.push_back(&teammate);
}

void Team::showTeamSquad()
{
    if(teamSquad.size()>0)
    {
        std::cout << teamSquad[0]->getTeamSite() << std::endl;
    }
}
