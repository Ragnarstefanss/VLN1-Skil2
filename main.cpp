#include <QCoreApplication>
#include "personal.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

void displayListSorted(Personal& list);
void displaySortChoices();
void displayFindChoices();
void searchForPerson(Personal& list);
void editingChoices(Personal& list);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Personal list;
    list.loadPersonal();                                      //Loads input from text files into vectors
    int user_choice;

    while(true)
    {
        cout << "1) Display the list" << endl
             << "2) Edit the list" << endl
             << "3) Display the list sorted" << endl
             << "4) Search for a person in the list" << endl
             << "5) Exit the program" << endl;

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
        if (user_choice == 5)
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




void searchForPerson(Personal& list)
{
    string name, gender, birth_year, death_year, type;
    displayFindChoices();
    int choice;
    cout << "Pick a number: ";
    cin >> choice;
    cin.ignore();                                         //þessi lína kemur í veg fyrir að það sendist inn empty input
    if (cin.fail())                                       //Checks if input is a number
    {
        cin.clear();
        cin.ignore(100, '\n');
    }
    cout << endl;


    while((choice < 1) || (choice > 4))
    {
        cout <<"Wrong number!" << endl;
        displayFindChoices();
        cout << "Pick a number: ";
        cin >> choice;
        cin.ignore();                                   //þessi lína kemur í veg fyrir að það sendist inn empty input
        if (cin.fail())                                       //Checks if input is a number
        {
            cin.clear();
            cin.ignore(100, '\n');
        }
        cout << endl;
    }
    if(choice == 1)
    {
        type = "name";

        cout << "Search for the name: ";
        getline(cin, name);
        name[0] = toupper(name[0]);

        cout << endl;
        list.findbytype(name, type);
        cout << endl;
     }

   else if(choice == 2)
    {
        type = "gender";

        cout << "Search for gender: ";
        cin >> gender;
        gender[0] = toupper(gender[0]);

        list.findbytype(gender, type);
    }

    else if(choice == 3)
    {
        type = "birth";

        cout << "Search for birth year: ";
        cin >> birth_year;

        list.findbytype(birth_year, type);
    }

    else if(choice == 4)
    {
        type = "death";

        cout << "Search for death year: ";
        cin >> death_year;

        list.findbytype(death_year, type);
    }
}

void displayListSorted(Personal& list)
{
    while(true)
    {
         int sortChoice;
         displaySortChoices();
         cout << "Pick a number: ";
         cin >> sortChoice;
         cin.ignore();                                   //þessi lína kemur í veg fyrir að það sendist inn empty input
         if (cin.fail())                                       //Checks if input is a number
         {
             cin.clear();
             cin.ignore(100, '\n');
         }
         cout << endl;

         if((sortChoice < 1) || (sortChoice > 8))
         {
             cout <<"Wrong number!" << endl << endl;
         }
         else
         {
            list.sort(sortChoice);
            break;
         }
    }
}

void editingChoices(Personal& list)
{
    int listEdit;
    cout << "What do you want to do?" << endl
         << "1) Add a person to the list" << endl
         << "2) Remove a person from the list" << endl
         << "Pick a number: ";
         cin >> listEdit;
         cin.ignore();                                              //þessi lína kemur í veg fyrir að það sendist inn empty input
         if (cin.fail())                                            //Checks if input is a number
         {
             cin.clear();
             cin.ignore(100, '\n');
         }
         while((listEdit != 1) && (listEdit != 2))
         {
             cout <<"Choose either option 1 or 2!" << endl
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
         else
         {
             cout << endl;
             list.deletePersonal();
         }
}


void displaySortChoices()
{
    cout << "1) Sort by names in ascending order" << endl
         << "2) Sort by names in descending order" << endl
         << "3) Sort by gender: females" << endl
         << "4) Sort by gender: males" << endl
         << "5) Sort by year of birth in ascending order" << endl
         << "6) Sort by year of birth in descending order" << endl
         << "7) Sort by year of death in ascending order" << endl
         << "8) Sort by year of death in descending order" << endl;
}

void displayFindChoices()
{
    cout << "1) Search by name" << endl
         << "2) Search by gender" << endl
         << "3) Search by birth year" << endl
         << "4) Search by death year" << endl << endl;
}
