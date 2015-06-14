#include "match.h"

using namespace std;
void Match::calculate_sets(int &sets_first,int &sets_second){
	int size=_result.size();
	char first,second; 
	int i=0;
	while(i<size){
		first=_result[i];
		i=i+2;
		second=_result[i];
		i=i+2;
		if(first>second)
			sets_first++;
		else
			sets_second++;
	}
}
player Match::getWinner(){
	int sets_first=0;
	int sets_second=0;
	calculate_sets(sets_first,sets_second);
	if(sets_first>sets_second)
		return Get_first_player();
	else 
		return Get_second_player();
	}
player Match::getLoser(){
int sets_first=0;
	int sets_second=0;
	calculate_sets(sets_first,sets_second);
	if(sets_first<sets_second)
		return Get_first_player();
	else 
		return Get_second_player();
	}


Match::Match(const Match& match)
{
    this->_first_player=match._first_player;
    this->_second_player=match._second_player;
    this->_result=match._result;
};


const player& Match::Get_first_player() const
{
     return _first_player;
}

void Match::Set_first_player(player val)
{
    _first_player = val;
}

const player& Match::Get_second_player() const
{
    return _second_player;
};

void Match::Set_second_player(player val)
 {
     _second_player = val;
}

const std::string& Match::Get_result() const
{
     return _result;
}

void Match::Set_result(std::string val)
{
     _result = val;
}


void Match::Set_Match(player name_first,player name_second,std::string result)
{
    _first_player=name_first;
    _second_player=name_second;
    _result=result;
}

