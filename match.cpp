#include "match.h"

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

