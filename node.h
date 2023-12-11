#ifndef	NODE_H
#define NODE_H
#include "D_array.h"
#include<iostream>
using namespace std;
template<class T>
class node
{
public:
	D_array<T>data;
	node* next;
	bool isfull();
	bool isempty();
	void insertarr_front(const T&);
	void insertarr_end(const T&);
	void deleteend();
	bool edit(T,const T&);
	void deletefront();
	bool search(T val)
	{
	    return data.search(val);
	}
	void display();
};


template<class T>
bool node<T>::isfull()
{
	return data.isfull();
}

template<class T>
bool node<T>::edit(T val,const T&val2)
{
    return data.edit(val,val2);
}


template<class T>
bool node<T>::isempty()
{
	return data.isempty();
}


template<class T>
void node<T>::insertarr_front(const T& value)
{
	data.insertarr_front(value);
}


template<class T>
void node<T>::insertarr_end(const T &value)
{
	data.insertarr_end(value);
}


template<class T>
void node<T>::deleteend()
{
	data.deletearr_end();
}


template<class T>
void node<T>::deletefront()
{
	data.deletearr_front();
}


template<class T>
void node<T>::display()
{
	if(!isempty())
	{
		data.display();
		cout << endl;
	}
}
#endif
