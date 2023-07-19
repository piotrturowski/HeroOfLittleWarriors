#ifndef TEAMMATE_HPP
#define TEAMMATE_HPP




class Teammate
{
private:
    static int teammatesCounter;
    bool teamSite;
    short teammateID;
public:
    Teammate();
    bool getTeamSite();
    void setTeamSite(bool teamSite);
    short getTeammateID();
    void setTeammateID(short teammateID);
};
#endif // TEAMMATE_HPP
