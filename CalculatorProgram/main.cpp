#include "programTools.h"
/*
Calculator 1.3

	This version uses Tokens to capture numerical data as well as operands:

	Each Token is then processed through the TokenStream class

	Created: 9-22-2024

	Revision List: This is the place where any revisions for this software will go.

	First Revision: 09-23-2024 --
	Small changes to the introduction text. I cleaned up the order of evaulation
	For example:

	Old Text:

	std::cout << "Welcome to our simple calculator. \n"
				<< "Please enter expressions using floating-point numbers. \n"
				<< "Below you will find the logical operations available for this version of the calculator: \n"
				<< '\n' << '\n'
				<< "1. (Normal Math Operations: +, -, *, /) \n2. (Bitwise Operators: &, |, ^, ~, <<, >>)\n"
				<< "3. (Grouping with: () and {}) \n"
				<< "\nSome basic rules: \n\n"
				<< " 1.) This program follows PEMDAS(Parenthesis, Exponents, Multiplication, "
				<< " Division, Addition, Subtraction.)\n"
				<< "\n 2.) A complete expression requires a terminating ';', which is the keyword for print. \n"
				<< "\n 3.) To exit the program: Enter 'q' !\n"
				<< "\nExample Expressions: \n"
				<< "\n1+2; "
				<< "\n(1+2)*(5-2); "
				<< "\n\n";
	Changed Text:
	std::cout << "Welcome to our simple calculator. \n"
			<< "Please enter expressions using floating-point numbers. \n"
			<< "Below you will find the logical operations available for this version of the calculator: \n"
			<< '\n' << '\n'
			<< "1. (Grouping with: () and {} and factorial with '!') \n2. (Normal Math Operations: +, -, *, /)\n"     -- This line was changed to include factorials within the grouping section.
			<< "3. (Bitwise Operators: &, |, ^, ~, <<, >>)\n"
			<< '\n'
			<< "This program will evaluate your expression in the order of the above: With Grouping and factorials being first\n"  -- This was changed to include factorials:
			<< "\nSome basic rules: \n\n"
			<< " 1.) This program follows PEMDAS(Parenthesis, Exponents(not available at the moment), Multiplication, \n"
			<< "     Division, Addition, Subtraction.)\n"
			<< "\n 2.) A complete expression requires a terminating ';', which is the keyword for print. \n"
			<< "\n 3.) To exit the program: Enter 'q' !\n"
			<< "\nExample Expressions: \n"
			<< "\n1+2; "
			<< "\n(1+2)*(5-2); "
			<< "\n\n";
			Final change, instead of having this text in the calculatorlogic function. 
			I placed this code into a seperate function. 

	Revision Version 1.2:
	
	Version 1.2's biggest feature add, is the ability to calculate modulo (%) or remainder:

	For Example: =>: 5 % 3;
	             = 2

	Code Cleanup was performed: In the TokenStream get() function

	We also had to add the token '%' onto our get function so we can use the token.

	Added:

	Examples for Modulo:

	Major Announcement: 09-28-2024, robust error handling has been created.

	Instead of the program shutting down if a user enters in a bad Token,
	The program will clean up the TokenStream and allow calculation to continue.
	********************************************************************************
	End of Revision 1.2
*******************************************************************************************************************************************************************
******************************************************************************************************************************************************************
Revision 1.3 -- 10-06-2024

This is a Major Revision: 

1. This version has been completely overhauled! An almost complete re-write of the previous versions! 
   It has been given the name MCalculator.
	    
   a.) All "magic" constants have been moved to named variables and labeled as const characters below

   b.) The entire TokenStream::get() function has been reformed and optimized to handle multiple different types of tokens:
	   To Include: quit, print, name, number, ^ (for exponents), =(for Variable Assignment)..

2. This version of our TokenStream handles variable assignment: This is a major feature release!
   The basic premise is: Enter -- let x = 5; The program will accept that as a variable named x, with a value set at 5
   So, this means we can then now use that x variable, for all kinds of computations. 

   Example:
	  x + 2; This will result in 7, because the computer will take our original 5 we set the x to be, and add 2 to it.

3. Variables are not the only major addition for this release.

   a.) MCalculator 1.3, can also handle factorials, more robustly using ! as the operator for factorial. Preventing overflows!

   b.) Square Root has been added to this version of this calculator. Example usage: > sqrt(25); This will = 5

   c.) Last by surely not least, added in 1.3, is the ability to process exponentation in calculations:
	   Example: 5 ^ 2;

4. The last addition for version 1.3 is MCalculator's interactive help menu system. You should check it out.
   Built in with logical keys allowed for this program. It allows you to page between different sections of help.
   Those keys are 'h' for the main help system, once in there, you can enter 'e' to get basic expressions,
   you could also enter 'a' for advanced topics: Like Square Root, Exponent, Factorials. More to be added later.

***  One Caveat:  
When you run this program, it will allow for 5 + 2; 5 - 1; 5 * 5; on one line.
But the output will not be what is expected. 
                             
The output will be as follows: > 5 + 2; 5 - 1; 5 * 5; Instead of: > 5 + 2; 5 - 1; 5 * 5;
                               = 7                                = 7
							   > = 4                              = 4
                               > = 25                             = 25
	    					   >                                  > 

This issue is a known bug in the program. It will be fixed before version 2.0. I am unsure of how to solve the problem.
Any Advice, would be greatly appreciated. 

End of Changelog for Version 1.3!
*******************************************************************************************************************************
ChangeLog for 1.35

This was a major overhaul, for it being such a small incremental number:

The program has been converted into all classes. To see the calculator program in full description, review UniversalCalculatorTokenStreams.h 
which is located in the included HeaderFiles folder.

The basic premise is, now the entire Calculator, TokenStream, Token classes have been fully implemented. 

1. Added the ability to do calculations based on user choice:
   
   a. From file, this means the user can process calculations from a text document (.txt) suffix

   b. From The console, input and output inside of the program.

   c. You can also save your calculations in version 1.35!

      When you complete your console based calculations, you will be prompted to save the results. 

2. The help menu has been improvised. Attempting to make it more interactive. 
   The help menu, when you exit, will now go back to the calculator. Using a callback procedure. 

3. The prompt is a little weird. It is a known bug. 
   I am still trying to figure out how to get a proper console output. 
End of Changelog for MCalculator 1.35!
*********************************************************************************************************************

*/

namespace CalculatorProgram
{
	void introText()
	{
		std::cout << "Welcome to MCalculator version 1.35!\n";
		std::cout << "This calculator is based on Tokens, and has a Token Stream built in.\n";
		std::cout << "\nThe basic premise: You enter 1 + 2; \n";
		std::cout << "This line has four Tokens in it: Token 1 = '1', Token 2 = '+', Token 3 = '2', and the final Token = ';'\n";
		std::cout << '\n' << '\n';
		std::cout << "To quit MCalculator 1.35, simply type in q, to view the help menu, for all available commands, type in 'h' \n";
	}
	void userChoiceText()
	{
		std::cout << "\nHow would you like to perform your calculations: \n\n";
		std::cout << " - Press c for Console Calculations(Command Line) -- The results will print out to the console\n";
		std::cout << '\n';
		std::cout << " - Press f if you would like to process calculations from a external file (.txt files) \n";
		std::cout << "**************************************************************************************\n";
		//<< "or x(input from file and output to file) ? \n";
	}
	int calculatorProgram()
	{
		try
		{
			using namespace ProgramTools::UniversalCalculatorTokenStreams;

			introText();
			TokenStream tokenStream;
			char choice{ ' ' };
			do
			{
				userChoiceText();
				std::cout << ProgramKeys::prompt;
				std::cin >> choice;
				switch (choice)
				{
				case 'c':
				{
					tokenStream.setInputStream(std::cin);
					Calculator consoleCalculations(std::move(tokenStream), &std::cout, &std::cin);
					consoleCalculations.calculate();
					std::cout << "Calculation Complete! Would you like to save your results to file? (Y/N) \n";
					char printChoice{ ' ' };
					std::cin >> printChoice;

					if (printChoice == 'y' || printChoice == 'Y')
					{
						std::cout << "Please enter the name of the file you would like to create for output. \n";
						std::string outputFilename{ " " };
						std::cin >> outputFilename;
						// Save the results to the outputfile
						consoleCalculations.writeResultsToFile(outputFilename);
						consoleCalculations.resetResults();
					}
					else if (printChoice == 'n' || printChoice == 'N')
					{
						consoleCalculations.resetResults();
					}
					else
					{
						consoleCalculations.resetResults();
						std::cerr << "An invalid command has been entered. \n";
					}
					break;
				}
				case 'f':
				{
					std::cout << "\nEnter the name of the file you would like to calculate: ";
					std::string inputFilename;
					std::cin >> inputFilename;

					std::cout << "Enter the name of the output file: " << std::endl;
					std::string outputFilename;
					std::cin >> outputFilename;

					Calculator fileCalculations(inputFilename, outputFilename);
					fileCalculations.processFile(inputFilename, outputFilename);
					break;
				}
				case 'q':
					std::cout << "Thank you for using MCalculator 1.35!\n";
					break;
				default:
					std::cerr << "Invalid Command Detected!\n";
					break;
				}
			} while (choice != 'q');



		}
		catch (const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
			return 1;
		}

		return 0;
	}
}

int main()
{
	// Initialize PLOGD: (Every program should initialize PLOGD)
	UniversalFunctionsToolset::plogdInit();
	//******************************************************* Code Here ******************************************************* // 

	CalculatorProgram::calculatorProgram();
	

	// ***************************************************** End of Code ****************************************************** //
	// Function to ask user to press enter to exit program. 
	UniversalFunctionsToolset::pauseConsole();

	return 0;
}