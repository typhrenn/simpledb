#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <iomanip>
#include <regclass.hpp>

using namespace std;

Register::Register()
{
    FIRST_NAME = "";
    MIDDLE_NAME = "";
    LAST_NAME = "";
    COUNTRY = "";
    CITY = "";
    MARITAL_STATUS = "";
    STATUS = "";
    AGE = "";
}

Register::Register(string first_name, string middle_name, string surname)
{
    FIRST_NAME = first_name;
    MIDDLE_NAME = middle_name;
    LAST_NAME = surname;
    COUNTRY = "";
    CITY = "";
    MARITAL_STATUS = "";
    STATUS = "";
    AGE = "";
}

Register::Register(string first_name, string middle_name, string surname, string age)
{
    FIRST_NAME = first_name;
    MIDDLE_NAME = middle_name;
    LAST_NAME = surname;
    AGE = age;
    COUNTRY = "";
    CITY = "";
    MARITAL_STATUS = "";
    STATUS = "";
}

Register::Register(string first_name, string middle_name, string surname, string age, string country)
{
    FIRST_NAME = first_name;
    MIDDLE_NAME = middle_name;
    LAST_NAME = surname;
    AGE = age;
    COUNTRY = country;
    CITY = "";
    MARITAL_STATUS = "";
    STATUS = "";
}

Register::Register(string first_name, string middle_name, string surname, string age, string country, string city)
{
    FIRST_NAME = first_name;
    MIDDLE_NAME = middle_name;
    LAST_NAME = surname;
    AGE = age;
    COUNTRY = country;
    CITY = city;
    MARITAL_STATUS = "";
    STATUS = "";
}

Register::Register(string first_name, string middle_name, string surname, string age, string country, string city, string marital_status)
{
    FIRST_NAME = first_name;
    MIDDLE_NAME = middle_name;
    LAST_NAME = surname;
    AGE = age;
    COUNTRY = country;
    CITY = city;
    MARITAL_STATUS = marital_status;
    STATUS = "";
}

Register::Register(string first_name, string middle_name, string surname, string age, string country, string city, string marital_status, string status)
{
    FIRST_NAME = first_name;
    MIDDLE_NAME = middle_name;
    LAST_NAME = surname;
    AGE = age;
    COUNTRY = country;
    CITY = city;
    MARITAL_STATUS = marital_status;
    STATUS = status;
}

void Register::pushRegister(const char *filename)
{
    // Opening file
    ofstream pushReg(filename, ios::app);

    // Pushing Data
    // First Name
    if (!FIRST_NAME.empty())
    {
        pushReg << FIRST_NAME << " ";
    }
    else
    {
        pushReg << "???" << " ";
    }

    // Middle Name
    if (!MIDDLE_NAME.empty())
    {
        pushReg << MIDDLE_NAME << " ";
    }
    else
    {
        pushReg << "???" << " ";
    }

    // Last Name
    if (!LAST_NAME.empty())
    {
        pushReg << LAST_NAME << " ";
    }
    else
    {
        pushReg << "???" << " ";
    }

    // Age
    if (!AGE.empty())
    {
        pushReg << AGE << " ";
    }
    else
    {
        pushReg << "???" << " ";
    }

    // Country
    if (!COUNTRY.empty())
    {
        pushReg << COUNTRY << " ";
    }
    else
    {
        pushReg << "???" << " ";
    }

    // City
    if (!CITY.empty())
    {
        pushReg << CITY << " ";
    }
    else
    {
        pushReg << "???" << " ";
    }

    // Marital Status
    if (!MARITAL_STATUS.empty())
    {
        pushReg << MARITAL_STATUS << " ";
    }
    else
    {
        pushReg << "???" << " ";
    }

    // Status (ex: Deceased, Alive, Missing)
    if (!STATUS.empty())
    {
        pushReg << STATUS << " ";
    }
    else
    {
        pushReg << "???";
    }

    // NEWLINE
    pushReg << endl;

}

void Register::currentReg()
{
    cout << "┏ Id: ┳ First Name ━━┳ Middle Name ━┳ Last Name ━━━┳ Age ┳ Country ━━━━━┳ City ━━━━━━━━┳ Marital Status ┳ Status ━━━━┓";
    cout << endl;
    cout << "┃ ";
    cout << left << setw(3) << "DRG" << " ┃ ";
    cout << left << setw(12) << FIRST_NAME << " ┃ ";
    cout << left << setw(12) << MIDDLE_NAME << " ┃ ";
    cout << left << setw(12) << LAST_NAME << " ┃ ";
    cout << left << setw(3) << AGE << " ┃ ";
    cout << left << setw(12) << COUNTRY << " ┃ ";
    cout << left << setw(12) << CITY << " ┃ ";
    cout << left << setw(14) << MARITAL_STATUS << " ┃ ";
    cout << left << setw(10) << STATUS << " ┃";

    cout << "\n┗━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━┛\n\n";
}

// Function for splitting command input into keywords
char** Lexer(const string& input, int& count) 
{
    vector<string> words;
    string word;

    for (char ch : input) 
    {
        if (ch == ' ') 
        {
            if (!word.empty()) 
            {
                words.push_back(word);
                word.clear();
            }
        } 
        else 
        {
            word += ch;
        }
    }

    if (!word.empty()) 
    {
        words.push_back(word);
    }
    
    count = words.size();
  
    char** result = new char*[count];
    for (int i = 0; i < count; ++i) 
    {
        result[i] = new char[words[i].size() + 1];
        strcpy(result[i], words[i].c_str());
    }

    return result;
}

// Function for getting registers from file
char ***getReg(const char* filename, int& registerCount, int*& wordCounts) 
{
    ifstream file(filename);
    if (!file.is_open()) 
    {
        return nullptr;
    }

    string line;
    vector<char**> registers;
    vector<int> wordCountVec;

    while (getline(file, line)) 
    {
        int wordCount = 0;
        char** words = Lexer(line, wordCount);
        registers.push_back(words);
        wordCountVec.push_back(wordCount);
    }

    registerCount = registers.size();

    char*** result = new char**[registerCount];
    wordCounts = new int[registerCount];

    for (int i = 0; i < registerCount; ++i) 
    {
        result[i] = registers[i];
        wordCounts[i] = wordCountVec[i];
    }

    return result;
}

void listReg(char ***registers, int registerCount)
{
    cout << "┏ Id: ┳ First Name ━━┳ Middle Name ━┳ Last Name ━━━┳ Age ┳ Country ━━━━━┳ City ━━━━━━━━┳ Marital Status ┳ Status ━━━━┓";
    for (int i = 0; i < registerCount; i++)
    {
        cout << endl;
        cout << "┃ ";
        cout << left << setw(3) << i << " ┃ ";
        cout << left << setw(12) << registers[i][0] << " ┃ ";
        cout << left << setw(12) << registers[i][1] << " ┃ ";
        cout << left << setw(12) << registers[i][2] << " ┃ ";
        if (atoi(registers[i][3]) < 18)
        {
            cout << "\033[1;31m" << left << setw(3) << registers[i][3] << "\033[0m" << " ┃ ";
        }
        else if (atoi(registers[i][3]) >= 18)
        {
            cout << "\033[1;32m" << left << setw(3) << registers[i][3] << "\033[0m" << " ┃ ";
        }
        cout << left << setw(12) << registers[i][4] << " ┃ ";
        cout << left << setw(12) << registers[i][5] << " ┃ ";
        cout << left << setw(14) << registers[i][6] << " ┃ ";
        cout << left << setw(10) << registers[i][7] << " ┃";
    }
    cout << "\n┗━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━┛\n\n";
}

// Function to delete a specific line from registers
void deleteRegister(const string& file, int lineToDelete) 
{
    ifstream inFile(file);

    vector<string> lines;
    string line;
    int currentLine = 0;
    while (getline(inFile, line)) 
    {
        if (currentLine != lineToDelete) 
        {
            lines.push_back(line);
        }
        currentLine++;
    }

    inFile.close();

    if (lineToDelete < 0 || lineToDelete >= currentLine) 
    {
        cout << "Line " << lineToDelete << " doesn\'t exits." << endl;
        return;
    }

    ofstream outFile(file);

    for (const auto& l : lines) 
    {
        outFile << l << endl;
    }

    outFile.close();
    cout << "Line " << lineToDelete << " has been successfully deleted." << endl;
}

// Function to create a file
void createRegisterFile(const string& file)
{
    ofstream outFile(file);
    cout <<  "File " << file << " has been succesfully created." << endl;
    outFile.close();
}

// Function to delete a file
void deleteRegisterFile(const string& file) 
{
    if (remove(file.c_str()) == 0) 
    {
        cout << "File " << file << " deleted successfully." << endl;
    } 
    else 
    {
        cout << "Could not delete the file " << file << "." << endl;
    }
}
