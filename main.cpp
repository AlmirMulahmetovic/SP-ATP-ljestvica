#include "list1.hxx"
#include "ljestvica.hxx"
#include <iostream>
#include <fstream>
using namespace std;
void load_players(ATP& table,const string & file_name){
 ifstream fs(file_name.c_str());
  if(!fs) {
	cout << "File '" << file_name << "' does not exist." << endl;
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
 table.mergeSort(byPoints);
 
 fs.close();
 }



int main(){
	ATP table;
	load_players(table,"players.txt");
//citanje fajlova
  while(true){
	int i;
	cout<<"Choose one of the following options(enter  the number of option):"<<endl;
	cout<<"1) Print ATP list"<<endl;
	cout<<"2) Print tournament"<<endl;
	cout<<"3) Insert tournament"<<endl;
	cout<<"4) End"<<endl;	
	cin>>i;
	if(i==1)
		table.see_players();
	else if(i==2){
		string name;
		int rating;
		cout<<"Insert name and rating of the tournament that 			you want to print."<<endl;
		cin>>name>>rating;
		table.print_tournament(rating,name);
		}
	else if(i==3){
		cout<<"Insert rating of the tournament that 				you want to insert."<<endl;
		int j;
		cin>>j;
	
		if(j==250)
			table.enter250();
		else if(j==500)
			table.enter500();
		else if(j==1000)
			table.enter1000();
		else if(j==2000)
			table.enter_gslam();
		else
			cout<<"Wrong rating"<<endl;
	}
	else if(i==4)
	break;
	else
	cout<<"Wrong choise"<<endl;
}
table.store_players("tournament.txt");
return 0;				
}
