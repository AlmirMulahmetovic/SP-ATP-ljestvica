#ifndef _LJESTVICA_H
#define _LJESTVICA_H
#include "list1.hxx"
#include "Player.h"
#include "match.h"
#include <iostream>
#include <fstream>
#include "master250.hxx"
#include "master500.hxx"
#include "master1000.hxx"
#include "grand_slam.hxx"
#include "sort.hxx"
using namespace std;

class ATP{
private: 
  
  list<player> players;
  list<master250> master_250;
  list<master500> master_500;
  list<master1000> master_1000;
  list<grand_slam> grandSlam;
public:
  template<typename F>
  void mergeSort(F const&);
  void enter250();
  void enter500();
  void enter1000();
  void enter_gslam();
  template<typename T>
  void enter_round(int num_of_matches,int points,list<player>& winners,list<player>& this_winners,T &tournament);
  template<typename T>
  void enter_round1(int num_of_matches,int points,list<player>& this_winners,T &tournament);
  void see_players();
  void print_tournament(int, const string&);
  void store_players(const string& file_name);
  void insert_player(const player&);
}; 
  void ATP::insert_player(const player& p){
  players.addToEnd(p);
  }
  void see_players(){
  	mergeSort(byPoints);
  	players.print();
  }

void ATP::enter500(){
string name;
  cout<<"Please enter tournament name."<<endl;
  cin>>name;
  master500 tournament(name);
  list<player> winners2(2);
  player first,second;
  enter_round1(2,200,winners2,tournament);
  winners2.print();
  list<player> winners1(1);
  enter_round(1,360,winners2,winners1,tournament);
  player winner=winners1[0];
  bool found=false;	
	for(int i=0;i<players.listSize();i++){
		if(winner==players[i]){
			players[i].increase_points(500);
			found=true;
			break;
			}
		}
	if(!found){
	winner.increase_points(500);
	players.addToEnd(winner);
	}
 
  master_500.addToEnd(tournament);
  cout<<master_500[0]<<endl;
  cout<<tournament<<endl;
}

 void ATP::enter250()
 {
		  string name;
		  cout<<"Please enter tournament name."<<endl;
		  cin>>name;
		  master250 tournament(name);
		  list<player> winners16(16);
		  string name1,lastname1,name2,lastname2,result;
		  player first,second;
		  enter_round1(16,5,winners16,tournament);
		  list<player> winners8(8);
		  enter_round(8,20,winners16,winners8,tournament);
		  list<player> winners4(4);
		  enter_round(4,45,winners8,winners4,tournament);
		  list<player> winners2(2);
		  enter_round(2,90,winners4,winners2,tournament);
		  list<player> winners1(1);
		  enter_round(1,150,winners2,winners1,tournament);
		  player winner=winners1[0];
		  bool found=false;	
		  for(int i=0;i<players.listSize();i++)
		  {
				if(winner==players[i])
				{
					players[i].increase_points(250);
					found=true;
					break;
				}
		  }
		if(!found)
		{
				winner.increase_points(250);
				players.addToEnd(winner);
		}
} 

/*void ATP::enter500(){
  string name;
  cout<<"Please enter tournament name."<<endl;
  cin>>name;
  master500 tournament(name);
  list<player> winners16(16);
  string name1,lastname1,name2,lastname2,result;
  player first,second;
  enter_round1(16,20,winners16,tournament);
  list<player> winners8(8);
  enter_round(8,45,winners16,winners8,tournament);
  list<player> winners4(4);
  enter_round(4,90,winners8,winners4,tournament);
  list<player> winners2(2);
  enter_round(2,180,winners4,winners2,tournament);
  list<player> winners1(1);
  enter_round(1,360,winners2,winners1,tournament);
  player winner=winners1[0];
  bool found=false;	
	for(int i=0;i<players.listSize();i++){
		if(winner==players[i]){
			players[i].increase_points(500);
			found=true;
			break;
			}
		}
	if(!found){
	winner.increase_points(500);
	players.addToEnd(winner);
	}
}*/

 void ATP::enter1000(){
  string name;
  cout<<"Please enter tournament name."<<endl;
  cin>>name;
  master1000 tournament(name);
  string name1,lastname1,name2,lastname2,result;
  player first,second;
  list<player> winners32(32);
  enter_round1(32,25,winners32,tournament);
  list<player> winners16(16);
  enter_round(16,45,winners32,winners16,tournament);
  list<player> winners8(8);
  enter_round(8,90,winners16,winners8,tournament);
  list<player> winners4(4);
  enter_round(4,180,winners8,winners4,tournament);
  list<player> winners2(2);
  enter_round(2,360,winners4,winners2,tournament);
  list<player> winners1(1);
  enter_round(1,600,winners2,winners1,tournament);
  player winner=winners1[0];
  bool found=false;	
	for(int i=0;i<players.listSize();i++){
		if(winner==players[i]){
			players[i].increase_points(1000);
			found=true;
			break;
			}
		}
	if(!found){
	winner.increase_points(1000);
	players.addToEnd(winner);
	}
  
}
void ATP::enter_gslam(){
	string name;
	cout<<"Please enter tournament name."<<endl;
	cin>>name;
	grand_slam tournament(name);
	list<player> winners64(64);
	string name1, lastname1, name2, lastname2, result;
	player first, second;
	enter_round1(64, 10, winners64, tournament);
	list<player> winners32(32);
	enter_round(32, 45, winners64, winners32, tournament);
	list<player> winners16(16);
	enter_round(16, 90, winners32, winners16, tournament);
	list<player> winners8(8);
	enter_round(8, 180, winners16, winners8, tournament);
	list<player> winners4(4);
	enter_round(4, 360, winners8, winners4, tournament);
	list<player> winners2(2);
	enter_round(2, 720, winners4, winners2, tournament);
	list<player> winners1(1);
	enter_round(1, 1200, winners2, winners1, tournament);
	player winner=winners1[0];
	bool found=false;	
	for(int i=0;i<players.listSize();i++){
		if(winner==players[i]){
			players[i].increase_points(2000);
			found=true;
			break;
		}
	}
	if(!found){
		winner.increase_points(2000);
		players.addToEnd(winner);
	}
}
template<typename T>
void ATP::enter_round(int num_of_matches,int points,list<player>& winners,list<player>& this_winners,T &tournament){
  cout<<"Enter the first match of round"<<endl;
  string name1,name2,lastname1,lastname2,natonality1,natonality2,result;
  player first,second;
  for(int i=num_of_matches;i>0;i--){
 	cin>>name1>>lastname1>>natonality1>>name2>>lastname2>>natonality2>>result;
	first.Set_player(name1,lastname1,natonality1,0);  
	second.Set_player(name2,lastname2,natonality2,0);
  	bool iswinner1=false;
	bool iswinner2=false;
	for(int j=0;j<winners.listSize();j++){
		if(winners[j]==first){
			iswinner1=true;
			break;
		}
	}
	for(int k=0;k<winners.listSize();k++){
		if(winners[k]==second){
			iswinner2=true;
			break;
		}
	}
	if(iswinner1 && iswinner2){
	Match a;
	a.Set_Match(first,second,result);
	player winner=a.getWinner();
	player loser=a.getLoser();
	tournament.push_match(a);	
	this_winners.addToEnd(winner);
	bool found=false;	
		for(int i=0;i<players.listSize();i++){
			if(loser==players[i]){
				players[i].increase_points(points);
				found=true;
				break;
			}
		}
		if(!found){
		loser.increase_points(points);
		players.addToEnd(loser);
		}
	if(i!=num_of_matches-1)
	cout<<"Please enter next match od round."<<endl;
	}
	else{
	cout<<"One of two players that you typed lost in previous round,type again!"<<endl;
	i++;
	continue;	
	}
  }
}
template<typename T>
void ATP::enter_round1(int num_of_matches,int points,list<player>& this_winners,T &tournament){
  cout<<"Enter the first match of round"<<endl;
  string name1,name2,lastname1,lastname2,natonality1,natonality2,result;
  player first,second;  
  for(int i=num_of_matches;i>0;i--){
 	cin>>name1>>lastname1>>natonality1>>name2>>lastname2>>natonality2>>result;
	first.Set_player(name1,lastname1,natonality1,0);  
	second.Set_player(name2,lastname2,natonality2,0);
	Match a;
	a.Set_Match(first,second,result);
	player winner=a.getWinner();
	player loser=a.getLoser();
	tournament.push_match(a);	
	this_winners.addToEnd(winner);
	bool found=false;	
		for(int i=0;i<players.listSize();i++){
			if(loser==players[i]){
				players[i].increase_points(points);
				found=true;
				break;
			}
		}
		if(!found){
		loser.increase_points(points);
		players.addToEnd(loser);
		}
  	if(i!=num_of_matches-1)
	cout<<"Please enter next match od round."<<endl;
  }
}

void ATP::print_tournament(int points, const string& name)
{
	if(points == 250)
	{
		master250 tour(name);
		int i = master_250.find(tour);
		if(i != -1)
			cout<< master_250[i] <<endl;
		else
			cout<<"You have requested to print tournament that does not exist. Please recheck your spell, and try again."<<endl;
	}
	else if(points == 500)
	{
		master500 tour(name);
		int i = master_500.find(tour);
		if(i != -1)
			cout<< master_500[i] <<endl;
		else
			cout<<"You have requested to print tournament that does not exist. Please recheck your spell, and try again."<<endl;
	}
	else if(points == 1000)
	{
		master1000 tour(name);
		int i = master_1000.find(tour);
		if(i != -1)
			cout<< master_1000[i] <<endl;
		else
			cout<<"You have requested to print tournament that does not exist. Please recheck your spell, and try again."<<endl;
	}
	else if(points == 2000)
	{
		grand_slam tour(name);
		int i = grandSlam.find(tour);
		if(i != -1)
			cout<< grandSlam[i] <<endl;
		else
			cout<<"You have requested to print tournament that does not exist. Please recheck your spell, and try again."<<endl;
	}
}

template<typename F>
void ATP::mergeSort(F const& function){
	merge_sort(players, players.listSize(), function);
}
  void ATP::store_players(const string& file_name){
  	mergeSort(byPoints);
	ofstream myfile (file_name);
	if(myfile.is_open()){
		for(int i=0;i<players.listSize();i++){
		myfile<<players[i].Get_first_name()<<' '<<players[i].Get_last_name()<<' '<<players[i].Get_nationality()<<' '<<players[i].Get_points()<<'\n';
		}
	myfile.close();
	}
	else 
	cout << "File can not be open.";
  }







#endif
