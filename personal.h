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

    void addComputer();                                                      //Adds new computer to the list
    void addPersonal();                                                      //Adds new person to the list
    void deletePersonal();                                                   //Removes a person from the list

    void sortByComputers();                                                  //Sorts the computers list depending on users choice
    void sortByPeople();                                                     //Sorts the people list depenging on users choice

    void findByComputer();                                                   //Searchs the list for names, genders, dates of births and deaths
    void findByPerson();

    void createOwnership();
    void showOwnership();
};

#endif // PERSONAL_H
