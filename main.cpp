#include "list1.hxx"
#include "ljestvica.hxx"
#include <iostream>
#include <fstream>
using namespace std;
void load_players(ATP& table,const string & file_name){
 ifstream fs(file_name.c_str());
  if(!fs) {
	fs.close();
	return;
  }
 string name,lastname,nationality;
 int points;
 while(fs>>name && fs>>lastname && fs>>nationality && fs>>points){
	player a;
	a.Set_player(name,lastname,nationality,points);
	table.insert_player(a);
	}
 
 
 fs.close();
 }
  void store_tournament_names(list<string> names){
	ofstream myfile ("tournament_names.txt");
	for(int i=0;i<names.listSize();i++)
		myfile<<names[i]<<'\n';
	myfile.close();
	}

  void load_tournament_names(list<string>& names){
  string file_name="tournament_names.txt";
  ifstream fs(file_name.c_str());
  if(!fs) {
	fs.close();
	return;
  }
  string name;
  while(fs>>name)
	names.addToEnd(name);
  fs.close();
  }
 int getFileSize() {	
	std::ifstream is ("players.txt", std::ifstream::binary);
	int length = 0;
	if (is) {	    
	    is.seekg (0, is.end);
	    length = is.tellg();	   
	    is.close();
	}
	return length;
 }	


int main(){
	bool added_new= false, already_loaded=false, saved_in_file=false;
	list<string> all_tournaments;
	all_tournaments.print();
	list<data> edit_tournaments;
	ATP table;
//citanje fajlova
  while(true){
	int i;
	cout<<"Choose one of the following options(enter  the number of option):"<<endl;
	cout<<"1) Print ATP list"<<endl;
	cout<<"2) Print tournament"<<endl;
	cout<<"3) Insert tournament"<<endl;
	cout<<"4) End"<<endl;
	cout<<"5) Load data"<<endl;
	cout<<"6) Store data"<<endl;	
	cin>>i;
	if(i==1){
		if(getFileSize()>0 && !already_loaded){
			char decision;
			cout<<"Files aren't loaded do you want to load it Y/N"<<endl;
			cin>>decision;
			if(decision=='Y'){
				load_tournament_names(all_tournaments);
				table.load_tournaments(all_tournaments);
				load_players(table,"players.txt");
				already_loaded=true;
			}
		}
			
		table.mergeSort(byPoints);
		table.see_players();
		}
	else if(i==2){
		if(getFileSize()>0 && !already_loaded){
			char decision;
			cout<<"Files aren't loaded do you want to load it Y/N"<<endl;
			cin>>decision;
			if(decision=='Y'){
				load_tournament_names(all_tournaments);
				table.load_tournaments(all_tournaments);
				load_players(table,"players.txt");
				already_loaded=true;
			}
		}
		if (table.is_finished())
			cout<<"This season is completed!"<<endl;
		else{		
			string name;
			int rating;
			cout<<"Insert name and rating of the tournament that you want to print."<<endl;
			cin>>name>>rating;
			table.print_tournament(rating,name);
		}
		
	}
	else if(i==3){
		if(getFileSize()>0 && !already_loaded){
			char decision;
			cout<<"Files aren't loaded do you want to load it Y/N"<<endl;
			cin>>decision;
			if(decision=='Y'){
				load_tournament_names(all_tournaments);
				table.load_tournaments(all_tournaments);
				load_players(table,"players.txt");
				already_loaded=true;
			}
		}
		cout<<"Insert rating and name of the tournament that you want to insert."<<endl;
		string a;
		int j;
		cin>>j>>a;
		bool done=true;
	
		if(j==250)
			table.enter250(a);
		else if(j==500)
			table.enter500(a);
		else if(j==1000)
			table.enter1000(a);
		else if(j==2000)
			table.enter_gslam(a);
		else{
			cout<<"Wrong rating"<<endl;
			done=false;
		}
		if(done){
			data k;
			k.rate=j;
			k.name=a;
			edit_tournaments.addToEnd(k);
			all_tournaments.addToEnd(a);
			added_new=true;
			saved_in_file=false;
			}
	}
	else if(i==4)
	break;
	else if(i==5){
		load_tournament_names(all_tournaments);
		table.load_tournaments(all_tournaments);
		load_players(table,"players.txt");
		already_loaded=true;
	}
	else if(i==6){
 	table.store_players("players.txt");
 	table.store_tournaments(edit_tournaments);
 	store_tournament_names(all_tournaments);
	saved_in_file=true;
	}

	else
	cout<<"Wrong choise"<<endl;
	cin.clear();
 }
 if(added_new && !saved_in_file){
	char decision;
	cout<<"You have unsaved data, do you want to save it? Y/N"<<endl;
	cin>>decision;
	if(decision=='Y'){
 		table.store_players("players.txt");
 		table.store_tournaments(edit_tournaments);
 		store_tournament_names(all_tournaments);
		}
	}
cout<<"Ending program..."<<endl;
 return 0;				
 }
