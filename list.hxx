#ifndef _list_hxx
#define _list_hxx

#include <iostream>
#include <stdexcept>
void merge(int*, int*, int*, int, int);
void mergeSort(int*, int);

template <typename T>
class list{
	public:
	list(int max){
		max_size = max;
		size = 0;
		elements = new T[max_size];
	}
	~list(){
		delete []elements;
	}
	list(const list<T>& l){
		max_size = l.max_size;
		size = l.size;
		elements = new T[max_size];
		for(int i = 0; i < size; ++i){
			elements[i] = l.elements[i];
		}
	}
	list(list<T>&& l){
		size = l.size;
		max_size = l.max_size;
		elements = l.elements;
		l.elements = nullptr;
	}
	list<T>& operator=(const list<T> & l){
		if(elements != l.elements){
			delete [] elements;
			size = l.size;
			elements = new T[l.max_size];
			for(int i = 0; i < size; ++i){
				elements[i] = l.elements[i];
			}
		}
		return *this;
	}
	list<T>& operator=(list<T> && l){
		auto temp = *this;
		*this = l;
		l = temp;
		return *this;
	}
	list<T>& dodaj_iza(T a){
		elements[size++] = a;
		return *this;
	}
	list<T>& dodaj_ispred(T a){
		size++;
		for(int i = size-1; i > 0; --i){
			elements[i] = elements[i-1];
		}
		elements[0] = a;
		return *this;
	}
	void ispisi(){
		for(int i = 0; i < size; ++i){
			std::cout << elements[i] << " ";
		}
		std::cout << std::endl;
	}
	T at(int i){
		if(i < 0 || i > size - 1)
			throw std::out_of_range("Index not valid!");
		else
			return elements[i];
	}
		private:
		T* elements;
		int size;
		int max_size;
		
};


#endif
