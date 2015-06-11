#include "match.h"

Match::Match()
{
       _name_of_first_player="";
       _name_of_second_player="";
       _result="";
}

void Match::Set_Match(string name_first,string name_second,string result)
{
    _name_of_first_player=name_first;
    _name_of_second_player=name_second;
    _result=result;
}
