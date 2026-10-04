#include <iostream>
#include <cctype> 
using namespace std;

// QUESTION PROMPTS
const string Q1 = "Enter the starting number: ";
const string Q2 = "Enter the target ending number: ";




// INITIALIZE FUNCTIONS
// Calculates the sum between 2 numbers recursively
int recursiveSum(int n1, int n2);
// Prompts the user for an integer
int getNum(string cinNum, string instruction);
// Checks if string is valid if it is an integer
bool isInputInt(string validateStr);




// FUNCTION IMPLEMENTATIONS
// After being called, enter and process the function
int recursiveSum (int n1, int n2)
{
    // Base Case: if starting number meets the target ending number
    if (n1 == n2)   
        return n1; //Return recursive sum

    // Compute running total
    return n1 + recursiveSum(n1+1, n2);
}

int getNum(string cinNum, string instruction) 
{
    // Ask until the user enters a valid input
    cout << instruction;
    // Retrieve as a string
    getline (cin, cinNum);
    // Check if user input is a valid value
    isInputInt(cinNum);

    // If invalid value, run until user types in a valid input
    while (!isInputInt(cinNum))
    { 
        // Prompt again
        cout << "Invalid data type. Value must be an integer.\n";
        cout << instruction;
        getline (cin, cinNum);
        // Validate again
        isInputInt(cinNum);

    } 

    // If input is a valid value, convert it to integer
    int cinInteger = stoi (cinNum);
    // Return the valid integer value
    return cinInteger;
}

bool isInputInt(string validateStr)
{
    // Validate if user input is an integer
    if (validateStr == "" || validateStr == "-")
        return false;
    
    // Loop the entire string, character by character
    for (int a=0; a<validateStr.length(); a++)
    {
        // Check the validity per each char 

        // Check if the value is a negative
        if (validateStr[a] == '-' && a == 0)
            continue; // Continue processing the next characters
        // Check if value is a valid integer number
        else if (!isdigit(validateStr[a]) || validateStr[a] == ' ' || validateStr[a] == '-') 
            return false; // If the digit is not an integer, set to false
    }
    // Return true for a valid integer
    return true;
}
