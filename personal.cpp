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
    QString dbName = "E:/Annad/VLN/VLN1-Skil2/Database/skil2.sqlite";
    db.setDatabaseName(dbName);
    db.open();
    QSqlQuery query(db);
}


void Personal::sort(int choice)
{

   QSqlQuery query;
   if(choice == 1)
   {
      if(query.exec("SELECT name, building_year, type, built FROM Tolvur ORDER BY name ASC"))
      {
          cout << "List of famous computers: " << endl << endl;
          while(query.next())
          {
              QString name   = query.value(0).toString();
              QString building_year = query.value(1).toString();
              QString type  = query.value(2).toString();
              QString built  = query.value(3).toString();
              qDebug() << "Name:" << name << endl
                       << "Building Year:" << building_year << endl
                       << "Type:" << type << endl
                        << "Built:" << built << endl;
           }
        }

      else {
         cout << "No computers to display!" << endl;
       }

     }
   if(choice == 2)
   {
      if(query.exec("SELECT name, building_year, type, built FROM Tolvur ORDER BY name DESC"))
      {
          cout << "List of famous computers: " << endl << endl;
          while(query.next())
          {
              QString name   = query.value(0).toString();
              QString building_year = query.value(1).toString();
              QString type  = query.value(2).toString();
              QString built  = query.value(3).toString();
              qDebug() << "Name:" << name << endl
                       << "Building Year:" << building_year << endl
                       << "Type:" << type << endl
                        << "Built:" << built << endl;
           }
        }

      else {
         cout << "No computers to display!" << endl;
       }

     }

   if(choice == 3)
   {
      if(query.exec("SELECT name, building_year, type, built FROM Tolvur ORDER BY building_year ASC"))
      {
          cout << "List of famous computers: " << endl << endl;
          while(query.next())
          {
              QString name   = query.value(0).toString();
              QString building_year = query.value(1).toString();
              QString type  = query.value(2).toString();
              QString built  = query.value(3).toString();
              qDebug() << "Name:" << name << endl
                       << "Building Year:" << building_year << endl
                       << "Type:" << type << endl
                        << "Built:" << built << endl;
           }
        }

      else {
         cout << "No computers to display!" << endl;
       }

     }

   if(choice == 4)
   {
      if(query.exec("SELECT name, building_year, type, built FROM Tolvur ORDER BY building_year DESC"))
      {
          cout << "List of famous computers: " << endl << endl;
          while(query.next())
          {
              QString name   = query.value(0).toString();
              QString building_year = query.value(1).toString();
              QString type  = query.value(2).toString();
              QString built  = query.value(3).toString();
              qDebug() << "Name:" << name << endl
                       << "Building Year:" << building_year << endl
                       << "Type:" << type << endl
                        << "Built:" << built << endl;
           }
        }

      else {
         cout << "No computers to display!" << endl;
       }

   }

   if(choice == 5)
   {
      if(query.exec("SELECT name, building_year, type, built FROM Tolvur ORDER BY type ASC"))
      {
          cout << "List of famous computers: " << endl << endl;
          while(query.next())
          {
              QString name   = query.value(0).toString();
              QString building_year = query.value(1).toString();
              QString type  = query.value(2).toString();
              QString built  = query.value(3).toString();
              qDebug() << "Name:" << name << endl
                       << "Building Year:" << building_year << endl
                       << "Type:" << type << endl
                        << "Built:" << built << endl;
           }
        }

      else {
         cout << "No computers to display!" << endl;
       }

     }

   if(choice == 6)
   {
      if(query.exec("SELECT name, building_year, type, built FROM Tolvur ORDER BY type DESC"))
      {
          cout << "List of famous computers: " << endl << endl;
          while(query.next())
          {
              QString name   = query.value(0).toString();
              QString building_year = query.value(1).toString();
              QString type  = query.value(2).toString();
              QString built  = query.value(3).toString();
              qDebug() << "Name:" << name << endl
                       << "Building Year:" << building_year << endl
                       << "Type:" << type << endl
                        << "Built:" << built << endl;
           }
        }

      else {
         cout << "No computers to display!" << endl;
       }

     }

   if(choice == 7)
   {
      if(query.exec("SELECT name, building_year, type, built FROM Tolvur ORDER BY built DESC"))
      {
          cout << "List of famous computers: " << endl << endl;
          while(query.next())
          {
              QString name   = query.value(0).toString();
              QString building_year = query.value(1).toString();
              QString type  = query.value(2).toString();
              QString built  = query.value(3).toString();
              qDebug() << "Name:" << name << endl
                       << "Building Year:" << building_year << endl
                       << "Type:" << type << endl
                        << "Built:" << built << endl;
           }
        }

      else {
         cout << "No computers to display!" << endl;
       }

     }

   if(choice == 8)
   {
      if(query.exec("SELECT name, building_year, type, built FROM Tolvur ORDER BY built ASC"))
      {
          cout << "List of famous computers: " << endl << endl;
          while(query.next())
          {
              QString name   = query.value(0).toString();
              QString building_year = query.value(1).toString();
              QString type  = query.value(2).toString();
              QString built  = query.value(3).toString();
              qDebug() << "Name:" << name << endl
                       << "Building Year:" << building_year << endl
                       << "Type:" << type << endl
                        << "Built:" << built << endl;
           }
        }

      else {
         cout << "No computers to display!" << endl;
       }

     }

   if(query.exec("SELECT name, building_year, type, built FROM Tolvur ORDER BY built ASC"))
   {
       cout << "List of famous computers: " << endl << endl;
       while(query.next())
       {
           QString name   = query.value(0).toString();
           QString building_year = query.value(1).toString();
           QString type  = query.value(2).toString();
           QString built  = query.value(3).toString();
           qDebug() << "Name:" << name << endl
                    << "Building Year:" << building_year << endl
                    << "Type:" << type << endl
                     << "Built:" << built << endl;
        }
     }

   else {
      cout << "No computers to display!" << endl;
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
void Personal::addPersonal(string name, int building_year, string type, bool built)
{
    QSqlQuery query;
    /*
    query.prepare("INSERT INTO Tolvur (name, building_year, type, built) VALUES (:name, :building_year, :type, :built)");
    query.bindValue(":name", name);
    query.bindValue(":building_year", building_year);
    query.bindValue(":type", type);
    query.bindValue(":built", built);

    query.exec();

    if(!query.exec())
    {
        cout << "nothing inserted";
    }
    */
   // string queryInsert = "INSERT INTO Tolvur (name, building_year, type, built) VALUES ('ari', 1995, 'Personal', 1)";
   // query.exec(QString(queryInsert.c_str()));

    /*
    string name, buildin_year, type, built;
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
    */
}

void Personal::displayPersonal()
{
    QSqlQuery query;

    if(query.exec("SELECT name, building_year, type, built FROM Tolvur ORDER BY name ASC"))
    {
        cout << "List of famous computers: " << endl << endl;
        while(query.next()) {
            QString name   = query.value(0).toString();
            QString building_year = query.value(1).toString();
            QString type  = query.value(2).toString();
            QString built  = query.value(3).toString();
            qDebug() << "Name:" << name << endl
                     << "Building Year:" << building_year << endl
                     << "Type:" << type << endl
                     << "Built:" << built << endl;
        }
    }
    else {
        cout << "No computers to display!" << endl;
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
