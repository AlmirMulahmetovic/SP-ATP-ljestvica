#ifndef _LJESTVICA_H
#define _LJESTVICA_H
#include "list1.hxx"
#include "Player.h"
#include "match.h"
#include <iostream>
#include "master500.hxx"
#include "master1000.hxx"
#include "grand_slam.hxx"
using namespace std;

class ATP{
private: 
  
  list<player> players;
  list<master500> master_500;
public:  
  void enter500();
  void enter1000();
  void enter_round(int num_of_matches,int points,list<player>& winners,list<player>& this_winners,master500 &tournament);
  void enter_round1(int num_of_matches,int points,list<player>& this_winners,master500 &tournament);
  void see_players(){players.print();}
}; 
/*void ATP::enter500(){
string name;
  cout<<"Please enter tournament name."<<endl;
  cin>>name;
  master500 tournament(name);
  list<player> winners2(2);
  string name1,lastname1,name2,lastname2,result;
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
}*/
  void ATP::enter500(){
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
}

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
  
void ATP::enter_round(int num_of_matches,int points,list<player>& winners,list<player>& this_winners,master500 &tournament){
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
	}
	else{
	cout<<"One of two players that you typed lost in previous round,type again!"<<endl;
	i++;
	continue;	
	}
  }
}
void ATP::enter_round1(int num_of_matches,int points,list<player>& this_winners,master500 &tournament){
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
  }
}


#endif
