#ifndef SNODE_H
#define SNODE_H
#include <string>
#include<iostream>
using namespace std;
template<class T>
class snode
{
public:
	T data;
	snode* next;
};
#endif
