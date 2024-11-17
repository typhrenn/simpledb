#include <iomanip>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <regclass.hpp>

using namespace std;

// Main function 
int main()
{
    // Count variables
    int wordCount = 0;
    int *regWordCount = 0;
    int registerCount = 0;
    // Clearing and setting up the input variable
    string input;
    system("clear");
    // Registry file
    char *file = nullptr;
    // Command list variable / Registry list variable
    char **lexList;
    char ***registers;
    Register defaultreg;

    cout << "Use command \"help\" for more informations" << endl;

    // Main Loop
    while (strcmp(input.c_str(), "exit") != 0)
    {
        // Default register
        if (file == nullptr)
        {
            cout << "SIMPLEDB> ";
        }
        else
        {
            cout << "SIMPLEDB \033[1;32m" << file << "\033[0m> ";
        }
        getline(cin, input);
        char **lexList = Lexer(input, wordCount);

        // Command execution
        for (int i = 0; i < wordCount; i++)
        {
            // LOAD FUNCTION
            if (strcmp(lexList[i], "load") == 0)
            {
                if (i + 1 < wordCount)
                {
                    file = lexList[i + 1];

                    registers = getReg(file, registerCount, regWordCount);

                    if (registers == NULL)
                    {
                        cout << "Register" << file << "Could not be loaded properly." << endl;
                        return -1;
                    }

                    cout << "Register " << file << " has been successfully loaded." << endl;
                }
            }

            // RELOAD FUNCTION
            if (strcmp(lexList[i], "reload") == 0)
            {
                if (i + 1 < wordCount)
                {
                    registers = getReg(file, registerCount, regWordCount);

                    if (registers == NULL)
                    {
                        cout << "Register" << file << "Could not be loaded properly." << endl;
                        return -1;
                    }

                    cout << "Register " << file << " has been successfully reloaded." << endl;
                }
            }


            // LIST FUNCTION
            if (strcmp(lexList[i], "list") == 0)
            {
                registers = getReg(file, registerCount, regWordCount);
                listReg(registers, registerCount);
            }

            // CLEAR FUNCTION
            if (strcmp(lexList[i], "clear") == 0)
            {
                system("clear");
            }

            // CURRENTREG FUNCTION
            if (strcmp(lexList[i], "currentreg") == 0)
            {
               defaultreg.currentReg(); 
            }

            // NEWREG FUNCTION
            if (strcmp(lexList[i], "newreg") == 0)
            {
                if (wordCount < 4)
                {
                    cout << "Too small amount of arguments." << endl;
                    continue;
                }
                if (wordCount == 4)
                {
                    defaultreg = Register("Julian", "Jakub", "Galicki");
                }
                else if (wordCount == 5)
                {
                    defaultreg = Register(string(lexList[1]), string(lexList[2]), string(lexList[3]), string(lexList[4]));
                }
                else if (wordCount == 6)
                {
                    defaultreg = Register(string(lexList[1]), string(lexList[2]), string(lexList[3]), string(lexList[4]), string(lexList[5]));
                }
                else if (wordCount == 7)
                {
                    defaultreg = Register(string(lexList[1]), string(lexList[2]), string(lexList[3]), string(lexList[4]), string(lexList[5]), string(lexList[6]));
                }
                else if (wordCount == 8)
                {
                    defaultreg = Register(string(lexList[1]), string(lexList[2]), string(lexList[3]), string(lexList[4]), string(lexList[5]), string(lexList[6]), string(lexList[7]));
                }
                else if (wordCount == 9)
                {
                    defaultreg = Register(string(lexList[1]), string(lexList[2]), string(lexList[3]), string(lexList[4]), string(lexList[5]), string(lexList[6]), string(lexList[7]), string(lexList[8]));
                }
            }

            // PUSHREG FUNCTION
            if (strcmp(lexList[i], "pushreg") == 0)
            {
                defaultreg.pushRegister(file);
                cout << "Register has been succesfully added." << endl;
            }
            // CREATE FUNCTION
            if (strcmp(lexList[i], "create") == 0)
            {
                if (i + 1 < wordCount)
                {
                    createRegisterFile(lexList[i+1]);
                }
                else
                {
                    cout << "Improper use of \"create\" command." << endl;
                }
            }
            // DELETE FUNCTION
            if (strcmp(lexList[i], "delete") == 0)
            {
                if (i + 1 < wordCount)
                {
                    deleteRegister(file,atoi(lexList[i+1]));
                }
                else
                {
                    deleteRegisterFile(file);
                    file = nullptr;
                }
            }

            // LISTFILE FUNCTION
            if (strcmp(lexList[i], "listfiles") == 0)
            {
                system("ls");
                cout << endl;
            }

            // HELP FUNCTION
            if (strcmp(lexList[i], "help") == 0)
            {
                cout << endl << "COMMANDS: " << endl;
                cout << left << setw(20) << "load <file>" << "Loads a file." << endl;
                cout << left << setw(20) << "list" << "Lists a loaded file." << endl;
                cout << left << setw(20) << "create <file>" << "Creates a file." << endl;
                cout << left << setw(20) << "delete" << "Deletes a loaded file." << endl;
                cout << left << setw(20) << "delete <line>" << "Deletes a line of loaded file." << endl;
                cout << left << setw(20) << "listfiles" << "Lists files in current directory." << endl;
                cout << left << setw(20) << "newregister <info>" << "Creates a new register." << endl;
                cout << left << setw(20) << "pushregister <info>" << "Pushes the created register to the file." << endl;
                cout << endl;

            }

        }
        cout << endl;
    }
    return 0;
}











