#ifndef _sort_hxx
#define _sort_hxx
#include "list1.hxx"
#include "Player.h"
bool byPoints(player const &, player const &);
bool byName(player const &, player const &);
bool byCountry(player const &, player const &);

template<typename F>
void merge_sort(list<player> &, int, F const&);
template<typename F>
void merge(list<player>&, list<player>&, list<player>&, int, int, F const& function);

template <typename F>
void merge(list<player>& left, list<player>& right, list<player>& List, int sizeL, int sizeR, F const& function){
	int l = 0, r = 0, i = 0;
	while(l < sizeL && r < sizeR){
		if(function(left[l], right[r])){
			List.deleteFromLocation(i);
			List.addToLocation(i, left[l]);
			++i;++l;
		}else{
			List.deleteFromLocation(i);
			List.addToLocation(i, right[r]);
			++i;++r;
		}
	}
	
	while(l < sizeL){
		List.deleteFromLocation(i);
		List.addToLocation(i, left[l++]);
		++i;
	}
	while(r < sizeR){
		List.deleteFromLocation(i);
		List.addToLocation(i, right[r++]);
		++i;
	}
}
template <typename F>
void merge_sort(list<player>& List, int size, F const & function){
	if(size < 2)
		return;
	int middle = size/2;
	list<player> left(middle);
	list<player> right(size - middle);
	for(int i = 0; i < middle; ++i){
		left.addToLocation(i, List[i]);
	}
	for(int i = 0; i < size - middle; ++i){
		right.addToLocation(i, List[i+middle]);
	}
	merge_sort(left, middle, function);
	merge_sort(right, size - middle, function);
	merge(left, right, List, middle, size-middle, function);
}
bool byPoints(player const & a, player const & b) {
	return a.Get_points() > b.Get_points();
}
bool byName(player const & a, player const & b) {
	return a.Get_last_name() < b.Get_last_name();
}
bool byCountry(player const & a, player const & b) {
	return a.Get_nationality() < b.Get_nationality();
}
#endif
