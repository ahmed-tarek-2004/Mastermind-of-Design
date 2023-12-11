#include "Factory.h"
#include "Stack.h"
#include <string>
#include <iostream>
#include <string>
#include<iomanip>
using namespace std;
Factory factory;
void underline()
{
    for (int i = 0; i < 100; ++i) {
        cout << '-';
    }
    cout << "\n";
}
short ReadMainMeunOptions()
{
    short Choice;
    cout << setw(35) << left << "" << "Please Enter Your Choice :  ";
    cin >> Choice;
    while (Choice < 0 || Choice >5)
    {
        cout << "Chocie Out of Range, Please Enter Anthor One :  ";
        cin >> Choice;
    }
    return Choice;
}
int main()
{
    short Choice = 0;
    do
    {
        system("cls");
        cout << setw(35) << left << "" << "____________________________________________\n\n";
        cout << setw(35) << left << "" << "\t\tShow Main Menu\n";
        cout << setw(35) << left << "" << "___________________________________________\n\n";
        cout << setw(35) << left << "" << "=============================================\n";
        cout << setw(35) << left << "" << "\tSmart Factory Manufacturing Menu\n";
        cout << setw(35) << left << "" << "=============================================\n";
        cout << setw(35) << left << "" << "[1] Add Product.\n";
        cout << setw(35) << left << "" << "[2] Delete Product.\n";
        cout << setw(35) << left << "" << "[3] DisPlay Products.\n";
        cout << setw(35) << left << "" << "[4] Search Products.\n";
        cout << setw(35) << left << "" << "[5] Edit Product.\n";
        cout << setw(35) << left << "" << "[0] Logout.\n";
        cout << setw(35) << left << "" << "=============================================\n";
        Choice = ReadMainMeunOptions();
        switch (Choice)
        {
        case 1:
        {
            factory.add_product();
            break;
        }
        case 2:
        {
            system("cls");
            underline();
           factory.delete_product();
            underline();
            break;
        }
        case 3:
        {
            system("cls");
            // Print function
            underline();
           factory.display();
            underline();
            break;

        }
        case 4:
        {
            underline();
            factory.search();
            break;
        }
        case 5:
        {
            factory.EditProduct();
            break;
        }
        case 0:
        {
           // system("cls");
            cout << "\n\n";
            underline();
            cout <<"\t\t\t\t\t\tThank You\n";
            underline();
            return 0;
            break;
        }
        }
        cout << "Would You Like To Continue? ([1]-Continue / [0] Logout ) : ";
        cin >> Choice;
    } while (Choice);
    cin.get();
}
