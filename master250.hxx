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
		bool operator==(const master250&);
		friend ostream& operator<<(ostream& out,const master250& tour )
		{
        		for(int i=0; i<tour.matches.listSize(); i++)
	            	{	out<<tour.matches[i]<<endl;
	            		
	            	}
		  return out;	
		} 
};

bool master250::operator==(const master250& tour)
{
	return tournament_name==tour.tournament_name && rating==tour.rating;
}
#endif

