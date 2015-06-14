#ifndef _MASTER_1000_
#define _MASTER_1000_
#include <iostream>
#include <string>
#include "list1.hxx"
#include "match.h"

using namespace std;

class master1000
{
	private:
		string tournament_name;
		int rating = 1000;
		list<Match> matches{63};
	public:
		master1000() = default;
		master1000(const string& name) : tournament_name(name) {}
		~master1000() = default;
		void push_match(const Match& new_match){matches.addToEnd(new_match);}
};

#endif
