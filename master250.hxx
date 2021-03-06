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
		master250(string name):tournament_name{name}{};
		void push_match(const Match& new_match){matches.addToEnd(new_match);}
		bool operator==(const master250&);
		friend ostream& operator<<(ostream& out,const master250& tour )
		{
        		for(int i=0; i<tour.matches.listSize(); i++)
	            	{	out<<tour.matches[i]<<endl;
	            		
	            	}
		  return out;	
		} 
	void store_master250();
};
  void master250::store_master250(){
		string file_name=tournament_name+".txt";
		ofstream myfile (file_name);
		if(myfile.is_open()){
			myfile<<tournament_name<<' '<<rating<<'\n';
			for(int i=0;i<matches.listSize();i++){
			myfile<<matches[i].Get_first_player().Get_first_name()<<' '<<matches[i].Get_first_player().Get_last_name()<<' '<<matches[i].Get_first_player().Get_nationality()<<' '<<matches[i].Get_second_player().Get_first_name()<<' '<<matches[i].Get_second_player().Get_last_name()<<' '<<matches[i].Get_second_player().Get_nationality()<<' '<<matches[i].Get_result()<<'\n';
			}
  			myfile.close();
		}
		else
		cout << "File can not be open.";
  }

bool master250::operator==(const master250& tour){
	return tournament_name==tour.tournament_name && rating==tour.rating;
}
#endif
