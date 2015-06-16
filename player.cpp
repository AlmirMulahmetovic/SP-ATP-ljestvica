#include "Player.h"

player::player()
{
     _first_name="";
     _last_name="";
     _nationality="";
     _points=0;
}
player player::operator=(const player& p){
	_first_name = p._first_name;
	_last_name = p._last_name;
	_nationality = p._nationality;
	_points = p._points;
	return *this;
}
player::player(const player& Player)
{
    this->_first_name=Player._first_name;
    this->_last_name=Player._last_name;
    this->_nationality=Player._nationality;
    this->_points=Player._points;
}

const std::string& player::Get_first_name() const
{
     return _first_name;
};

 void player::Set_first_name(std::string val)
{
    _first_name = val;
}

void player::Set_last_name(std::string val)
{
    _last_name = val;
}

const std::string& player::Get_nationality() const
{
    return _nationality;
}

void player::Set_nationality(std::string val)
{
    _nationality = val;
}

const int& player::Get_points() const
{
    return _points;
}

void player::Set_points(int val)
{
    _points = val;
}

const std::string& player::Get_last_name()const
{
     return _last_name;
}

void player::Set_player(std::string first_name,std::string last_name,std::string nationality ,int points)
{
    _first_name=first_name;
    _last_name=last_name;
    _points=points;
    _nationality=nationality;

}

bool player::operator==(const player& Player) const
{
    return _first_name==Player._first_name && _last_name==Player._last_name;
};

bool player::operator!=(const player& Player) const
{
    return _first_name!=Player._first_name || _last_name!=Player._last_name;
};

bool player::operator<(const player& Player) const
{
    return _points<Player._points;
};

bool player::operator>(const player& Player) const
{
    return _points>Player._points;
};
bool player::operator<=(const player& Player) const
{
    return _points<=Player._points;
};

bool player::operator>=(const player& Player) const
{
    return _points>=Player._points;
};

void player::increase_points(int a)
{
      _points=_points+a;
}


