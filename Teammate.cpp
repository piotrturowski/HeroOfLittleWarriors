#include "Teammate.hpp"

Teammate::Teammate()
{
    teammatesCounter++;
    teammateID = teammatesCounter;
}

bool Teammate::getTeamSite()
{
    return teamSite;
}

void Teammate::setTeamSite(bool teamSite)
{
    this->teamSite = teamSite;
}

short Teammate::getTeammateID()
{
    return teammateID;
}
void Teammate::setTeammateID(short teammateID)
{
    this->teammateID=teammateID;
}
