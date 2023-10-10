//
//  PhoneBook.hpp
//  PhoneBook
//
//  Created by Michalis on 11.10.2023.
//

//#ifndef PhoneBook_hpp
//#define PhoneBook_hpp
#pragma once
#include <stdio.h>

//#endif /* PhoneBook_hpp */
class PhoneBook
{
    char* firstName;
    char* lastName;
    char* sureName;
    
    char* workPhone;
    char* mobilePhone;
    char* homePhone;
public:
    PhoneBook();
    PhoneBook(char* fn, char* ln, char* sn, char* wp, char* mp, char* hp);
    ~PhoneBook();
    void Input();
    void Print();
    int AddAbonent(PhoneBook*& array, int oldSize);
    int DeleteAbonent(PhoneBook*& array, int oldSize, int numberDelete);
    int FIOSearch(PhoneBook* array, int size, const char* fn, const char* ln, const char* sn);
    void SaveToFile(PhoneBook* array, int size);
    void LoadFromFile();
    char* GetFistName();
        char* GetLastName();
        char* GetSurName();

        char* GetHomePhone();
        char* GetWorkPhone();
    char* GetMobilePhone();
    

        void SetFistName(const char*);
        void SetLastName(const char*);
        void SetSureName(const char*);

        void SetHomePhone(const char*);
        void SetWorkPhone(const char*);
    void SetMobilePhone(const char*);
};
