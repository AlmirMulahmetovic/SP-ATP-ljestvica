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
		master1000(const string& name) : tournament_name(name) {};
		void push_match(const Match& new_match){matches.addToEnd(new_match);}
	bool operator==(const master1000&);
		
	 friend ostream& operator<<(ostream& out,const master1000 tour )
	{
        	for(int i=0; i<tour.matches.listSize(); i++)
            	{	out<<tour.matches[i]<<endl;
            		
            	}
	return out;  	
	} 
	void store_master1000();
	
};
  void master1000::store_master1000(){
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
bool master1000::operator==(const master1000& drugi){
	return tournament_name==drugi.tournament_name && rating==drugi.rating;
}

#endif
