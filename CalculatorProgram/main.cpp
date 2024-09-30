#include "programTools.h"
/*
Calculator 1.2

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


**/
namespace CalculatorProgram
{
	// t.kind == number means that t is a number Token
	constexpr char number = '8';
	// t.kind == quit means that t is a quit Token
	constexpr char quit = 'q';
	// t.kind == print means t is a print Token
	constexpr char print = ';';

	// Let's Remove the Magic Constants for our prompt and result Token's
	const std::string prompt{ "=>: " };
	const std::string result{ "==: " };

	class Token
	{
	public:
		char m_kind;
		double m_value{ };
		// A few Token Constructors for use: Characters only
		Token(char k) : m_kind{ k }, m_value{ 0.0 } { }
		// A Token Constructor for use: Characters and values
		Token(char k, double value) : m_kind{ k }, m_value{ value } { }
	};
	class TokenStream
	{
	public:
		TokenStream() : full{ false }, buffer{ 0 } { }
		Token get();
		void putback(Token t);
		// Adding the ability to cleanup bad Tokens
		void ignore(char c);

	private:
		bool full{ false };
		Token buffer;
	};
	// Function to get the Next Token
	Token TokenStream::get()
	{   // Pre-condition: We need to make sure our TokenStream is empty: 
		if (full)
		{
			full = false;
			return buffer;
		}

		char ch{ };
		std::cin >> ch;
		switch (ch)
		{
		case print:
		case quit:

		// Added for factorials
		case '!':
		// Grouping cases:
		case '(': 
		case ')':
		case '{': 
		case '}':
		// Regular math operations 
		case '+': 
		case '-': 
		case '*': 
		case '/': 
		// (Version 1.2 Adds the ability to do Modulo (%) reminader cases:)
		case '%':
		// Added for bitwise capability:
		case '&': 
		case '|': 
		case '^': 
		case '<': 
		case '>':
			return Token(ch);
		// Numerical Cases and .
		case '.':
		case '0': case '1': case '2': case '3':
		case '4': case '5': case '6': case '7':
		case '8': case '9':
		{
			std::cin.putback(ch);
			double value{ };
			std::cin >> value;

			// Return our Token
			return Token{ '8', value };

		}
		default:
			ErrorReportingSupport::error("Bad Token");
		}
	}
	// Function to put back a Token onto our TokenStream
	void TokenStream::putback(Token t)
	{   // Pre-Condition: The TokenStream buffer must be empty
		if (full)
		{
			ErrorReportingSupport::error("putback() cannot function on a full buffer!");
		}
		buffer = t;
		full = true;
	}
	/*
	Our TokenStream class does not know what makes 
	a good calculator Token. This function will help:    */
	void TokenStream::ignore(char c)
	{   // char 'c' represents the kind of Token we are looking for:
		if (full && c == buffer.m_kind)
		{
			full = false;
			return;
		}
		// Now we search for input
		char ch = 0;

		while (std::cin >> ch)
		{
			if (ch == c)
			{
				return;
			}
		}
	}

	// Create tokenStreams -- This needs to be invoked, to access the putback and get functions:
	TokenStream tokenStreams;
	// Need this forward declaration of expression:
	double expression();
	// Handle Factorials 
	int factorial(int n)
	{   // This function will calculate Factorials !
		// Non-recursive implementation
		// Pre-Condition
		if (n < 0)
		{
			ErrorReportingSupport::error("factorial(), invoked with a negative number!");
		}
		int f = 1;

		if (n != 0)
		{
			while (n > 0)
			{
				f *= n;
				--n;
			}
		}
		return f;
	}

	// Primary Function
	double primary()
	{
		Token t = tokenStreams.get();

		double d{ 0.0 };

		switch (t.m_kind)
		{
		case '(':
		{
			d = expression();
			t = tokenStreams.get();
			if (t.m_kind != ')')
			{
				ErrorReportingSupport::error("')' expected!");
			}
			return d;
		}
		case '{':
		{
			d = expression();

			t = tokenStreams.get();

			if (t.m_kind != '}')
			{
				ErrorReportingSupport::error("'}' expected!");
			}
			return d;
		}
		case number:
			return t.m_value;
		case '-':
			d = -primary();
			break;
		case '+':
			d = primary();
			break;
		case '~':         // The bitwise NOT Operator
			d = static_cast<int>(primary());
			return ~static_cast<int>(d);
		default:
			tokenStreams.putback(t);
			return d;
		}
	}

	// Factorial Parser Function
	double factorialParser()
	{
		double left = primary();
		Token t = tokenStreams.get();

		// We do not need a while loop like in term() because ! is a unary operator
		switch (t.m_kind)
		{
		case '!':
			return factorial(left);
		default:
			tokenStreams.putback(t);
			return left;
		}
	}
	// Function to Handle * and /
	double term()
	{
		double left = factorialParser();
		Token t = tokenStreams.get();
		/*
		*/
		while (true)
		{
			switch (t.m_kind)
			{
			case '*':
				left *= factorialParser();
				t = tokenStreams.get();
				break;
			case '/':
			{
				double d = factorialParser();

				if (d == 0.0)
				{
					ErrorReportingSupport::error("Error: Can not divide by zero.");
				}
				left /= d;
				t = tokenStreams.get();
				break;
			}
			case '%':
			{
				double d = factorialParser();

				if (d == 0.0)
				{
					ErrorReportingSupport::error("%: Cannot divide by zero!");
				}
				left = std::fmod(left, d);

				t = tokenStreams.get();
				break;
			}
			default:
				tokenStreams.putback(t);
				return left;
			}
		}
	}
	// Function to handle our Bitwise operators
	double bitwise()
	{
		double left = term();
		Token t = tokenStreams.get();
		/**/
		while (true)
		{
			switch (t.m_kind)
			{
			case '&':
				left = static_cast<int>(left) & static_cast<int>(term());
				t = tokenStreams.get();
				break;
			case '|':
				left = static_cast<int>(left) | static_cast<int>(term());
				break;
			case '^':
				left = static_cast<int>(left) ^ static_cast<int>(term());
				break;
			case '<':
				t = tokenStreams.get();
				if (t.m_kind == '<')
				{
					int shiftAmount = static_cast<int>(term());

					if (static_cast<int>(left) > (std::numeric_limits<int>::max() >> shiftAmount))
					{
						left = std::numeric_limits<int>::max();
					}
					else
					{
						left = static_cast<int>(left) << shiftAmount;
					}
					t = tokenStreams.get();
				}
				else
				{
					ErrorReportingSupport::error("'<<' expected!");
				}
				break;
			case '>':
				t = tokenStreams.get();

				if (t.m_kind == '>')
				{
					left = static_cast<int>(left) >> static_cast<int>(term());

					t = tokenStreams.get();
				}
				else
				{
					ErrorReportingSupport::error("'>>' expected!");
				}
				break;
			default:
				tokenStreams.putback(t);
				return left;
			}
		}
	}
	// Function to Parse + and -
	double expression()
	{
		double left = bitwise();
		Token t = tokenStreams.get();
		/*
		*/
		while (true)
		{
			switch (t.m_kind)
			{
			case '+':
				left += bitwise();
				t = tokenStreams.get();
				break;
			case '-':
				left -= bitwise();
				t = tokenStreams.get();
				break;
			default:
				tokenStreams.putback(t);
				return left;
			}
		}
	}
	void introText()
	{
		std::cout << "Welcome to our simple calculator. \n"
			<< "Please enter expressions using floating-point numbers. \n"
			<< "Below you will find the logical operations available for this version of the calculator: \n"
			<< '\n' << '\n'
			<< "1. (Grouping with: () and {} and factorial with '!') \n2. (Normal Math Operations: +, -, *, / (version 1.2 Adds % or Remainder))\n"
			<< "3. (Bitwise Operators: &, |, ^, ~, <<, >>)\n"
			<< '\n'
			<< "This program will evaluate your expression in the order of the above: With Grouping and factorials being first\n"
			<< "\nSome basic rules: \n\n"
			<< " 1.) This program follows PEMDAS(Parenthesis, Exponents(not available at the moment), Multiplication, \n"
			<< "     Division, Addition, Subtraction.)\n"
			<< "\n 2.) A complete expression requires a terminating ';', which is the keyword for print. \n"
			<< "\n 3.) To exit the program: Enter 'q' !\n"
			<< "\nExample Expressions: \n"
			<< "\n1.) Single Expressions: 1+2; "
			<< '\n'
			<< "\n2.) Multiple expressions on one line: 1+2; 5-1; 6*7; "
			<< '\n'
			<< "      When using the calculator with many expressions on one Line: Notice! This will be improved in a later edition. "
			<< "\n                                                                 >1+2; 5-1; 6*7; "
			<< "\n                                                                 = > : 3 "
			<< "\n                                                                 >=> : 4 "
			<< "\n                                                                 >=> : 42 "
			<< "\n3.) We can even handle complex operations: (1+2)*(5-2); Even (1+2)*(5-1)*(8*1); or as complex as you can imagine. "
			<< "\n4.) With Edition 1.2, you can also type in remainder cases: 5%2; "
			<< "\n\n";
	}

	// Function to handle cleanup operations:
	void cleanUp()
	{
		tokenStreams.ignore(print);
	}

	// Function for our calculations:
	void calculate()
	{
		while (std::cin)
		try{
			std::cout << ">";
			Token t = tokenStreams.get();
			while (t.m_kind == print)
			{
				t = tokenStreams.get();
			}
			if (t.m_kind == quit)
			{
				std::cout << "\nThank you for using our simple Calculator!\n";
				return;
			}
			tokenStreams.putback(t);

			std::cout << prompt << expression() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			cleanUp();
		}
	}
	
	// Main Program Logic
	int calculatorLogic()
	{
		try
		{
			introText();
			calculate();
			return 0;
		}
		catch (...)
		{
			std::cerr << "Oops! Unknown Exceptions Caught!\n";
			return 1;
		}
	}
}
int main()
{
	// Initialize PLOGD: (Every program should initialize PLOGD)
	UniversalFunctionsToolset::plogdInit();
	//******************************************************* Code Here ******************************************************* // 

	CalculatorProgram::calculatorLogic();

	// ***************************************************** End of Code ****************************************************** //
	// Function to ask user to press enter to exit program. 
	UniversalFunctionsToolset::pauseConsole();

	return 0;
}