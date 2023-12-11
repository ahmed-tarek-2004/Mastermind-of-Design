#ifndef STACK_H
#define STACK_H
#include<iostream>
#include <stdexcept>
#include "snode.h"
#include <string>
using namespace std;
template<class T>
class Stack
{
    int size;
    snode<T>* top;
    string name;
public:
    snode<T>* gettop()
    {
        return top;
    }
    Stack();
    bool empty();
    bool full();
    int getsize();
    void push(const T&);
    T pop();
    void peek(int);
    void setname(string name);
    T top_data()
    {
        return top->data;
    }
    void operator=(const Stack<T> &other)
    {
        if (this != &other)
        {
            while (top != nullptr)
            {
                snode<T>* temp = top;
                top = top->next;
                delete temp;
            }
            snode<T>* t = other.top;
            snode<T>* p = nullptr;
            name = other.name;
            while (t != nullptr)
            {
                snode<T>* newsnode = new snode<T>;
                newsnode->data = t->data;
                if (p == nullptr)
                {
                    top = newsnode;
                }
                else
                {
                    p->next = newsnode;
                }
                p = newsnode;
                t = t->next;
            }
            p->next = nullptr;
        }
    }
    bool operator==(const Stack<T>&other)
    {
        return name==other.name;
    }
    friend ostream& operator<<(ostream& out, Stack <T> &ob)
    {
        if (ob.top)
        {
            snode<T>* p = ob.top;
            int index = 0;
            out << "Product Name IS " << ob.name << endl;
            out << "Operation/s IS : \n";
            while (p)
            {
                out << "[" << ++index << "]- " << p->data << endl;
                p = p->next;
            }
            out<< endl;
        }
        else
        {
            throw out_of_range("\n\t\t\t\tStack IS Empty\n");
        }
        return out;
    }
    friend istream& operator>>(istream& in, Stack <T> &ob)
    {
        cout << "\nEnter Product Name : ";
        string name;
        in >> name;
        ob.setname(name);

        cout << "How Many Operations You Want To Do ";
        cout << "Enter Your Answer : ";
        int num;
        in >> num;
        cout << "Enter Product Operation/s :- \n";
        for (int i = 0; i < num; i++)
        {
            T operations;
            cout << "\n [" << i + 1 << "] : ";
            in >> operations;
            ob.push(operations);
        }
        return in;
    }
    void display();
    ~Stack();
};

template<class T>
Stack<T>::Stack()
{
    name ="";
    top = nullptr;
    size = 0;
}


template<class T>
int Stack<T>::getsize()
{
    return size;
}

template<class T>
bool Stack<T>::empty()
{
    return top == nullptr;
}

template<class T>
bool Stack<T>::full()
{
    snode<T>* p = new snode<T>;
    if (p == nullptr)
    {
        return true;
    }
    else
    {
        delete p;
        return false;
    }
}
template <class T>
void Stack<T>::setname(string name)
{
    this->name = name;
}
template<class T>
void Stack<T>::push(const T& value)
{
    if (!full())
    {
        snode<T>* p = new snode<T>;
        p->data = value;
        p->next = top;
        top = p;
        size++;
    }
    else
        throw out_of_range("\n\t\t\t\tStack IS Full\n");
}

template<class T>
T Stack<T>::pop()
{
    if (!empty())
    {
        snode<T>* p = top;
        T value = top->data;
        top = top->next;
        delete p;
        size--;
        return value;
    }
    else
    {
        throw out_of_range("\n\t\t\t\tStack IS Empty\n");
    }
}

template<class T>
void Stack<T>::peek(int index)
{
    // Index With Zero
    if (!empty())
    {
        snode<T>* p = top;
        for (int i = 0; i < index; i++)
        {
            p = p->next;
        }
        cout << "Data in Index " << "( " << index << " ) IS : " << p->data << endl;
    }
    else
    {
        throw out_of_range("\n\t\t\t\tStack IS Empty\n");
    }
}


/*template<class T>
ostream& operator<<(ostream& out, Stack<T> &ob)
{
	snode<T>* p = ob.gettop();
	int index = 0;
	while (p)
	{
		out << "Data in Index " << "( " << index++ << " ) IS : " << p->data << endl;
		p = p->next;
	}
	out << endl;
	return out;
}*/


template<class T>
void Stack<T>::display()
{
    // Index With Zero
    if (top)
    {
        snode<T>* p = top;
        int index = 0;
        cout << "Product Name IS : " << name << endl;
        cout << "Operation/s IS : \n";

        while (p)
        {
            cout << "["<<++index<<"]- " << p->data << endl;
            p = p->next;
        }
        cout << endl;
    }
    else
    {
        throw out_of_range("\n\t\t\t\tStack IS Empty\n");
    }
}
template<class T>
Stack<T>::~Stack()
{
    while (!empty())
    {
        pop();
    }
}
#endif
