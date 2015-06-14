#ifndef _MASTER_250_
#define _MASTER_250_

#include "list1.hxx"
#include "match.h"

#include <iostream>

using namespace std;

class master250{
  private:
		string tournament_name;
		int rating=250;
		list<Match> matches{31};
  public:
		master250()=default;
		master250(const master250&)=default;
		master250(master250&&)=default;
		master250(string name):tournament_name{name}{};
		~master250() = default;
		void push_match(const Match& new_match){matches.addToEnd(new_match);}
};
#endif
