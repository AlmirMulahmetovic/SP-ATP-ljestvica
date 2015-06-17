#ifndef _grand_slam_hxx
#define _grand_slam_hxx
#include <string>
#include "list1.hxx"
#include "match.h"


class grand_slam{
	private:
		std::string tournament_name;
		int rating = 2000;
		list<Match> matches{127};
	public:
		grand_slam() = default;
		grand_slam(std::string n): tournament_name(n){}
		~grand_slam(){}
		void push_match(const Match& new_match){matches.addToEnd(new_match);}
		bool operator==(const grand_slam&)const;
		friend ostream& operator<<(ostream& out,const grand_slam& tour )
		{
	        	for(int i=0; i<tour.matches.listSize(); i++)
	            	{	out<<tour.matches[i]<<endl;
	            		
	            	}
		 return out; 	
		} 
};

bool grand_slam::operator==(const grand_slam& tour)const
{
	return tournament_name==tour.tournament_name && rating==tour.rating;
}

#endif
