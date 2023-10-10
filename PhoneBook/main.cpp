//
//  main.cpp
//  PhoneBook
//
//  Created by Michalis on 10.10.2023.
//

#include <iostream>
#include "PhoneBook.hpp"

using namespace std;
int main() {
    int userChoice;
    int numAb = 0;
    char* firstName;
        char* lastName;
        char* sureName;
        PhoneBook* subscribers = nullptr;
    char buff[100];
    int key;
    bool isData=false;
    int numDel;
    do{
        do{
            cout<<"Menu:"<<endl;
            cout<<"1. Add abonent"<<endl;
            cout<<"2. Delete abonent"<<endl;
            cout<<"3. Find FIO abonent"<<endl;
            cout<<"4. Show all abonents"<<endl;
            cout<<"5. SafeToFile"<<endl;
            cout<<"6. LoadFromFile"<<endl;
            cout<<"0. EXIT"<<endl;
            
            cout<<"Input your choice: ";
            cin>>userChoice;
            
            if ((userChoice>6)||(userChoice<0))
            {
                cout<<"Error! Wrong input! Try again"<<endl;
            }
        }while((userChoice>6)||(userChoice<0));
        
        switch(userChoice)
        {
            case 1:
                cout<<"How many abnts you wanna add?"<<endl;
                cin>>numAb;
            
                subscribers = new PhoneBook[numAb];

                               for (int i = 0; i < numAb; i++) 
                               {
                                   subscribers[i].Input();
                                   cout << endl;
                               }
                isData=true;
                break;
            case 2:
                if (isData)
                {
                    cout << "Quantity of abnts: " << numAb << endl;

                                       do {
                                           cout << "Input # of abnt to delete: ";
                                           cin >> numDel;

                                           if (numDel > numAb || numDel <= 0)
                                               cout << "Вы ввели не допустимый диапозон!" << endl << endl;
                                       } while ((numDel > numAb)|| (numDel <= 0));
                    numDel--;

                    numAb = subscribers->DeleteAbonent(subscribers, numAb, numDel);
                                       
                }
                else
                {
                    cout<<"Firstly add abonents!!!"<<endl;
                }
                break;
            case 3:
                if (isData)
                {
                    cout << "Поиск по ФИО: " << endl;
                    cout << "Введите фамилию: ";
                    cin >> buff;
                    lastName = new char[strlen(buff) + 1];
                    strcpy(lastName, buff);

                    cout << "Введите имя: ";
                    cin >> buff;
                    firstName = new char[strlen(buff) + 1];
                    strcpy(firstName, buff);

                    cout << "Введите отчество: ";
                    cin >> buff;
                    sureName = new char[strlen(buff) + 1];
                     strcpy(sureName, buff);

                     key = subscribers->FIOSearch(subscribers, numAb, firstName, lastName, sureName);

                      cout << "KEY: " << key << endl;

                     if (key == -1)
                    cout << "Ключ не найден!" << endl;
                     else
                     subscribers[key].Print();
                }
                else
                {
                    cout<<"Firstly add abonents!!!"<<endl;
                }
                break;
            case 4:
                if (isData)
                {
                    if (numAb == 0)
                    {
                        cout << "No abnnts to show" << endl << endl;
                    }
                    else 
                    {
                        for (int i = 0; i < numAb; i++)
                        {
                            subscribers[i].Print();
                            cout << endl;
                        }
                    }
                }
                else
                {
                    cout<<"Firstly add abonents!!!"<<endl;
                }
                break;
            case 5:
                if (isData)
                {
                    subscribers->SaveToFile(subscribers, numAb);
                }
                else
                {
                    cout<<"Firstly add abonents!!!"<<endl;
                }
                break;
            case 6:
                if (isData)
                {
                    subscribers->LoadFromFile();
                }
                else
                {
                    cout<<"Firstly add abonents!!!"<<endl;
                }
                break;
            case 0:
                cout<<"See you!"<<endl;
                break;
        }
    }while (userChoice!=0);
    return 0;
}
