#ifndef FACTORY_H
#define FACTOR_H
#include "Queues.h"
#include<string>
using namespace std;
class Factory
{
    queues<Stack<string>>queue;
    Stack<string> stack;
public:
    void add_product();
    void EditProduct();
    void dellete_operation();
    void delete_product();
    void search();
    void display();
};
void Factory::add_product()
{
    //system("cls");
    // Add function
    while (!stack.empty())
    {
        stack.pop();
    }
    cout << "Enter Product Name : ";
    string name;
    cin >> name;
    stack.setname(name);

    cout << "How Many Operations You Want To Do ";
    cout << "Enter Your Answer : ";
    int num;
    cin >> num;
    cout << "Enter Product Operation/s :- \n";
    for (int i = 0; i < num; i++)
    {
        string operations;
        cout << "\n [" << i + 1 << "] : ";
        cin >> operations;
        stack.push(operations);
    }
    if (num)
        queue.insertdata_end(stack);
}
void Factory::delete_product()
{
    queue.deletedata_front();
}
void Factory::display()
{
    queue.display();
}
void Factory::EditProduct()
{
    if (!queue.isempty())
    {
        cout<<"Enter Stack Name To Edit : ";
        Stack<string>s;
        string name;
        cin>>name;
        s.setname(name);
        queue.Edit_Product(s);
    }
    else
        throw out_of_range("\n\t\t\t\tContainer IS Empty Can't Display.\n");
}
void Factory::search()
{
    if (!queue.isempty())
    {
        cout<<"Enter Stack Name To Search : ";
        Stack<string>s;
        string name;
        cin>>name;
        s.setname(name);
        queue.search(s);
    }
    else
        throw out_of_range("\n\t\t\t\tContainer IS Empty Can't Display.\n");
}
#endif
