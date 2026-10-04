#include <iostream>
#include <cctype> 
#include "recursiveSum.h"
using namespace std;

int main()
{
    int num1, num2; // Values for recursion
    string userInput; // Get user input 
    // Char 'y' stands for "yes"
    // Set to start (yes, run program) by default
    char run = 'y';

    // Output an introductory message
    cout << "\nWelcome to the Recursive Sum Program!\n"
            << "This program calculates the sum between two numbers.\n"
            << "Let's begin.\n\n";
    
    // Run program as user intends to
    while ( run == 'y' || run == 'Y')
    {   
        // Prompt user for number range
        // Call function to retrieve an integer from the user and assign the values
        num1=getNum(userInput, Q1);
        num2=getNum(userInput, Q2);

        // Ensure that starting number must be less than the target number
        while (num1>num2)
        {
            cout << "\nThe second number cannot be larger than the first number. "
                << "Please enter a valid range.\n";
            num1=getNum(userInput, Q1);
            num2=getNum(userInput, Q2);
        }

        // Call recursive function and pass in the two input numbers
        cout << "The recursive sum is: " << recursiveSum(num1, num2) << "\n\n";
        // Ask if user wants to stop the program or compute another recursive sum
        cout << "Would you like to continue? Press Y or N: ";
        cin >> run;
        // Ensure user inputs a valid option
        while (run != 'y' && run != 'n' &&
               run != 'Y' && run != 'N' )
        {
            cout << "Would you like to continue? Press Y or N: ";
            cin >> run;
        }
        // If user proceeds, clear the line feed and restart the loop(program)
        if (run == 'y' || run == 'Y')
        { 
            cin.clear();
            cin.ignore(1000,'\n');
            cout << endl;
        }
        // If user wishes to not continue, exit program
        else if (run == 'n' || run == 'N')
            break;
    }
    cout << "Terminating program... goodbye!\n";
    return 0; // Terminate program successfully
}
