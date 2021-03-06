#ifndef _LIST_
#define _LIST_

#include <iostream>
#include<stdexcept>

using namespace std; 

template<typename T>
class list
{
private:
	T* elements; 
	int size;  
	int maxSize; 
public:
	list(int n = 100); 
	list(const list<T>& List); 
	const list<T>& operator=(const list<T>&); 
	bool empty() const;
	bool full() const;
	int listSize() const { return size; } 
	int maxListSize() const { return maxSize; } 
	void print() const; 
	bool equal(int location, const T& obj) const;  
	list<T>&  addToLocation(int location, const T& objadd);
	list<T>&  addToEnd(const T& objadd); 
	list<T>&  deleteFromLocation(int location); 
	list<T>&  replaceOnLocation(int location, const T& objNew); 
	int find(const T& obj);
	list<T>&  add(const T& obj);
	list<T>&  deleteEl(const T& obj); 
	T& catchEl(int location); 
	T& Min();
	T& Max();
	T operator[](int index) const;
	T& operator[](int index);
	~list(void) { delete  [] elements; } 
	
	friend ostream& operator<<(ostream& out , const list<T>& List){ 	       
            for(auto i = 0; i<List.size; i++)
                out<<List.elements[i]<<endl;
            out<<endl;
            return out;
    }

};

template <typename T>
T & list<T>::operator[](int index)
{
  if(index < 0 || index >= size)
  {
    std::string message = "Index (" 
      + std::to_string(index) 
      + ") out_of_range [" 
      + std::to_string(0) + ", " + std::to_string(size) + "]." ;
    throw std::invalid_argument(message);
  }
  return elements[ index ];
}

template <typename T>
T list<T>::operator[](int index) const
{
  if(index < 0 || index >= size)
  {
    std::string message = "Index (" 
      + std::to_string(index) 
      + ") out_of_range [" 
      + std::to_string(0) + ", " + std::to_string(size) + "]." ;
    throw std::invalid_argument(message);
  }
  return elements[ index ];
}

template<typename T>
list<T>::list(int n)
{
  n<0 ?  maxSize  = 100 : maxSize = n; 
  size = 0; 
  elements = new T[maxSize];
}


template<typename T>
list<T>::list(const list<T>& List)
{
	maxSize = List.maxListSize(); 
	size = List.listSize(); 
	elements = new T[maxSize]; 
	for (int i = 0; i<size; i++)
		elements[i] = List.elements[i];
}

template<typename T>
const list<T>& list<T>::operator=(const list<T>& otherList)
{
	if (this!=&otherList) 
	{
		delete [] elements; 
		maxSize = otherList.maxListSize(); 
		size = otherList.listSize(); 
		elements = new T[maxSize]; 
		for (int i= 0; i<size; i++)
			elements[i] = otherList.elements[i];
	}
	return *this; 
}


template<typename T>
bool list<T>::empty() const
{
	return (size == 0);
}


template<typename T>
bool list<T>::full() const
{
	return (size == maxSize);
}


template<typename T>
void list<T>::print() const
{
	for (int i = 0; i<size; i++)
		cout << elements[i] <<endl;;
	cout << endl; 
}



template<typename T>
bool list<T>::equal(int location, const T& obj) const
{
	return (elements[location]==obj); 
}

template<typename T> 
list<T>& list<T>::addToLocation(int location, const T& objadd)
{
	if (location<0 || location > maxSize)
		throw out_of_range("You have entered wrong index.");
	else 
	{
		if (full())
			throw string("list is full. It is not possible to add another element. ");
		else 
		{
			for (int i = size; i>location; i--) 
				elements[i] = elements[i-1]; 
			elements[location] = objadd; 
			size++;
		} 
	}
	return *this;
}


template<typename T> 
list<T>& list<T>::addToEnd(const T& objadd)
{
	if (full())
		throw string("list is full. It is not possible to add another element. ");
	else 
	    elements[size++] = objadd;	
	   
	return *this;	
	
}

template<typename T> 
list<T>& list<T>::deleteFromLocation(int location)
{
	if (location<0 || location >= size)
		throw out_of_range("You have entered wrong index.");
	else 
	{
		for (int i = location; i<size - 1; i++)
			elements[i] = elements[i+1];
		size--; 
		
	}
	
	return *this;
}


template<typename T> 
list<T>& list<T>::replaceOnLocation(int location, const T& objNew)
{
	
	if (location<0 || location >= size)
		throw out_of_range("You have entered wrong index.");
	else 
	{
		elements[location] = objNew; 
	}
	
	return *this;
}


template<typename T> 
int list<T>::find(const T& obj)
{
	for (int i = 0; i<size; i++)
	{
		if (elements[i]==obj)
			return i; 
	}
	return -1; 
}


template<typename T> 
list<T>& list<T>::add(const T& obj)
{
	if (find(obj)==-1)
	{
		addToEnd(obj);
	}
	return *this;
}

template<typename T> 
list<T>& list<T>::deleteEl(const T& obj)
{
    auto loc = find(obj);
	if (loc!=-1) 
	{
	   deleteFromLocation(loc);
	}
	return *this;
}


template<typename T> 
T& list<T>::catchEl(int location) 
{
	if (location<0 || location >= size)
		throw out_of_range("Niste unijeli dozvoljeni indeks.");
	else 
		return elements[location];
}

template<typename T>
T& list<T>::Min()
{
	T min;
	min=elements[0];
	for(auto i=1; i<size; i++){
		if(min>elements[i])
		min=elements[i];
		}
	return min;
}

template<typename T> 
T& list<T>::Max() 
{ 
	T max; 
	max=elements[0]; 
	for (auto i=1; i<size;i++){ 
	 	if (max<elements[i]) 
		max=elements[i]; 
		} 
	return max; 
}

#endif
