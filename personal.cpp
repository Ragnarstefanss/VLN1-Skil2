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
    QString dbName = "/Database/skil2.sqlite";
    //QString dbName = "skil2.sqlite";
    db.setDatabaseName(dbName);
    db.open();
    QSqlQuery query(db);
}

void displayInformation(QSqlQuery query)
{
    while(query.next())
    {
        QString name   = query.value(0).toString();
        QString building_year = query.value(1).toString();
        QString type  = query.value(2).toString();
        QString built  = query.value(3).toString();
        qDebug() << "Name:" << name << endl
                 << "Building Year:" << building_year << endl
                 << "Type:" << type << endl
                 << "Built(0 = No/1 = Yes):" << built << endl;
    }
}

void displayPersonalInformation(QSqlQuery query)
{
    while(query.next())
    {
        QString name   = query.value(0).toString();
        QString gender = query.value(1).toString();
        QString birth  = query.value(2).toString();
        QString death  = query.value(3).toString();
        qDebug() << "Name:" << name << endl
                 << "Gender:" << gender << endl
                 << "Birth year:" << birth << endl
                 << "Death year:" << death << endl;
    }
}


void Personal::sort(int choice)
{
   QSqlQuery query;
   if(choice == 1)
   {
       query.exec("SELECT name, building_year, type, built FROM Tolvur ORDER BY name ASC");
       cout << "List of famous computers sorted by name(ASC): " << endl << endl;
       displayInformation(query);
   }

   if(choice == 2)
   {
       query.exec("SELECT name, building_year, type, built FROM Tolvur ORDER BY name DESC");
       cout << "List of famous computers sorted by name(DESC): " << endl << endl;
       displayInformation(query);
   }

   if(choice == 3)
   {
      query.exec("SELECT name, building_year, type, built FROM Tolvur ORDER BY building_year ASC");
      cout << "List of famous computers sorted by builth year(ASC): " << endl << endl;
      displayInformation(query);
   }

   if(choice == 4)
   {
      query.exec("SELECT name, building_year, type, built FROM Tolvur ORDER BY building_year DESC");
      cout << "List of famous computers sorted by builth year(DESC): " << endl << endl;
      displayInformation(query);
   }

   if(choice == 5)
   {
      query.exec("SELECT name, building_year, type, built FROM Tolvur ORDER BY type ASC");
      cout << "List of famous computers sorted by type(ASC): " << endl << endl;
      displayInformation(query);
   }

   if(choice == 6)
   {
       query.exec("SELECT name, building_year, type, built FROM Tolvur ORDER BY type DESC");
       cout << "List of famous computers sorted by type(DESC): " << endl << endl;
       displayInformation(query);
    }

   if(choice == 7)
   {
       query.exec("SELECT name, building_year, type, built FROM Tolvur ORDER BY built DESC");
       cout << "List of famous computers sorted by computers that were built: " << endl << endl;
       displayInformation(query);
   }

   if(choice == 8)
   {
       query.exec("SELECT name, building_year, type, built FROM Tolvur ORDER BY built ASC");
       cout << "List of famous computers sorted by computers that were not built: " << endl << endl;
       displayInformation(query);
   }
}
/*

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

*/
void Personal::addComputer()
{
    QSqlQuery query;

    string name, type, buildYR, pcBuilt;
    int building_year;
    bool built;
    char c;


    NAME_LOOP:
    cout << "Enter the name of the computer you wish to add: ";
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


    YEAR_LOOP:
    cout << "Enter the year the computer was built: ";
    getline(cin, buildYR);

    while (buildYR == "")
    {
        cout << "No entry found!" << endl;
        cout << "Try again!" << endl << endl;
        goto YEAR_LOOP;
    }

    if(buildYR.length() == 4)
    {
        for (unsigned int i = 0; i < buildYR.length(); i++)
        {
            c = buildYR.at(i);
            if ((c >= '0' && c <= '9'))
            {
                       //Right input
            }
            else
            {
                cout << "Wrong year input!" << endl;
                cout << "Input a year containing exactly four numbers!" << endl << endl;
                goto YEAR_LOOP;
            }
        }
    }
    else
    {
        cout << "Wrong year input!" << endl;
        cout << "Input a year containing exactly four numbers!" << endl << endl;
        goto YEAR_LOOP;
    }
    building_year = atoi(buildYR.c_str());
    cout << endl;


    TYPE_LOOP:
    cout << "Enter the type of the computer: ";
    getline(cin, type);
    while (type == "")
    {
        cout << "No entry found!" << endl;
        cout << "Try again!" << endl << endl;
        goto TYPE_LOOP;
    }
    for (unsigned int i = 0; i < type.length(); i++)
    {
        c = type.at(i);
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == ' '))
        {
                   //Right input
        }
        else
        {
            cout << "Only alphabetic letters and spaces are allowed!" << endl;
            cout << "Try again!" << endl << endl;
            goto TYPE_LOOP;
        }
    }
    type[0] = toupper(type[0]);                                         //Makes the first character of a name a capital letter
    cout << endl;


    BUILT_LOOP:
    cout << "Enter whether the computer was built(YES/NO): ";
    getline(cin, pcBuilt);
    while (pcBuilt == "")
    {
        cout << "No entry found!" << endl;
        cout << "Try again!" << endl << endl;
        goto BUILT_LOOP;
    }

    while((pcBuilt != "Yes") && (pcBuilt != "yes") && (pcBuilt != "YES") && (pcBuilt != "No") && (pcBuilt != "no") && (pcBuilt != "NO"))
    {
        cout << "Wrong input! Enter either yes or no!" << endl;
        cout << "Try again!" << endl << endl;
        goto BUILT_LOOP;
    }

    if((pcBuilt == "Yes") || (pcBuilt == "yes") || (pcBuilt == "YES"))
    {
        pcBuilt[0] = toupper(pcBuilt[0]);
        built = true;
    }

    if((pcBuilt == "No") || (pcBuilt == "no") || (pcBuilt == "NO"))
    {
        pcBuilt[0] = toupper(pcBuilt[0]);
        built = false;
    }
    cout << endl;



    QString qname(name.c_str());
    QString qtype(type.c_str());
    query.prepare("INSERT INTO Tolvur (name, building_year, type, built) VALUES (:name, :building_year, :type, :built)");
    query.bindValue(":name", qname);
    query.bindValue(":building_year", building_year);
    query.bindValue(":type", qtype);
    query.bindValue(":built", built);

    query.exec();
}

void Personal::addPersonal()
{
    QSqlQuery query;

    string name, gender, birth, death;
    int birthINT;
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
    getline(cin, gender);

    while (gender == "")
    {
        cout << "No entry found!" << endl;
        cout << "Try again!" << endl << endl;
        goto SEX_LOOP;
    }

    while((gender != "Male") && (gender != "male") && (gender != "Female") && (gender != "female"))
    {
        cout << "Wrong input! Enter either male or female, no transsexuals allowed!" << endl;
        cout << "Try again!" << endl << endl;
        goto SEX_LOOP;
    }

    if(gender == "female")
    {
        gender[0] = toupper(gender[0]);
    }

    if(gender == "male")
    {
        gender[0] = toupper(gender[0]);
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
    birthINT = atoi(birth.c_str());
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

    QString qname(name.c_str());
    QString qgender(gender.c_str());
    QString qdeath(death.c_str());
    query.prepare("INSERT INTO persons (name, gender, birth, death) VALUES (:name, :gender, :birthINT, :death)");
    query.bindValue(":name", qname);
    query.bindValue(":gender", qgender);
    query.bindValue(":birthINT", birthINT);
    query.bindValue(":death", qdeath);

    query.exec();
}

void Personal::displayPersonal()
{
    int choice;

    cout << "Choose the list you wish to display:" << endl
         << "1) List of famous people" << endl
         << "2) List of famous computers" << endl
         << "Pick a number: ";
    cin >> choice;
    cin.ignore();                                         //þessi lína kemur í veg fyrir að það sendist inn empty input
    if (cin.fail())                                       //Checks if input is a number
    {
        cin.clear();
        cin.ignore(100, '\n');
    }

    while((choice != 1) && (choice != 2))
    {
        cout <<"Choose either option 1 or 2!" << endl
             <<"Pick a number: ";
        cin >> choice;
        cin.ignore();                                         //þessi lína kemur í veg fyrir að það sendist inn empty input
        if (cin.fail())                                       //Checks if input is a number
        {
            cin.clear();
            cin.ignore(100, '\n');
        }
    }

    if (choice == 1)
    {
        QSqlQuery query;
        query.exec("SELECT name, gender, birth, death FROM persons");
        cout << "List of famous people: " << endl << endl;
        displayPersonalInformation(query);
    }

    else
    {
        QSqlQuery query;
        query.exec("SELECT name, building_year, type, built FROM Tolvur");
        cout << "List of famous computers: " << endl << endl;
        displayInformation(query);
    }
}


void Personal::findbytype(string input, string type)
{
    QString qinput(input.c_str());
    QString qtype(type.c_str());

    QSqlQuery query;
    query.prepare("SELECT name, building_year, type, built FROM Tolvur WHERE "+ qtype + " LIKE '"+qinput+"%'");
    query.exec();


    if (!query.exec())
            qDebug() << query.lastError();

    displayInformation(query);
}

