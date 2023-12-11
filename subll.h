#ifndef SUBLL_H
#define SUBLL_H
#include "D_array.h"
#include "node.h"
#include "Stack.h"
#include <iostream>
using namespace std;
template<class T>
class subll
{
	size_t sizel;
	node<T>* head;
	node<T>* current;
	int index;
public:
	subll();
	~subll();
	virtual void insertdata_front(const T&);
	virtual void insertdata_end(const T&);
	virtual void deletedata_front();
	virtual void deletedata_end();
    virtual void search(T);
    virtual void Edit_Product(T);
	virtual bool isfull()
	{
		node <T>* t;
		t = new node<T>;
		if (t == NULL)
		{
			return true;
		}
		else
		{
			delete t;
			return false;
		}
	}
	virtual bool isempty()
	{
		return head == nullptr;
	}
	virtual void display();
};


template<class T>
subll<T>::subll()
{
	index = 0;
	sizel = 0;
	head = nullptr;
	current = nullptr;
}


template<class T>
void subll<T>::insertdata_end(const T&value)
{
	if (!isfull())
	{
		if (head == nullptr)
		{
			head = new node<T>;
			head->next = nullptr;
			current = head;
		}
		if (current->isfull())
		{
			node <T>* t;
			t = new node<T>;
			current->next = t;
			current = t;
			current->next = NULL;
		}
		current->insertarr_end(value);
		sizel++;
	}
	else
	{
		cout << "\n\n\t\t\t\t\tMemory IS Full\n";
	}
}


template<class T>
void subll<T>::insertdata_front(const T &value)
{
	if (!isfull())
	{
		if (head == nullptr)
		{
			head = new node<T>;
			head->next = nullptr;
			current = head;
		}
		current->insertarr_front(value);
		sizel++;
	}
	else
	{
		cout << "\n\n\t\t\t\t\tMemory IS Full\n";
	}
}


template<class T>
void subll<T>::deletedata_end()
{
	if (head)
	{
		if (!current->isempty())
		{
			current->deleteend();
			sizel--;
		}
		else if (current->isempty())
		{
			node<T>* p = head;
			node<T>* q = NULL;
			while (p->next)
			{
				q = p;
				p = p->next;
			}
			delete p;
			q->next = NULL;
			current = q;
			//current->deleteend();
		}
	}
}


template<class T>
void subll<T>::deletedata_front()
{
	if(!isempty())
	{
		if (!head->isempty())
		{
			head->deletefront();
			sizel--;
		}
		if (head->isempty())
		{
			if (!head->next->isempty())
			{
				node<T>* t = head;
				head = head->next;
				delete t;
			}
			else
			{
				cout << "Empry Container\n";
			}
		}
	}
	else
	{
		cout << "\n\n\t\t\t\t\tMemory IS Empty\n";
	}
}

template<class T>
void subll<T>::Edit_Product(T s)
{

    if (head)
    {
        if (!head->isempty())
        {
            int flage=0;
            node<T>*t=head;
            cout<<"Enter New Element : ";
            T value;
            cin>>value;
            while(t)
            {
                if (t->edit(s,value))
                {
                    flage++;
                    break;
                }
                t=t->next;
            }
            if (!flage)
            {
                cout<<"\n\t\t\t\t\## NOT Found To Edit ##\n";
            }
        }
        else if (head->isempty())
        {
            if (!head->next->isempty())
            {
                head=head->next;
                int flage=0;
                node<T>*t=head;
                cout<<"Enter New Element : ";
                T value;
                cin>>value;
                while(t)
                {
                    if (t->edit(s,value))
                    {
                        flage++;
                        break;
                    }
                    else
                        t=t->next;
                }
                if (!flage)
                {
                    cout<<"\n\t\t\t\t\## NOT Found To Edit ##\n";
                }
            }
            else
                throw out_of_range("\n\t\t\t\tContainer IS Empty Can't Display.\n");
        }
        else
            throw out_of_range("\n\t\t\t\tContainer IS Empty Can't Display.\n");
    }
    else
        throw out_of_range("\n\t\t\t\tContainer IS Empty Can't Display.\n");
}

template<class T>
void subll<T>::search(T s)
{
    if (head)
    {
        if (!head->isempty())
        {
            node<T>*p=head;
            int f=0;
            while (p)
            {
                if (p->search(s))
                {
                    f++;
                    break;
                }
                else
                {
                    p=p->next;
                }
            }
            if (f==0)
                cout<<"\n\t\t\t\t\t## NOT Found ##\n";
        }
        else if (head->isempty())
        {
            if (!head->next->isempty())
            {
                head=head->next;
                node<T>*p=head;
                int f=0;
                while (p)
                {
                    if (p->search(s))
                    {
                        f++;
                        break;
                    }
                    else
                    {
                        p=p->next;
                    }
                }
                if (f==0)
                    cout<<"\n\t\t\t\t\t## NOT Found ##\n";
            }
            else
                throw out_of_range("\n\t\t\t\tContainer IS Empty Can't Display.\n");
        }
        else
            throw out_of_range("\n\t\t\t\tContainer IS Empty Can't Display.\n");
    }
    else
        throw out_of_range("\n\t\t\t\tContainer IS Empty Can't Display.\n");
}

template<class T>
void subll<T>::display()
{
	if (head)
	{
		if (!head->isempty())
		{
			node<T>* t = head;
			while (t)
			{
				if (!t->isempty())
				{
					//cout << "[" << i++ << "]- ";
					t->display();
				}
				t = t->next;
			}
		}
		else
			cout << "\n\n\t\t\t\t\tEmpty Container Can't Display. \n";
	}
	else
		cout << "\n\n\t\t\t\t\tEmpty Container Can't Display. \n";
}


template<class T>
subll<T>::~subll()
{
	node<T>* p = head;
	node<T>* t = NULL;
	while (p)
	{
		t = p;
		p = p->next;
		delete t;
	}
}
#endif
