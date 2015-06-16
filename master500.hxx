#ifndef _MASTER_500_
#define _MASTER_500_
#include "list1.hxx"
#include <iostream>
#include "match.h"
using namespace std;

class master500{
  private:
  string tournament_name;
  int rating=500;
  list<Match> matches{31};
  public:
  master500()=default;
  master500(const master500&)=default;
  master500(master500&&)=default;
  master500(string name):tournament_name{name}{};
  void push_match(const Match& new_match){matches.addToEnd(new_match);}
  
  friend ostream& operator<<(ostream& out,const list<Match>& matches )
	{
        	for(int i=0; i<matches.listSize(); i++)
            	{	out<<matches[i]<<endl;
            		return out;
            	}
		  	
	}
	
};




#endif



