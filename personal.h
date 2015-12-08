#ifndef PERSONAL_H
#define PERSONAL_H

#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Personal
{
public:
    Personal();                                                              //List constructor

    void displayPersonal();                                                  //Displays the list of people

    void addPersonal();                                                      //Adds new person to the list
    void deletePersonal();                                                   //Removes a person from the list

    void sort(int choice);                                                   //Sorts the list depending on users choice

    void findbytype(string input, string type);                              //Searchs the list for names, genders, dates of births and deaths
};

#endif // PERSONAL_H
