#ifndef MATCH_H
#define MATCH_H
#include <string>
#include "Player.h"

class Match
{
    public:
        Match()=default;
		Match(const Match& match);
	void calculate_sets(int &sets_first,int &sets_second);	
	player getWinner();
	player getLoser();	
        const player& Get_first_player() const;
        void Set_first_player(player val);
        const player& Get_second_player() const;
        void Set_second_player(player val);
        const std::string& Get_result() const;
        void Set_result(std::string val);
        void Set_Match(player name_first,player name_second,std::string result);

 	friend std::ostream& operator<<(std::ostream& out,const Match& val )
        {
           out<< val.Get_first_player().Get_first_name() << " " << val.Get_first_player().Get_last_name() << "(" << val.Get_first_player().Get_nationality() << ")" << " - " << val.Get_second_player().Get_first_name() << val.Get_second_player().Get_last_name() << "(" << val.Get_second_player().Get_nationality() << ")" << val.Get_result() <<std::endl;
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
