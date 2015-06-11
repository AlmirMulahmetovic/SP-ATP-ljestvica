#include "player.h"

player::player()
{
     _first_name="";
     _last_name="";
     _nationality="";
     _points=0;
}

void player::Set_player(string first_name,string last_name,int points)
{
    _first_name=first_name;
    _last_name=last_name;
    _points=points;

}
