#include "personal.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <QtSql>
#include <windows.h>

using namespace std;


Personal::Personal()
{

    // DATABASE
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "C:/Users/Lenovo/Desktop/Lokaverkefni2/VLN1-Skil2/Database/skil2.sqlite";
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


void Personal::sortByComputers()
{
    int choice;

    cout << "1) Sort by names in ascending order" << endl
         << "2) Sort by names in descending order" << endl
         << "3) Sort by building year in ascending order" << endl
         << "4) Sort by building year in descending order" << endl
         << "5) Sort by computer type in ascending order" << endl
         << "6) Sort by computer type in descending order" << endl
         << "7) Sort by computers that were built" << endl
         << "8) Sort by computers that were not built" << endl;
    cin >> choice;
    cin.ignore();                                   //þessi lína kemur í veg fyrir að það sendist inn empty input
    if (cin.fail())                                 //Checks if input is a number
    {
        cin.clear();
        cin.ignore(100, '\n');
    }

    while((choice < 1) || (choice > 8))
    {
        cout <<"Wrong number!" << endl
             << "1) Sort by names in ascending order" << endl
             << "2) Sort by names in descending order" << endl
             << "3) Sort by building year in ascending order" << endl
             << "4) Sort by building year in descending order" << endl
             << "5) Sort by computer type in ascending order" << endl
             << "6) Sort by computer type in descending order" << endl
             << "7) Sort by computers that were built" << endl
             << "8) Sort by computers that were not built" << endl;
        cin >> choice;
        cin.ignore();                                   //þessi lína kemur í veg fyrir að það sendist inn empty input
        if (cin.fail())                                 //Checks if input is a number
        {
            cin.clear();
            cin.ignore(100, '\n');
        }
        cout << endl;
    }


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

void Personal::sortByPeople()
{
    int choice;

    cout << "1) Sort by names in ascending order" << endl
         << "2) Sort by names in descending order" << endl
         << "3) Sort by males" << endl
         << "4) Sort by females" << endl
         << "5) Sort by year of birth in ascending order" << endl
         << "6) Sort by year of birth in descending order" << endl
         << "7) Sort by year of death in ascending order" << endl
         << "8) Sort by year of death in descending order" << endl;
    cin >> choice;
    cin.ignore();                                   //þessi lína kemur í veg fyrir að það sendist inn empty input
    if (cin.fail())                                 //Checks if input is a number
    {
        cin.clear();
        cin.ignore(100, '\n');
    }

    while((choice < 1) || (choice > 8))
    {
        cout <<"Wrong number!" << endl
             << "1) Sort by names in ascending order" << endl
             << "2) Sort by names in descending order" << endl
             << "3) Sort by males" << endl
             << "4) Sort by females" << endl
             << "5) Sort by year of birth in ascending order" << endl
             << "6) Sort by year of birth in descending order" << endl
             << "7) Sort by year of death in ascending order" << endl
             << "8) Sort by year of death in descending order" << endl;
        cin >> choice;
        cin.ignore();                                   //þessi lína kemur í veg fyrir að það sendist inn empty input
        if (cin.fail())                                 //Checks if input is a number
        {
            cin.clear();
            cin.ignore(100, '\n');
        }
        cout << endl;
    }


    QSqlQuery query;
    if(choice == 1)
    {
        query.exec("SELECT name, gender, birth, death FROM persons ORDER BY name ASC");
        cout << "List of famous people sorted by name(ASC): " << endl << endl;
        displayPersonalInformation(query);
    }

    if(choice == 2)
    {
        query.exec("SELECT name, gender, birth, death FROM persons ORDER BY name DESC");
        cout << "List of famous people sorted by name(DESC): " << endl << endl;
        displayPersonalInformation(query);
    }

    if(choice == 3)
    {
       query.exec("SELECT name, gender, birth, death FROM persons ORDER BY gender DESC");
       cout << "List of famous people sorted by gender(Male): " << endl << endl;
       displayPersonalInformation(query);
    }

    if(choice == 4)
    {
       query.exec("SELECT name, gender, birth, death FROM persons ORDER BY gender ASC");
       cout << "List of famous people sorted by gender(Female): " << endl << endl;
       displayPersonalInformation(query);
    }

    if(choice == 5)
    {
       query.exec("SELECT name, gender, birth, death FROM persons ORDER BY birth ASC");
       cout << "List of famous people sorted by birth year(ASC): " << endl << endl;
       displayPersonalInformation(query);
    }

    if(choice == 6)
    {
        query.exec("SELECT name, gender, birth, death FROM persons ORDER BY birth DESC");
        cout << "List of famous people sorted by birth year(DESC): " << endl << endl;
        displayPersonalInformation(query);
     }

    if(choice == 7)
    {
        query.exec("SELECT name, gender, birth, death FROM persons ORDER BY death ASC");
        cout << "List of famous people sorted by death year(ASC): " << endl << endl;
        displayPersonalInformation(query);
    }

    if(choice == 8)
    {
        query.exec("SELECT name, gender, birth, death FROM persons ORDER BY death DESC");
        cout << "List of famous people sorted by death year(DESC): " << endl << endl;
        displayPersonalInformation(query);
    }
}




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

// ownership
void Personal::createOwnership()
{
    cout << "Choose an id for desired computer";
    Sleep(2000); // læt forritið bíða í 2 sek svo það sé hægt að lesa línuna fyrir ofan

    QSqlQuery query;
    query.exec("SELECT id, name, building_year, type FROM Tolvur");

    while(query.next())
    {
        QString id   = query.value(0).toString();
        QString name = query.value(1).toString();
        QString building_year  = query.value(2).toString();
        QString type  = query.value(3).toString();
        qDebug() << "ID:" << id << endl
                 << "Name:" << name << endl
                 << "Building Year:" << building_year << endl
                 << "Type:" << type << endl;
    }


    int talva_id;
    cout << "ID: ";
    cin >> talva_id;

    cout << endl;

    cout << "Choose an id for desired person" << endl;
    Sleep(2000); // læt forritið bíða í 2 sek svo það sé hægt að lesa línuna fyrir ofan

    QSqlQuery query2;
    query2.exec("SELECT id, name, gender, birth, death FROM persons");

    while(query2.next())
    {
        QString name   = query2.value(0).toString();
        QString gender = query2.value(1).toString();
        QString birth  = query2.value(2).toString();
        QString death  = query2.value(3).toString();
        qDebug() << "Name:" << name << endl
                 << "Gender:" << gender << endl
                 << "Birth year:" << birth << endl
                 << "Death year:" << death << endl;
    }

    int person_id;
    cout << "ID: ";
    cin >> person_id;

    QSqlQuery sendainn;

    sendainn.prepare("INSERT INTO ownership (tolvu_id, persons_id) VALUES (:talva_id,:person_id)");
    sendainn.bindValue(":talva_id", talva_id);
    sendainn.bindValue(":person_id", person_id);

    if(sendainn.exec())
    {
       cout << "Ownership has been created" << endl;
    }
    else
    {
        cout << "Could not send data" << endl;
    }

}

void Personal::showOwnership()
{
    QSqlQuery query;
    query.exec("SELECT t.name, p.name FROM ownership own JOIN persons p ON p.id = own.persons_id JOIN Tolvur t ON t.id = own.tolvu_id");

    while(query.next())
    {
        QString talva_name   = query.value(0).toString();
        QString person_name = query.value(1).toString();
        qDebug() << "Computer name:" << talva_name << endl
                 << "Person name:" << person_name << endl;
    }
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


void Personal::findByComputer()
{
    string input, type;
    string name, building_year, built, comp_type;
    int choice;

    cout << "1) Search by name" << endl
         << "2) Search by building year" << endl
         << "3) Search by computer type" << endl
         << "4) Search by built" << endl << endl
         << "Pick a number: ";
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
        cout <<"Wrong number!" << endl
             << "1) Search by name" << endl
             << "2) Search by building year" << endl
             << "3) Search by computer type" << endl
             << "4) Search by built" << endl << endl
             << "Pick a number: ";
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
        input = name;
        cout << endl;
     }

   else if(choice == 2)
    {
        type = "building_year";

        cout << "Search by building year: ";
        cin >> building_year;
        input = building_year;
        cout << endl;
    }

    else if(choice == 3)
    {
        type = "type";

        cout << "Search by type: ";
        cin >> comp_type;
        input = comp_type;
        cout << endl;
    }

    else if(choice == 4)
    {
        type = "built";

        cout << "Search by built: ";
        cin >> built;
        input = built;
        cout << endl;
    }

    QString qinput(input.c_str());
    QString qtype(type.c_str());

    QSqlQuery query;
    query.prepare("SELECT name, building_year, type, built FROM Tolvur WHERE "+ qtype + " LIKE '"+qinput+"%'");
    query.exec();

    if (!query.exec())
            qDebug() << query.lastError();

    displayInformation(query);
}

void Personal::findByPerson()
{
    string input, type;
    string name, gender, birth, death;
    int choice;

    cout << "1) Search by name" << endl
         << "2) Search by genderr" << endl
         << "3) Search by birth year" << endl
         << "4) Search by death year" << endl << endl
         << "Pick a number: ";
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
        cout << "1) Search by name" << endl
             << "2) Search by gender" << endl
             << "3) Search by birth year" << endl
             << "4) Search by death year" << endl << endl
             << "Pick a number: ";
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
        input = name;
        cout << endl;
     }

   else if(choice == 2)
    {
        type = "gender";

        cout << "Search by gender: ";
        cin >> gender;
        input = gender;
        cout << endl;
    }

    else if(choice == 3)
    {
        type = "birth";

        cout << "Search by birth year: ";
        cin >> birth;
        input = birth;
        cout << endl;
    }

    else if(choice == 4)
    {
        type = "death";

        cout << "Search by death year: ";
        cin >> death;
        input = death;
        cout << endl;
    }

    QString qinput(input.c_str());
    QString qtype(type.c_str());

    QSqlQuery query;
    query.prepare("SELECT name, gender, birth, death FROM persons WHERE "+ qtype + " LIKE '"+qinput+"%'");
    query.exec();


    if (!query.exec())
            qDebug() << query.lastError();

    displayPersonalInformation(query);
}

void Personal::deletePersonal()
{
    QSqlQuery query;
    string deletedName;
    int a = 1;
    int pNumber, deleteID;

    query.exec("SELECT name, gender, birth, death FROM persons");

    while(query.next())
    {
        QString name   = query.value(0).toString();
        cout << a << ": ";
        qDebug() << name << endl;
        a++;
    }
    a--;
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

    query.exec("SELECT id, name, gender, birth, death FROM persons");
        a = 1;
        while(query.next())
        {
           int id         = query.value(0).toInt();
           QString name   = query.value(1).toString();
           qDebug() << name << endl;
           if(a == pNumber)
           {
               deletedName = name.toLocal8Bit().constData();
               deleteID = id;
           }
           a++;
        }

        QString qnamey(deletedName.c_str());


        query.prepare("DELETE FROM ownership WHERE persons_id= :ID");
        query.bindValue(":ID", deleteID);
        query.exec();
        query.prepare("DELETE FROM persons WHERE name LIKE '"+qnamey+"%'");
        query.exec();

        cout << "Removing complete!" << endl << endl;

    }


    void Personal::deleteComputer()
    {
        QSqlQuery query;
        string deletedName;
        int a = 1;
        int pNumber, deleteID;

        query.exec("SELECT name, building_year, type, built FROM Tolvur");

        while(query.next())
        {
            QString name   = query.value(0).toString();
            cout << a << ": ";
            qDebug() << name << endl;
            a++;
        }
        a--;
        cout << endl << "Write the number of the computer you wish to remove: ";
        cin >> pNumber;
        if (cin.fail())                                                              //Checks if input is a number
        {
            cin.clear();
            cin.ignore(100, '\n');
        }

        while((pNumber) < 1 || (pNumber > a))
        {
            cout << "Choose a valid number from the list!" << endl
                 << "Write the number of the computer you wish to remove: ";
            cin >> pNumber;
            if (cin.fail())                                                         //Checks if input is a number
            {
                cin.clear();
                cin.ignore(100, '\n');
            }
         }

        query.exec("SELECT id, name, building_year, type, built FROM Tolvur");
        a = 1;
        while(query.next())
        {
           int id         = query.value(0).toInt();
           QString name   = query.value(1).toString();
           qDebug() << name << endl;
           if(a == pNumber)
           {
               deletedName = name.toLocal8Bit().constData();
               deleteID = id;
           }
           a++;
        }

        QString qnamey(deletedName.c_str());

        query.prepare("DELETE FROM ownership WHERE tolvu_id= :ID");
        query.bindValue(":ID", deleteID);
        query.exec();

        query.prepare("DELETE FROM Tolvur WHERE name LIKE '"+qnamey+"%'");
        query.exec();
        cout << "Removing complete!" << endl << endl;
    }
