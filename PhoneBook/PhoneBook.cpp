//
//  PhoneBook.cpp
//  PhoneBook
//
//  Created by Michalis on 11.10.2023.
//

#include "PhoneBook.hpp"
#include <iostream>
#include <fstream>

using namespace std;
PhoneBook::PhoneBook() {
    firstName = nullptr;
    lastName = nullptr;
    sureName = nullptr;

    homePhone = nullptr;
    workPhone = nullptr;
    mobilePhone=nullptr;
}
PhoneBook::PhoneBook(char* fn, char* ln, char* sn, char* wp, char* mp, char* hp)
{
    firstName = new char[strlen(fn) + 1];
    strcpy(firstName, fn);

    lastName = new char[strlen(ln) + 1];
    strcpy(lastName, ln);

    sureName = new char[strlen(sn) + 1];
    strcpy(sureName, sn);

    homePhone = new char[strlen(hp) + 1];
    strcpy(homePhone, hp);

    workPhone = new char[strlen(wp) + 1];
    strcpy(workPhone, wp);
    
    mobilePhone = new char[strlen(mp) + 1];
    strcpy(mobilePhone, mp);
}
PhoneBook::~PhoneBook() {
    cout << "Destructor\n";

    delete[] lastName;
    delete[] firstName;
    delete[] sureName;

    delete[] homePhone;
    delete[] workPhone;
    delete[] mobilePhone;
}
void PhoneBook::Input()
{
    char buff[100];

    cout << "Input your name";
    cin >> buff;

    if (firstName != nullptr) 
    {
        delete[] firstName;
    }

    firstName = new char[strlen(buff) + 1];
    strcpy(firstName, buff);



    cout << "Input your lastname: ";
    cin >> buff;

    if (lastName != nullptr) 
    {
        delete[] lastName;
    }

    lastName = new char[strlen(buff) + 1];
    strcpy(lastName, buff);



    cout << "Input your surename: ";
    cin >> buff;

    if (sureName != nullptr) {
        delete[] sureName;
    }

    sureName = new char[strlen(buff) + 1];
    strcpy(sureName, buff);



    cout << "Input your home phone: ";
    cin >> buff;

    if (homePhone != nullptr)
    {
        delete[] homePhone;
    }

    homePhone = new char[strlen(buff) + 1];
    strcpy(homePhone, buff);



    cout << "Input your work phone: ";
    cin >> buff;

    if (workPhone != nullptr) 
    {
        delete[] workPhone;
    }

    workPhone = new char[strlen(buff) + 1];
    strcpy(workPhone, buff);
    
    cout << "Input your mobile phone: ";
    cin >> buff;

    if (mobilePhone != nullptr)
    {
        delete[] mobilePhone;
    }

    mobilePhone = new char[strlen(buff) + 1];
    strcpy(mobilePhone, buff);
}
void PhoneBook::Print() 
{
    cout << "Last name: " << lastName << endl;
    cout << "First name: " << firstName << endl;
    cout << "Sure name: " << sureName << endl;
    
    cout << "Home phone: " << homePhone << endl;
    cout << "Work phone: " << workPhone << endl;
    cout << "Mobile phone: " << mobilePhone << endl;
}
char* PhoneBook::GetFistName()
{
    return this->firstName;
}
char* PhoneBook::GetLastName() 
{
    return this->lastName;
}
char* PhoneBook::GetSurName()
{
    return this->sureName;
}
char* PhoneBook::GetHomePhone() 
{
    return this->homePhone;
}
char* PhoneBook::GetWorkPhone() 
{
    return this->workPhone;
}
char* PhoneBook::GetMobilePhone()
{
    return this->mobilePhone;
}

// Сеттеры
void PhoneBook::SetFistName(const char* fn) 
{
    if (firstName != nullptr) 
    {
        delete firstName;
    }

    firstName = new char[strlen(fn)+1];
    strcpy(firstName, fn);
}
void PhoneBook::SetLastName(const char* ln)
{
    if (lastName != nullptr) 
    {
        delete lastName;
    }

    lastName = new char[strlen(ln) + 1];
    strcpy(lastName, ln);
}
void PhoneBook::SetSureName(const char* sn) 
{
    if (sureName != nullptr)
    {
        delete sureName;
    }

    sureName = new char[strlen(sn) + 1];
    strcpy(sureName, sn);
}
void PhoneBook::SetHomePhone(const char* hp)
{
    if (homePhone != nullptr)
    {
        delete homePhone;
    }

    homePhone = new char[strlen(hp) + 1];
    strcpy(homePhone, hp);
}
void PhoneBook::SetWorkPhone(const char* wp) 
{
    if (workPhone != nullptr)
    {
        delete workPhone;
    }

    workPhone = new char[strlen(wp) + 1];
    strcpy(workPhone, wp);
}
void PhoneBook::SetMobilePhone(const char* mp)
{
    if (mobilePhone != nullptr)
    {
        delete mobilePhone;
    }

    mobilePhone = new char[strlen(mp) + 1];
    strcpy(mobilePhone, mp);
}
int PhoneBook::AddAbonent(PhoneBook*& array, int oldSize) {
    int newSize = oldSize + 1;
    PhoneBook* newArray = new PhoneBook[newSize];

    for (int i = 0; i < oldSize; i++)
        newArray[i] = array[i];

    array = newArray;

    return newSize;
}
int PhoneBook::DeleteAbonent(PhoneBook*& array, int oldSize, int numberDelete) {
    int newSize = oldSize - 1;
    PhoneBook* newArray = new PhoneBook[newSize];

    for (int i = 0, j = 0; i < oldSize; i++) {
        if (i != numberDelete) {
            newArray[j] = array[i];
            j++;
        }
    }

    array = newArray;

    return newSize;
}
int PhoneBook::FIOSearch(PhoneBook* array, int size, const char* fn, const char* ln, const char* sn) {
    if (!array) {
        cout << "is NULL" << endl;
        return -2;
    }

    cout << "Поиск по ФИО: " << endl;
    cout << "Фамилия: " << ln << endl;
    cout << "Имя: " << fn << endl;
    cout << "Отчество: " << sn << endl;

    for (int i = 0; i < size; i++)
       
        if (strcmp(array[i].lastName, ln) == 0 && strcmp(array[i].firstName, fn) == 0 && strcmp(array[i].sureName, sn) == 0)
            return i;

    return -1;
}
void PhoneBook::SaveToFile(PhoneBook* array, int size) {
    if (!array) {
        cout << "is NULL";
        return;
    }

    ofstream text("subscribersInfo.txt");

    for (int i = 0; i < size; i++) {
        text << "FirstName: " << array[i].firstName << ";" << endl;
        text << "LastName: " << array[i].lastName << ";" << endl;
        text << "SurName: " << array[i].sureName << ";" << endl;
        
        text << "HomePhone: " << array[i].homePhone << ";" << endl;
        text << "WorkPhone: " << array[i].workPhone << ";" << endl << endl;
        text << "MobilePhone: " << array[i].mobilePhone << ";" << endl << endl;
    }
}
void PhoneBook::LoadFromFile() {
    int n = 256;
    char* buffer = new char[n] {};
    ifstream binary1("Employee.txt", ios::binary);

    binary1.read(buffer, n);
    cout << buffer << endl;

    delete[] buffer;

    binary1.close();
}

