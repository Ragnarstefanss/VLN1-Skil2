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

    void addComputer();                                                      //Lets user add a new computer to the list
    void addPersonal();                                                      //Lets user add a new person to the list
    void deletePersonal();                                                   //Lets user remove a person from the list
    void deleteComputer();                                                   //Lets user removes a computer from the list

    void sortByComputers();                                                  //Sorts the computers list depending on users choice
    void sortByPeople();                                                     //Sorts the people list depenging on users choice

    void findByComputer();                                                   //Searches the list for a computer depending on users choice
    void findByPerson();                                                     //Searches the list for a person depending on users choice

    void createOwnership();
    void showOwnership();
};

#endif // PERSONAL_H
