#ifndef D_ARRAY_H
#define D_ARRAY_H
#include <iostream>
#include<algorithm>
using namespace std;
template<class T>
class D_array
{
    T*arr;
    int sizea;
    int cap;
    void underline();
    int find(T);
public:
    D_array();
    D_array(int sizea);
    void insertarr_front(const T&);
    void insertarr_end(const T&);
    void deletearr_end();
    void deletearr_front();
    void set(T,int);
    bool isempty();
    bool search(T);
    bool edit(T,const T&);
    bool isfull();
    friend istream& operator<<(istream& out, D_array& ob);
    void operator =(const D_array<T>& other)
    {
        if (this != &other)
        {
            delete[] arr;
            sizea = other.sizea;
            cap = other.cap;
            arr = new T[cap];
            for (int i = 0; i < sizea; i++)
            {
                arr[i] = other.arr[i];
            }
        }
    }
    void display();
    int getsize()
    {
        return sizea;
    }
    T& operator[](int index)
    {
        return arr[index];
    }
    ~D_array();
};

template<class T>
D_array<T>::D_array()
{
    sizea = 0;
    cap = 5;
    arr = new T[5];
}


template<class T>
D_array<T>::D_array(int sizea)
{
    this->sizea =0 ;
    cap = sizea;
    arr = new T[cap];
}


template<class T>
bool D_array<T>::isfull()
{
    return sizea == cap;
}


template<class T>
bool D_array<T>::isempty()
{
    return sizea == 0;
}


template<class T>
void D_array<T>::insertarr_end(const T& value)
{
    if (sizea <= cap)
    {
        arr[sizea++] = value;
    }
}


template<class T>
void D_array<T>::insertarr_front(const T& value)
{
    try
    {
        if (!isfull())
        {
            if (!isempty())
                copy(arr, arr + sizea, arr + 1);
            arr[0] = value;
            sizea++;
        }
        else
        {
            throw ("Can't Insert Array Is FULL\n");
        }
    }
    catch (const char* errorh)
    {
        underline();
        cout << errorh << endl;
        underline();
        throw out_of_range("Can't Insert Array Is FULL\n");
    }
}


template<class T>
void D_array<T>::deletearr_end()
{
    if (!isempty())
        sizea--;
    else
        throw out_of_range("\n\t\t\t\tARRAY IS Empty\n");
}


template<class T>
void D_array<T>::underline()
{
    for (int i = 0; i < 100; ++i)
    {
        cout << '-';
    }
    cout << "\n";
}


template<class T>
void D_array<T>::deletearr_front()
{
    if (!isempty())
    {
        copy(arr + 1, arr + sizea, arr+0);//copy resizing
        sizea--;
    }
    else
        throw out_of_range("\n\t\t\t\tARRAY IS Empty\n");
}


template<class T>
void D_array<T>::set(T value,int index)
{
    arr[index] = value;
    sizea++;
}

template<class T>
ostream& operator<<(ostream& out, D_array<T> &ob)
{
    if (!ob.isempty())
        for (int i = 0; i < ob.sizea; i++)
        {
            out << "[" << i+1 << "]- ";
            out << ob.arr[i] << "\n";
        }
    else
        throw out_of_range("\n\t\t\t\tARRAY IS Empty\n");
    out << endl;
    return out;
}


template<class T>
bool D_array<T>::search(T other)
{
    int flage=0;
    int i;
    for (i=0; i<sizea; i++)
    {
        if (arr[i]==other)
        {
            flage++;
            break;
        }
    }
    if (flage)
    {
        cout<<"\n\t\t\t\t\t## Found ##\n";
        cout<<arr[i]<<endl;
    }
    return flage;
}

template<class T>
int D_array<T>::find(T other)
{
    int flage=0;
    int i;
    for (i=0; i<sizea; i++)
    {
        if (arr[i]==other)
        {
            flage++;
            break;
        }
    }
    if (flage)
        return i;
    return -1;
}

template<class T>
bool D_array<T>::edit(T other,const T &value)
{
    int i=find(other);
    if (i!=-1)
    {
        arr[i]=value;
        cout<<"\n\t\t\t\t ## Edited ##\n";
        return 1;
    }
    return 0;
}

template<class T>
void D_array<T>::display()
{
    if (!isempty())
        for (int i = 0; i < sizea; i++)
        {
            cout << "[" << ++i << "]- ";
            cout << arr[i] << "\n";
            underline();
        }
    else
        throw out_of_range("\n\t\t\t\tARRAY IS Empty\n");
    cout << endl;
}


template<class T>
D_array<T>::~D_array()
{
    delete[]arr;
}
#endif
