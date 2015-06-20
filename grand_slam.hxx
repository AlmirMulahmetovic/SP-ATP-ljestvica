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
		void push_match(const Match& new_match){matches.addToEnd(new_match);}
		bool operator==(const grand_slam&)const;
		friend ostream& operator<<(ostream& out,const grand_slam& tour )
		{
	        	for(int i=0; i<tour.matches.listSize(); i++)
	            	{	out<<tour.matches[i]<<endl;
	            		
	            	}
		 return out; 	
		} 
		void store_gslam();
		
		
};
  void grand_slam::store_gslam(){
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

bool grand_slam::operator==(const grand_slam& drugi)const{
	return tournament_name==drugi.tournament_name && rating==drugi.rating;
}
#endif
