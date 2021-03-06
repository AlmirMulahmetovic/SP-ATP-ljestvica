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
 
  master500(string name):tournament_name{name}{};
  void push_match(const Match& new_match){matches.addToEnd(new_match);}
  bool operator==(const master500&);
  friend ostream& operator<<(ostream& out,const master500& tour )
	{
        	for(int i=0; i<tour.matches.listSize(); i++)
            	{	out<<tour.matches[i]<<endl;
            		
            	}
		return out;  	
	}
  void store_master500();
	
};
  void master500::store_master500(){
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

bool master500::operator==(const master500& tour){
	return tournament_name==tour.tournament_name && rating==tour.rating;
 }



#endif



