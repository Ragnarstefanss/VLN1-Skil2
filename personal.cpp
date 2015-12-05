#include "personal.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <QtSql>

using namespace std;



Personal::Personal()
{

    // DATABASE
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "E:/Annad/VLN/Skil2/skil2.sqlite";
    db.setDatabaseName(dbName);
    db.open();

    vector<string> name;
    vector<string> gender;
    vector<string> birth;
    vector<string> death;
}



void Personal::loadPersonal()
{
    loadNames();
    loadGenders();
    loadBirths();
    loadDeaths();
}

void Personal::writePersonal()
{
    writeNames();
    writeGenders();
    writeBirths();
    writeDeaths();
}

void Personal::sort(int choice)
{
    sortedName = name;
    sortedGender = gender;
    sortedBirth = birth;
    sortedDeath = death;


    unsigned int sizeOfVector = sortedName.size();
    unsigned int reps = sortedName.size() - 1;

    string tempName, tempGender, tempBirth, tempDeath;

    if(sizeOfVector == 0)
    {
        cout << "Cant sort an empty list!" << endl;
    }
    else
    {
        sortDisplay(choice);
        for(unsigned int a = 0; a < reps; a++)
        {
            for(unsigned int i = 0; i < reps; i++)
            {
                if(choice == 1)
                {
                    if (sortedName[i] > sortedName[i+1])
                    {
                        sortingAlgorithm(i);
                    }
                }
                else if(choice == 2)
                {
                    if (sortedName[i] < sortedName[i+1])
                    {
                        sortingAlgorithm(i);
                    }
                }
                else if(choice == 3)
                {
                    if (sortedGender[i] > sortedGender[i+1])
                    {
                        sortingAlgorithm(i);
                    }
                }
                else if(choice == 4)
                {
                    if (sortedGender[i] < sortedGender[i+1])
                    {
                        sortingAlgorithm(i);
                    }
                }
                else if(choice == 5)
                {
                    if (sortedBirth[i] > sortedBirth[i+1])
                    {
                        sortingAlgorithm(i);
                    }
                }
                else if(choice == 6)
                {
                    if (sortedBirth[i] < sortedBirth[i+1])
                    {
                        sortingAlgorithm(i);
                    }
                }
                else if(choice == 7)
                {
                    if (sortedDeath[i] > sortedDeath[i+1])
                    {
                        sortingAlgorithm(i);
                    }
                }
                else if(choice == 8)
                {
                    if (sortedDeath[i] < sortedDeath[i+1])
                    {
                        sortingAlgorithm(i);
                    }
                }
             }
        }
        displaySorted();
    }

}

void Personal::displaySorted()
{
    for(unsigned int i = 0; i < sortedName.size();i++)
    {
        cout << "Name: " << sortedName[i] << endl
             << "Sex: " << sortedGender[i] << endl
             << "Born: " << sortedBirth[i] << endl
             << "Died: " << sortedDeath[i] << endl << endl;
    }
}

void Personal::deletePersonal()
{
    if(name.size() == 0)
    {
        cout << "There is nobody to remove!" << endl;
    }
    else
    {
        cout << "Who do you want to remove?" << endl;
        int a = 1;
        int pNumber;
        for(unsigned int i = 0; i < name.size();i++)
        {
            cout << a << ": " << name[i] << endl;
            a++;
        }
        cout << endl << "Write the number of the person you wish to remove: ";
        cin >> pNumber;
        if (cin.fail())                                                              //Checks if input is a number
        {
            cin.clear();
            cin.ignore(100, '\n');
        }

        while((pNumber) < 1 || (pNumber > a))
        {
            cout << "Choose a valid number from the list!" << endl
                 << "Write the number of the person you wish to remove: ";
            cin >> pNumber;
            if (cin.fail())                                                         //Checks if input is a number
            {
                cin.clear();
                cin.ignore(100, '\n');
            }
        }
        removalAlgorithm(pNumber);
        writePersonal();
        cout << "Removing complete!" << endl << endl;
    }
}

void Personal::addPersonal()
{
    string name, sex, birth, death;
    char c;

    NAME_LOOP:
    cout << "Enter the name of the person you wish to add: ";
    getline(cin, name);
    if(name == "")
    {
        cout << "No entry found!" << endl;
        cout << "Try again!" << endl << endl;
        goto NAME_LOOP;
    }

    for (unsigned int i = 0; i < name.length(); i++)
    {
        c = name.at(i);
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == ' '))
        {
                   //Right input
        }
        else
        {
            cout << "Only alphabetic letters and spaces are allowed!" << endl;
            cout << "Try again!" << endl << endl;
            goto NAME_LOOP;
        }
    }
    name[0] = toupper(name[0]);                                         //Makes the first character of a name a capital letter
    cout << endl;


    SEX_LOOP:
    cout << "Enter the gender: ";
    getline(cin, sex);

    while (sex == "")
    {
        cout << "No entry found!" << endl;
        cout << "Try again!" << endl << endl;
        goto SEX_LOOP;
    }

    while((sex != "Male") && (sex != "male") && (sex != "Female") && (sex != "female"))
    {
        cout << "Wrong input! Enter either male or female, no transsexuals allowed!" << endl;
        cout << "Try again!" << endl << endl;
        goto SEX_LOOP;
    }

    if(sex == "female")
    {
        sex[0] = toupper(sex[0]);
    }

    if(sex == "male")
    {
        sex[0] = toupper(sex[0]);
    }
    cout << endl;


    BIRTH_LOOP:
    cout << "Enter the year of birth: ";
    getline(cin, birth);
    while (birth == "")
    {
        cout << "No entry found!" << endl;
        cout << "Try again!" << endl << endl;
        goto BIRTH_LOOP;
    }
    if(birth.length() == 4)
    {
        for (unsigned int i = 0; i < birth.length(); i++)
        {
            c = birth.at(i);
            if ((c >= '0' && c <= '9'))
            {
                       //Right input
            }
            else
            {
                cout << "Wrong year input!" << endl;
                cout << "Input a year containing exactly four numbers!" << endl << endl;
                goto BIRTH_LOOP;
            }
        }
    }
    else
    {
        cout << "Wrong year input!" << endl;
        cout << "Input a year containing exactly four numbers!" << endl << endl;
        goto BIRTH_LOOP;
    }
    cout << endl;


    DEATH_LOOP:
    cout << "Enter the year of death (if person is still alive enter a '-' instead): ";
    getline(cin, death);
    while (death == "")
    {
        cout << "No entry found!" << endl;
        cout << "Try again!" << endl << endl;
        goto DEATH_LOOP;
    }
    if(death.length() == 4)
    {
        for (unsigned int i = 0; i < death.length(); i++)
        {
            c = death.at(i);
            if ((c >= '0' && c <= '9'))
            {
                       //Right input
            }
            else
            {
                cout << "Wrong year input!" << endl;
                cout << "Input a year containing exactly four numbers or a '-' "
                        "if the person is still alive" << endl << endl;
                goto DEATH_LOOP;
            }
        }
    }
    else if(death == "-")
    {
        //Right input
    }
    else
    {
        cout << "Wrong year input!" << endl;
        cout << "Input a year containing exactly four numbers or a '-' "
                "if the person is alive" << endl << endl;
        goto DEATH_LOOP;
    }
    cout << endl;

    pushNewPersonal(name, sex, birth, death);           //Pushes collected data to vectors
    writePersonal();                                    //Writes new vectors to text files
}

void Personal::pushNewPersonal(string nam, string sex, string birt, string deat)
{
    name.push_back(nam);
    gender.push_back(sex);
    birth.push_back(birt);
    death.push_back(deat);
}

void Personal::displayPersonal()
{
    QSqlQuery query;

    if(query.exec("SELECT name, gender, birth, death FROM persons"))
    {
        cout << "List of famous people: " << endl << endl;
        while(query.next()) {
            QString name   = query.value(0).toString();
            QString gender = query.value(1).toString();
            QString birth  = query.value(2).toString();
            QString death  = query.value(3).toString();
            qDebug() << "Name:" << name << endl
                     << "Sex:" << gender << endl
                     << "Born:" << birth << endl
                     << "Died:" << death << endl;
        }

    }
    else {
        cout << "No people to display!" << endl;
    }
}

void Personal::writeNames()
{
    ofstream writeNames("names.txt");
    if (writeNames.is_open())
    {
        for(unsigned int i = 0; i < name.size(); i++)
        {
            writeNames << name[i] << "\n";
        }
    writeNames.close();
    }
}

void Personal::writeGenders()
{
    ofstream writeGenders("genders.txt");
    if (writeGenders.is_open())
    {
        for(unsigned int i = 0; i < gender.size(); i++)
        {
            writeGenders << gender[i] << "\n";
        }
    writeGenders.close();
    }
}

void Personal::writeBirths()
{
    ofstream writeBirths("births.txt");
    if (writeBirths.is_open())
    {
        for(unsigned int i = 0; i < birth.size(); i++)
        {
            writeBirths << birth[i] << "\n";
        }
    writeBirths.close();
    }
}

void Personal::writeDeaths()
{
    ofstream writeDeaths("deaths.txt");
    if (writeDeaths.is_open())
    {
        for(unsigned int i = 0; i < death.size(); i++)
        {
            writeDeaths << death[i] << "\n";
        }
    writeDeaths.close();
    }
}

void Personal::loadNames()
{
    ifstream readNames("names.txt");
    string line;
    if(!readNames) //Tests if file open
    {
        cout << "Error opening names.txt file" << endl;
        exit(0);
    }

    while (getline(readNames, line))
    {
        line[0] = toupper(line[0]);                                //Makes the first character of a name a capital letter
        name.push_back(line);
    }
}

void Personal::loadGenders()
{
    ifstream readGenders("genders.txt");
    string line;
    if(!readGenders) //Tests if file open
    {
        cout << "Error opening genders.txt file" << endl;
        exit(0);
    }

    while (getline(readGenders, line))
    {
        if (line == "female")
        {
            line[0] = toupper(line[0]);
        }
        if (line == "male")
        {
            line[0] = toupper(line[0]);
        }
        gender.push_back(line);
    }

}

void Personal::loadBirths()
{
    ifstream readBirths("births.txt");
    string line;
    if(!readBirths) //Test if file open
    {
        cout << "Error opening births.txt file" << endl;
        exit(0);
    }

    while (getline(readBirths, line))
    {
        birth.push_back(line);
    }
}

void Personal::loadDeaths()
{
    ifstream readDeaths("deaths.txt");
    string line;
    if(!readDeaths) //Test if file open
    {
        cout << "Error opening deaths.txt file" << endl;
        exit(0);
    }

    while (getline(readDeaths, line))
    {
        death.push_back(line);
    }
}

void Personal::sortingAlgorithm(int i)
{
    string tempName, tempGender, tempBirth, tempDeath;

    tempName = sortedName[i];
    tempGender = sortedGender[i];
    tempBirth = sortedBirth[i];
    tempDeath = sortedDeath[i];

    sortedName[i] = sortedName[i+1];
    sortedGender[i] = sortedGender[i+1];
    sortedBirth[i] = sortedBirth[i+1];
    sortedDeath[i] = sortedDeath[i+1];

    sortedName[i+1] = tempName;
    sortedGender[i+1] = tempGender;
    sortedBirth[i+1] = tempBirth;
    sortedDeath[i+1] = tempDeath;
}

void Personal::removalAlgorithm(int pNumber)
{
    pNumber = pNumber - 1;
    name.erase (name.begin()+ pNumber);
    gender.erase (gender.begin()+ pNumber);
    birth.erase (birth.begin()+ pNumber);
    death.erase (death.begin()+ pNumber);
}

void Personal::sortDisplay(int s)
{
    if(s == 1)
    {
        cout << "List sorted by names in ascending order:" << endl;
    }
    if(s == 2)
    {
        cout << "List sorted by names in descending order:" << endl;
    }
    if(s == 3)
    {
        cout << "List sorted by gender(female):" << endl;
    }
    if(s == 4)
    {
        cout << "List sorted by gender(male):" << endl;
    }
    if(s == 5)
    {
        cout << "List sorted by year of birth(ascending):" << endl;
    }
    if(s == 6)
    {
        cout << "List sorted by year of birth(descending):" << endl;
    }
    if(s == 7)
    {
        cout << "List sorted by year of death(ascending):" << endl;
    }
    if(s == 8)
    {
        cout << "List sorted by year of birth(descending):" << endl;
    }
}

void Personal::findbytype(string input, string type)
{
    bool name_found = false;
    if(name.size() == 0)
    {
        cout << "No person matched that search string!" << endl << endl;
    }
    else
    {
        string temp, searchedName;
        for(unsigned int i = 0; i < name.size();i++)
        {
            if(type == "name")
            {
                temp = name[i];
                for(unsigned int g = 0; g < input.size(); g++)
                {
                    if (input[g] == temp[g])
                    {
                        //Character in input string number 'g' is the same as character number g in
                        //the name we are looking for.
                    }
                    else
                    {
                        break;
                    }
                    if(g == input.size() - 1)
                    {
                        searchedName = temp;     //Found all characters
                    }
                }
            }
            else if(type == "gender")
            {
                temp = gender[i];
            }
            else if(type == "birth")
            {
                temp = birth[i];
            }
            else if(type == "death")
            {
                temp = death[i];
            }

            if(input == temp || searchedName == temp)
            {
               cout << "Name: " << name[i] << endl
                    << "Sex: " << gender[i] << endl
                    << "Born: " << birth[i] << endl
                    << "Died: " << death[i] << endl << endl;
                name_found = true;
            }
        }
        if(name_found == false)
        {
            cout << "Person does not exist" << endl << endl;
        }
     }
}
