#ifndef QUEUES_H
#define QUEUES_H
#include "subll.h"
#include "node.h"
#include<string>
#include <iostream>
using namespace std;
template<class T>
class queues:public subll<T>
{
    int size;
    node<T>* front;
    node<T>* rear;
public:
    queues();
    ~queues();
    void insertdata_front(const T&);
    void deletedata_front();
    void search(T);
    void Edit_Product(T);
    void insertdata_end(const T&);
    void deletedata_end();
    void display();
    bool isfull()
    {
        node <T>* t;
        t = new node<T>;
        if (t==NULL)
        {
            return true;
        }
        else
        {
            delete t;
            return false;
        }
    }
    bool isempty()
    {
        return front == nullptr;
    }
};


template<class T>
queues<T>::queues()
{
    size = 0;
    front= nullptr;
    rear = nullptr;
}


template<class T>
void queues<T>::insertdata_end(const T &value)
{
    if (!isfull())
    {
        if (front == nullptr)
        {
            front = new node<T>;
            front->next = nullptr;
            rear = front;
        }
        if (rear->isfull())
        {
            node <T>* t;
            t = new node<T>;
            rear->next = t;
            rear = t;
            rear->next = NULL;
        }
        rear->insertarr_end(value);
        size++;
    }
    else
    {
        throw out_of_range("\n\t\t\t\tContainer IS FULL Can't INSERT.\n");
    }
}


template<class T>
void queues<T>::insertdata_front(const T &value)
{
    if (!isfull())
    {
        if (front == nullptr)
        {
            front = new node<T>;
            front->next = nullptr;
            rear = front;
        }
        if (rear->isfull())
        {
            node <T>* t;
            t = new node<T>;
            rear->next = t;
            rear = t;
            rear->next = NULL;
        }
        rear->insertarr_front(value);
        size++;
    }
    else
    {
        throw out_of_range("\n\t\t\t\tContainer IS FULL Can't INSERT.\n");
    }
}


template<class T>
void queues<T>::deletedata_end()
{
    if (!isempty())
    {
        if (!rear->isempty())
            rear->deleteend();
        else if (rear->isempty())
        {
            node<T>* p = front;
            node<T>* q = NULL;
            while (p->next)
            {
                q = p;
                p = p->next;
            }
            delete p;
            q->next = NULL;
            rear = q;
            //rear->deleteend();
        }
    }
    else
    {
        throw out_of_range("\n\t\t\t\tContainer IS Empty Can't Delete.\n");
    }
}


template<class T>
void queues<T>::deletedata_front()
{
    if(front)
    {
        if (!front->isempty())
        {
            front->deletefront();
            size--;
            cout << "\n\n\t\t\t\t\tDELETED (^-^)\n\n";
        }
        else if (front->isempty())
        {
            if (size > 0)
            {
                node<T>* t = front;
                front = front->next;
                delete t;
                //size--;
            }
            else
            {
                throw out_of_range("\n\t\t\t\tContainer IS Empty Can't Display.\n");
            }
        }
    }
    else
        throw out_of_range("\n\t\t\t\tContainer IS Empty Can't Display.\n");
}


template<class T>
void queues<T>::search(T s)
{
    if (front)
    {
        if (!front->isempty())
        {
            node<T>*p=front;
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
        else if (front->isempty())
        {
            if (!front->next->isempty())
            {
                front=front ->next;
                node<T>*p=front;
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
void queues<T>::Edit_Product(T s)
{
    if (front)
    {
        if (!front->isempty())
        {
            int flage=0;
            node<T>*t=front;
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
        else if (front->isempty())
        {
            if (!front->next->isempty())
            {
                front=front ->next;
                int flage=0;
                node<T>*t=front;
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
void queues<T>::display()
{
    if (front)
    {
        if (!front->isempty())
        {
            node<T>* t = front;
            while (t)
            {
                t->display();
                t = t->next;
            }
        }
        else if (front->isempty())
        {
            if (front->next)
            {
                if (!front->next->isempty())
                {
                    front = front->next;
                    front->display();
                }
                else
                    throw out_of_range("\n\t\t\t\tContainer IS Empty Can't Display.\n");
            }
            else
                throw out_of_range("\n\t\t\t\tContainer IS Empty Can't Display.\n");
        }
        else
        {
            throw out_of_range("\n\t\t\t\tContainer IS Empty Can't Display.\n");
        }
    }
    else
        throw out_of_range("\n\t\t\t\tContainer IS Empty Can't Display.\n");
}


template<class T>
queues<T>::~queues()
{
    node<T>* p = front;
    node<T>* t = NULL;
    while (p)
    {
        t = p;
        p = p->next;
        delete t;
    }
}
#endif
