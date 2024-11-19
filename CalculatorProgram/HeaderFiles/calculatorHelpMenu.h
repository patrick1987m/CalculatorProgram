#pragma once
#include "programTools.h"
#include "framework.h"

class HelpMenu
{
public:
	void printHelpMenu();
	void printExamples();
	void printAdvancedExamples();

private:
	const std::string helpPrompt = "\nEnter your choice: ";
    void handleMenuInput(char input)
    {
        switch (input)
        {
        case 'a':
            printAdvancedExamples();
            break;
        case 'e':
            printExamples();
            break;
        case 'h':
            printHelpMenu();
            break;
        case 'z':
            std::cout << "Thank you for using MCalculator 1.35's Interactive Help Menu!\n";
            return;
        default:
            std::cout << "Unrecognized Command. Please Try Again! \n";
            break;
        }
    }
};

// printHelpMenu()
void HelpMenu::printHelpMenu()
{
    while (true)
    {
        std::system("CLS");
        std::cout << "Welcome to MCalculator 1.35's Help Menu: \n";
        std::cout << "\nThis page will contain the necessary key's to operate the program: \n";
        std::cout << "\n1.) To Access the Help Menu, enter h\n";
        std::cout << "\n2.) To Exit the Program, enter q\n";
        std::cout << "\n3.) This calculator can handle the following operations: +, -, *, /, %(Modulo or Remainder): \n";
        std::cout << "\n4.) With sqrt(Number here), you can find the sqrt of a number. \n";
        std::cout << "\n5.) If you want to determine exponents, you can do so with the ^ key. \n";
        std::cout << "\nTo end a Statement, use a ';', This is the program's print character!\n\n";
        std::cout << '\n';
        std::cout << '\n' << '\n';
        std::cout << "Starting With MCalculator 1.35, instead of doing your calculations in the program. \n";
        std::cout << "You can also do calculations based on file. \n";
        std::cout << "At the beginning of the program, it will ask you if you want to do calculations based "
            << "upon console (press c), for file calculations, press (f).\n";
     
        std::cout << "If you would like to see a list of examples of simple examples, press e now: \n";
        std::cout << "If you would like to see the Advanced Functions, enter a! \n";
        std::cout << "To get back to the calculator, press z at this time:  \n";
        std::cout << helpPrompt;

        char input{ ' ' };
        std::cin >> input;

        if (input == 'q')
        {
            return;
        }

        handleMenuInput(input);
    }
}
// Basic Examples
void HelpMenu::printExamples()
{
    while (true)
    {
        std::system("CLS");
        std::cout << "Reminder: This program will follow the rules of PEMDAS! \n";
        std::cout << "(Parenthesis, Exponents, Multiplication, Division, Addition, Subtraction.)  \n";
        std::cout << "Below you will find some possible expressions that are allowed by this version of the calculator: \n";
        std::cout << '\n';
        std::cout << "********************************************************************************************************\n";
        std::cout << "* For Addition you can do the following:                                                               *\n";
        std::cout << "* A simple adding expression:        > 1 + 2;           A Complex Expression: > (1 + 2) + (5 + 2);     *\n";
        std::cout << "* This will result in:               = 3                This will result in:  = 10                     *\n";
        std::cout << "********************************************************************************************************\n";
        std::cout << "* Subtractions works in the same way:                                                                  *\n";
        std::cout << "* A simple subtraction expression:   > 5 - 1;           A Complex Expression: > (5 - 1) - (10 - 1);    *\n";
        std::cout << "* Will Result in:                    = 4                                      = -5                     *\n";
        std::cout << "********************************************************************************************************\n";
        std::cout << "* Multiplication Expression:         > 4 * 2;           A Complex Expression: > (5 * 2) + (5 * 4);     *\n";
        std::cout << "* Will Result in:                    = 8                                      = 30                     *\n";
        std::cout << "********************************************************************************************************\n";
        std::cout << "* Division Expression:               > 10 / 2;          A Complex Expression: > (8 + 2) / (1 + 1);     *\n";
        std::cout << "* Will Result in:                    = 5                                      = 5                      *\n";
        std::cout << "********************************************************************************************************\n";
        std::cout << "* Remainder Expression:              > 5 % 3;           A Complex Expression: > (3 + 2 / (1 + 3);      *\n";
        std::cout << "* Will Result in:                    = 2                                      = 2                      *\n";
        std::cout << "********************************************************************************************************\n";
        std::cout << "* Main Program Keys:                                                                                   *\n";
        std::cout << "* To Access The Main Help Menu -- Press 'h', to exit the Interactive HelpMenu, press z                 *\n";
        std::cout << helpPrompt;
        // Add the Ability to Access the Advanced Commands Screen:
        char advancedExpressions{ ' ' };
        std::cin >> advancedExpressions;

        if (advancedExpressions == 'q')
        {
            return;
        }
        handleMenuInput(advancedExpressions);
    }
}

// Print Advanced Examples
void HelpMenu::printAdvancedExamples()
{
    while (true)
    {
        std::system("CLS");
        std::cout << "**************************************************************************************************\n";
        std::cout << "* Other Calculator Operations:                      **********************************************\n";
        std::cout << "* This Calculator Can Handle Variables:             *  Main Program Key's:   *********************\n";
        std::cout << "*  So, if you type in: > let x = 5;                 *  e - Basic Commands    *********************\n";
        std::cout << "*                      = 5                          *  a - Advanced Commands *********************\n";
        std::cout << "* Now you can do this: > x * 2;                     *  h - Main Help Menu    *********************\n";
        std::cout << "* This will Result in: = 10                         *  To Exit:                                  *\n";
        std::cout << "*****************************************************  Press q to exit the Interactive Help Menu *\n";
        std::cout << "* To find the square root of a number:              *  From There, you can run calculations, or  *\n";
        std::cout << "* Simply type: > sqrt(25);  (Any number will work)  *  Press q again to exit the program.        *\n";
        std::cout << "*              = 5                                  **********************************************\n";
        std::cout << "**************************************************************************************************\n";
        std::cout << "* This Calculator can also handle factorials and exponents! See Below:                        ****\n";
        std::cout << "*                                                                                             ****\n";
        std::cout << "* For Exponents: Use the ^ key, by hitting the shift key + 6 (not F6) on the top of keyboard. ****\n";
        std::cout << "* Example Usage: > 5 ^ 2;                                                                     ****\n";
        std::cout << "*        Result: = 25                                                                         ****\n";
        std::cout << "* For Factorials: This Calculator can handle at the very least the following:                 ****\n";
        std::cout << "*                                                                                             ****\n";
        std::cout << "* The idea behind factorials is as follows                                                    ****\n";
        std::cout << "* 4! = (4 * 3 * 2 * 1) = 24                                                                   ****\n";
        std::cout << "* Example Usages: > 4!;   > 6!;                                                               ****\n";
        std::cout << "*                 = 24    = 720                                                               ****\n";
        std::cout << "*                 > 12! or (6 + 6)!;                                                          ****\n";
        std::cout << "*                 = 479001600        (Or The highest integer factorial)                       ****\n";
        std::cout << "*                 > 20! or (10 + 10);                                                         ****\n";
        std::cout << "*                 =                                                                           ****\n";
        std::cout << "**************************************************************************************************\n";
        // Add the Ability to access the other Menus:
        char returnMenu{ ' ' };
        std::cout << helpPrompt;
        std::cin >> returnMenu;
        if (returnMenu == 'q')
        {
            return;
        }
        handleMenuInput(returnMenu);

}
// Function to centralize Menu input
