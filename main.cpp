#include <QCoreApplication>
#include "personal.h"
#include <fstream>
#include <QtSql>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

void displayListSorted(Personal& list);
void searchForPerson(Personal& list);
void editingChoices(Personal& list);
void ownership(Personal& list);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Personal list;

    int user_choice;

    while(true)
    {
        cout << "1) Display the list" << endl
             << "2) Edit the list" << endl
             << "3) Display the list sorted" << endl
             << "4) Search the list" << endl
             << "5) Manage Ownerships" << endl
             << "6) Exit the program" << endl;

        cout << "Pick a number: ";
        cin >> user_choice;
        cin.ignore();                                         //þessi lína kemur í veg fyrir að það sendist inn empty input
        if (cin.fail())                                       //Checks if input is a number
        {
            cin.clear();
            cin.ignore(100, '\n');
        }
        cout << endl;


        if(user_choice == 1)
        {
            list.displayPersonal();
            cout << "What do you want to do next?" << endl;
        }
        if(user_choice == 2)
        {
            editingChoices(list);
            cout << "What do you want to do next?" << endl;
        }
        if (user_choice == 3)
        {
            displayListSorted(list);
            cout << "What do you want to do next?" << endl;
        }
        if(user_choice == 4)
        {
            searchForPerson(list);
            cout << "What do you want to do next?" << endl;
        }
        if(user_choice == 5)
        {
            ownership(list);
            cout << "What do you want to do next?" << endl;
        }
        if (user_choice == 6)
        {
            cout <<"Thank you for using the program!" << endl
                 <<"Goodbye!" << endl;
            exit(0);
        }

        if ((user_choice < 1) || (user_choice > 4))
        {
            cout <<"Wrong number!" << endl;
        }
    }
    return a.exec();
}

void ownership(Personal& list)
{
    int choice;

    cout << "1) Create ownership between computer and person" << endl
         << "2) Show ownerships" << endl
         << "Pick a number: ";
    cin >> choice;
    cin.ignore();                                         //þessi lína kemur í veg fyrir að það sendist inn empty input

    if (cin.fail())                                       //Checks if input is a number
    {
        cin.clear();
        cin.ignore(100, '\n');
    }
    cout << endl;

    if ((choice < 1) || (choice > 2))
    {
        cout <<"Wrong number!" << endl
             << "1) Create ownership between computer and person" << endl
             << "2) Show ownerships" << endl
             << "Pick a number: ";
        cin >> choice;
        cin.ignore();                                   //þessi lína kemur í veg fyrir að það sendist inn empty input
        if (cin.fail())                                 //Checks if input is a number
        {
            cin.clear();
            cin.ignore(100, '\n');
        }
        cout << endl;
    }

    if(choice == 1)
    {
        list.createOwnership();
    }
    if(choice == 2)
    {
       list.showOwnership();
    }
}


void searchForPerson(Personal& list)
{
    int choice;

    cout << "1) Find a famous person" << endl
         << "2) Find a famous computer" << endl
         << "Pick a number: ";
    cin >> choice;
    cin.ignore();                                         //þessi lína kemur í veg fyrir að það sendist inn empty input
    if (cin.fail())                                       //Checks if input is a number
    {
        cin.clear();
        cin.ignore(100, '\n');
    }
    cout << endl;

    while((choice != 1) && (choice != 2))
    {
        cout <<"Wrong number!" << endl
             << "1) Find a famous person" << endl
             << "2) Find a famous computer" << endl
             << "Pick a number: ";
        cin >> choice;
        cin.ignore();                                   //þessi lína kemur í veg fyrir að það sendist inn empty input
        if (cin.fail())                                 //Checks if input is a number
        {
            cin.clear();
            cin.ignore(100, '\n');
        }
        cout << endl;
    }
    if(choice == 1)
    {
        list.findByPerson();
    }
    else
    {
       list.findByComputer();
    }
}

void displayListSorted(Personal& list)
{
    while(true)
    {
         int sortChoice;
         cout << "How do you want the list sorted" << endl
              << "1) Sort by famous people" << endl
              << "2) Sort by famous computers" << endl
              << "Pick a number: ";

         cin >> sortChoice;
         cin.ignore();                                   //þessi lína kemur í veg fyrir að það sendist inn empty input
         if (cin.fail())                                 //Checks if input is a number
         {
             cin.clear();
             cin.ignore(100, '\n');
         }
         cout << endl;

         if((sortChoice != 1) && (sortChoice != 2))
         {
             cout <<"Wrong number!" << endl << endl;
         }
         else if(sortChoice == 1)
         {
             list.sortByPeople();
             break;
         }
         else if(sortChoice == 2)
         {
             list.sortByComputers();
             break;
         }
    }
}

void editingChoices(Personal& list)
{
    int listEdit;
    cout << "What do you want to do?" << endl
         << "1) Add a person to the list" << endl
         << "2) Add a computer to the list" << endl
         << "3) Remove a person from the list" << endl
         << "4) Remove a computer from the list" << endl
         << "Pick a number: ";
         cin >> listEdit;
         cin.ignore();                                              //þessi lína kemur í veg fyrir að það sendist inn empty input
         if (cin.fail())                                            //Checks if input is a number
         {
             cin.clear();
             cin.ignore(100, '\n');
         }
         while((listEdit < 1) || (listEdit > 4))
         {
             cout << "Wrong number!" << endl
                  << "Pick a number: ";
             cin >> listEdit;
             cin.ignore();                                         //þessi lína kemur í veg fyrir að það sendist inn empty input
             if (cin.fail())                                       //Checks if input is a number
             {
                 cin.clear();
                 cin.ignore(100, '\n');
             }
         }
         if(listEdit == 1)
         {
            cout << endl;
            list.addPersonal();
         }
         else if(listEdit == 2)
         {
             cout << endl;
             list.addComputer();
         }
         else if(listEdit == 3)
         {
             cout << endl;
             list.deletePersonal();
         }
         else
         {
             cout << endl;
             list.deleteComputer();
         }
}
