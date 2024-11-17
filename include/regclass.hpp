#ifndef REGCLASS_H
#define REGCLASS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Register
{
    public:
    string FIRST_NAME;
    string MIDDLE_NAME;
    string LAST_NAME;
    string COUNTRY;
    string CITY;
    string MARITAL_STATUS;
    string STATUS;
    string AGE;
    
    Register();
    Register(string first_name, string middle_name, string surname);
    Register(string first_name, string middle_name, string surname, string age);
    Register(string first_name, string middle_name, string surname, string age, string country);
    Register(string first_name, string middle_name, string surname, string age, string country, string city);
    Register(string first_name, string middle_name, string surname, string age, string country, string city, string marital_status);
    Register(string first_name, string middle_name, string surname, string age, string country, string city, string marital_status, string status);

    void pushRegister(const char *filename);
    void currentReg();
};

char** Lexer(const string& input, int& count);
char*** getReg(const char* filename, int& registerCount, int*& wordCounts);
void listReg(char ***registers, int registerCount);
void deleteRegister(const string& file, int lineToDelete);
void createRegisterFile(const string& file);
void deleteRegisterFile(const string& file);

#endif // REGCLASS_H
