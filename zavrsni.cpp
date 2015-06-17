#include "list1.hxx"
#include "master500.hxx"
#include "ljestvica.hxx"
#include <iostream>
using namespace std;
int main(){
ATP lista;
lista.enter500();
lista.see_players();
cout<<"unesite ime i tezinu turnira koji zelite ispisati"<<endl;
int tezina;
string ime;
cin>>ime>>tezina;
lista.print_tournament(tezina,ime);
}
