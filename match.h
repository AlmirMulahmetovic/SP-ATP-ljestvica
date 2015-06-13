#ifndef MATCH_H
#define MATCH_H

#include "Player.h"

class Match
{
    public:
        Match()=default;
		Match(const Match& match);
		
        const player& Get_first_player() const;
        void Set_first_player(player val);
        const player& Get_second_player() const;
        void Set_second_player(player val);
        const std::string& Get_result() const;
        void Set_result(std::string val);
        void Set_Match(player name_first,player name_second,std::string result);

        friend std::ostream& operator<<(std::ostream& out,const Match& val )
        {
            out<<val._first_player<<" - "<<val._second_player<<"Result: "<<val._result;
            return out;

        }
        /*
        friend istream& operator<<(istream& in,player& val )
        {

             in>>val._first_player;
             in>>val._second_player;
             in>>val._result;
             return in;
        }
        */
    protected:
    private:
        player _first_player;
        player _second_player;
        std::string _result;
};

#endif // MATCH_H
