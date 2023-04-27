#include "Team.hpp"

Team::Team()
{
    base = NULL;
}

void Team::addTeammate(Teammate teammate)
{
    teamSquad.push_back(&teammate);
}

void Team::addTower(Tower tower)
{
    towers.push_back(&tower);
}

bool Team::addBase(Base base)
{
    if(basePointerIsEmpty())
    {
        this->base = &base;
        return true;
    }
    return false;
}

bool Team::basePointerIsEmpty()
{
    if(this->base == NULL)
    {
        return true;
    }
    return false;
}

void Team::showTeamSquad()
{
    if(teamSquad.size()>0)
    {
        //std::cout << teamSquad[0]->getTeamSite() << std::endl;
    }
    /*if(towers.size()>0)
    {
        std::string word = "";

        for(int i=0; i<towers.size(); i++)
        {
            word += "tower ";
            word += i;
            word += "\n";

        }
        writeInConsole(word);
    }
    if(!basePointerIsEmpty())
    {
       writeInConsole("base");
    }*/
}

void Team::writeInConsole(std::string word)
{
    std::cout << word << std::endl;
}

