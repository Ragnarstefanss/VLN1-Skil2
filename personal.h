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
    void loadPersonal();                                                     //Loads input from files into vector
    void loadNames();                                                        //Loads names.txt into name vector
    void loadGenders();                                                      //Loads genders.txt into gender vector
    void loadBirths();                                                       //Loads births.txt into birth vector
    void loadDeaths();                                                       //Loads deaths.txt into death vector

    void displayPersonal();                                                  //Displays the list of people
    void displaySorted();                                                    //Displays the sorted list

    void addPersonal();                                                      //Adds new person to the list
    void deletePersonal();                                                   //Removes a person from the list
    void pushNewPersonal(string nam, string sex, string birt, string deat);  //Pushes new person into vectors
    void removalAlgorithm(int pNumber);                                      //Removal magic happens in this function

    void writePersonal();                                                    //Writes all vectors into text files
    void writeNames();                                                       //Writes name vector into names.txt
    void writeGenders();                                                     //Writes gender vector into genders.txt
    void writeBirths();                                                      //Writes births vector into births.txt
    void writeDeaths();                                                      //Writes deaths vector into deaths.txt

    void sort(int choice);                                                   //Sorts the list depending on users choice
    void sortingAlgorithm(int i);                                            //This function inholds all the sorting magic
    void sortDisplay(int s);                                                 //Displays sorting information

    void findbytype(string input, string type);                              //Searchs the list for names, genders, dates of births and deaths


private:
    vector<string> name;
    vector<string> gender;
    vector<string> birth;
    vector<string> death;

    vector<string> sortedName;
    vector<string> sortedGender;
    vector<string> sortedBirth;
    vector<string> sortedDeath;
};

#endif // PERSONAL_H
