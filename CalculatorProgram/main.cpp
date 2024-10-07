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
********************************************************************************************************************************/
#include "programTools.h"
namespace CalculatorProgram
{

	// We will Start with our Constants: These are Tokens to run the program:
	const char number = '8';             // t.m_kind==number means that t is a number Token 
	const char quit = 'q';               // t.m_kind==quit means that t is a quit Token
	const char print = ';';              // t.m_kind==print means that t is a print Token
	const char name = 'b';               // t.m_kind==name means that t is a variable Token
	const char underscore = '_';         // Not a Token but can be used in variable names

	const char let = 'L';                // Variable Declaration Token 
	const char stable = 'C';             // Our constant variable Token
	const char sqrtt = 'S';              // Our SquareRoot Token 
	const char poww = 'P';               // Our Exponent Token 
	const char help = 'h';               // Our Help Token
	const char advancedExamples{ 'a' };
	const char basicExamples{ 'e' };
	const char hQuit{ 'z' };
	const std::vector<char> tokenKinds{ let, stable, sqrtt, poww, help, advancedExamples, basicExamples, hQuit };

	// Constant Keywords:
	const std::string letKey = "let";
	const std::string stableKey = "const";
	const std::string sqrtKey = "sqrt";
	const std::string powKey = "pow";
	const std::string helpKey = "help";
	const std::string advExKey = "adv";
	const std::string baseKey = "baseK";
	const std::string helpQuit = "helpQuit";
	const std::vector<std::string> keywords{ letKey, stableKey, sqrtKey, powKey, helpKey, advExKey, baseKey, helpQuit };

	// Constants for a prompt and output:
	const std::string prompt = "> ";
	const std::string result = "= ";     // Used to indicate that what follows is a result

	// A very simple user-defined type (This is where we will define what a Token is!)
	class Token
	{
	public:

		Token(char ch) : m_kind{ ch }, m_value{ 0.0 } { }
		Token(char ch, double value) : m_kind{ ch }, m_value{ value } { }
		Token(char ch, std::string& n) : m_kind{ ch }, m_name{ n } { }

		char m_kind{ ' ' };             // What kind of Token are we dealing with?   
		double m_value{ 0.0 };          // For Numbers: a value 
		std::string m_name{ " " };      // For Names: name itself
	};

	// TokenStream class
	class TokenStream
	{
	public:
		// Make a TokenStream that reads from std::cin
		TokenStream();
		// Function to get a Token
		Token get();
		// Function to put a Token back
		void putback(Token t);
		// Discards characters up to and including a c
		void ignore(char c);

	private:
		bool full;
		std::vector<Token> m_buffer{ };
	};

	// TokenStream Constructor!
	TokenStream::TokenStream()
		: full{ false }, m_buffer{ } { }

	// Function to put back a Token
	void TokenStream::putback(Token t)
	{
		if (!m_buffer.empty() && full)
		{
			throw std::runtime_error("putback() failed to operate on a full buffer!");
		}
		m_buffer.push_back(t);

		full = true;
	}


	// Function to read characters from std::cin to compose a Token
	Token TokenStream::get()
	{   // Check if we had already a Token!

		if (!m_buffer.empty() && full)
		{
			Token t = m_buffer.back();
			m_buffer.pop_back();
			return t;
		}
		char ch{ };
		// Note: std::cin.get() does NOT skip whitespace!
		ch = static_cast<char>(std::cin.get());

		while (std::isspace(ch) && ch != '\n')
		{
			ch = static_cast<char>(std::cin.get());
		}
		// std::cout << "Character read: " << ch << std::endl;    // Debug print remove later

		switch (ch)
		{
		case advancedExamples:
	
		case print:
		case quit:
		case help:
		

		case '\n':
			if (ch == '\n') return Token(print);
			// std::cout << "Token Created: " << ch << std::endl;
			// Added for Factorials!
		case '!':
			return Token(ch);
			// Added for exponents!
		case '^':
			// Grouping Cases:
		case '(':
		case ')':
		case '{':
		case '}':
			// Regular Math operations including Remainder:
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
			// Added for Bitwise Capability
		case '&':
		case '|':
		case '~':  // Originaly was ^, but changed to ~ because I am using ^ for exponent calculations! Bitwise XOR
		case '<':
		case '>':

			// Added for assignment
		case '=':
			// std::cout << "Token Created: " << ch << std::endl;   // Debug print
			return Token(ch);
			// Floating point numbers can start with a . (0.1 for example!)
		case '.':
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		{
			std::cin.putback(ch);
			double value{ };
			// Read a floating-point number
			std::cin >> value;
			// std::cout << "Number token created: " << value << std::endl;
			return Token(number, value);
		}
		default:
			if (std::isalpha(ch))
			{
				std::string s{ };
				s += ch;

				while (std::cin.get(ch) && (std::isalpha(ch) || std::isdigit(ch) || ch == underscore)) s += ch;
				std::cin.putback(ch);

				for (int i = 0; i != keywords.size(); ++i)
				{
					if (s == keywords[i])
					{
						// std::cout << "Keyword token created: " << s << std::endl;
						return Token(tokenKinds[i]);
					}
				}
				// std::cout << "Name token created: " << s << std::endl;
				return Token{ name, s };

			}
			ErrorReportingSupport::error("Bad Token!");
			return Token{ '\0' };
		}
	}

	// Ingore Tokens up to a specifc kind
	void TokenStream::ignore(char c)
	{   // First look into the buffer 
		while (!m_buffer.empty() && m_buffer.back().m_kind != c)
		{
			m_buffer.pop_back();
		}
		if (!m_buffer.empty() && m_buffer.back().m_kind == c)
		{
			m_buffer.pop_back();
			return;
		}

		char ch{ ' ' };

		while (std::cin.get(ch))
		{
			if (ch == c || ch == '\n')
			{
				return;
			}
		}
	}
	/*************************************************************************************************/
	// Type for varTable and associated Functions:
	class SymbolTable
	{
	public:
		// Return the value of the Variable named s
		double get(const std::string& varName);
		// Set the Variable named s
		void set(const std::string& s, double d);
		// Is our Variable already in the varTable?
		bool isDeclared(std::string& var);
		// Add (var, val) to varTable
		void declare(std::string& varName, double value, bool isConst = false);
		// Function to print
		void print();
	private:
		// Declare our Variable Struct here instead of using previous class
		struct Variable
		{
			std::string m_name;
			double m_value;
			bool m_isConstant;
		};
		// A vector of Variables
		std::vector<Variable> varTable;
	};
	// Is var already in varTable?
	bool SymbolTable::isDeclared(std::string& var)
	{
		for (const Variable& v : varTable)
		{
			if (v.m_name == var) return true;
		}
		return false;
	}
	// Add (var, val) to varTable
	void SymbolTable::declare(std::string& varName, double value, bool isConst)
	{
		if (isDeclared(varName)) ErrorReportingSupport::error(varName, " declared twice");

		varTable.push_back(Variable{ varName, value, isConst });
	}
	// Return the value of the Variable named s
	double SymbolTable::get(const std::string& varName)
	{
		for (const Variable& var : varTable)
		{
			if (var.m_name == varName) return var.m_value;
		}
		ErrorReportingSupport::error("get: undefined variable ", varName);
		return 0.0;
	}
	// Function to set the Variable named s to d
	void SymbolTable::set(const std::string& varName, double value)
	{
		for (Variable& var : varTable)
		{
			if (var.m_name == varName)
			{
				if (var.m_isConstant)
				{
					ErrorReportingSupport::error("set: cannot modify a constant variable! ", varName);
				}
				var.m_value = value;
				return;
			}
		}
		ErrorReportingSupport::error("set: undefined variable ", varName);
	}
	// Function to Print
	void SymbolTable::print()
	{
		for (Variable var : varTable)
		{
			std::cout << var.m_name << " = " << var.m_value;

			if (var.m_isConstant) std::cout << " (constant)";
			std::cout << '\n';
		}
	}
	/***************************************************************************************************/
	// Provides SymbolTable's get(), set(), isDeclared() and declare() functions
	SymbolTable symbolTable;

	/***************************************************************************************************/

	// Function Prototypes:
	double expression(TokenStream& tokenStreams);

	double primary(TokenStream& tokenStreams);

	// Function to determine overflow in our factorial Cases:
	bool factorialOverflow(int n)
	{
		return 0 > std::numeric_limits<int>::max() - n;
	}

	// Function to Compute factorial of n!
	int factorial(int n)
	{
		if (n < 0) ErrorReportingSupport::error("factorial: Factorial is only defined for non-negative real numbers!");
		int res = 1;

		while (n > 1)
		{
			res *= n--;
			if (factorialOverflow(res)) ErrorReportingSupport::error("factorial: Factorial Overflow Occurred!");
		}

		return res;
	}

	// Function to deal with the Factorial Cases:
	double factorialParser(TokenStream& tokenStreams)
	{
		double left = primary(tokenStreams);
		Token t = tokenStreams.get();
		while (true)
		{
			if (t.m_kind == '!')
			{
				if (left != static_cast<int>(left) || left < 0)
				{
					ErrorReportingSupport::error("Factorial is only defined for non-negative integers!");
				}
				left = factorial(static_cast<int>(left));
				t = tokenStreams.get();
			}
			else if (t.m_kind == '^')
			{
				double factorialExponent = primary(tokenStreams);
				left = std::pow(left, factorialExponent);

				t = tokenStreams.get();
			}
			else
			{
				tokenStreams.putback(t);
				return left;
			}
		}
	}
	// Function that deals with numbers, unary (+/-), parenthesis, ~Not Bitwise, names
	double primary(TokenStream& tokenStreams)
	{
		Token t = tokenStreams.get();
		double result = 0.0;
		switch (t.m_kind)
		{
		case '(':
		{
			result = expression(tokenStreams);
			t = tokenStreams.get();

			if (t.m_kind != ')') ErrorReportingSupport::error("')' expected!");

			return result;
		}
		case '{':
		{
			result = expression(tokenStreams);

			t = tokenStreams.get();

			if (t.m_kind != '}') ErrorReportingSupport::error("'}' expected!");

			return result;
		}
		case '^':
		{
			double base = primary(tokenStreams);
			double exponent = primary(tokenStreams);
			return std::pow(base, exponent);
		}
		case '!':
			return factorialParser(tokenStreams);
		case number:
			return t.m_value;
		case name:
		{
			std::string varName = t.m_name;
			return symbolTable.get(varName);
		}
		// Handle Sqrt
		case sqrtt:
		{
			t = tokenStreams.get();
			if (t.m_kind != '(')
			{
				ErrorReportingSupport::error("'(' expected after 'sqrt' \n");
			}
			double result = expression(tokenStreams);
			t = tokenStreams.get();

			if (t.m_kind != ')')
			{
				ErrorReportingSupport::error("')' expected!");
			}
			if (result < 0)
			{
				ErrorReportingSupport::error("sqrt: Cannot process a negative number!");
			}
			return std::sqrt(result);
		}
		case poww:
		{
			t = tokenStreams.get();

			if (t.m_kind != '(') ErrorReportingSupport::error("\'(\' expected after pow keyword");

			double base = expression(tokenStreams);

			t = tokenStreams.get();
			if (t.m_kind != ',') ErrorReportingSupport::error("\',\' expected after the base");
			int exp = static_cast<int>(expression(tokenStreams));
			t = tokenStreams.get();
			if (t.m_kind != ')') ErrorReportingSupport::error("\')\' expected after exp");

			return std::pow(base, exp);

		}

		case '-':
			result = -primary(tokenStreams);
			return result;
		case '+':
			result = primary(tokenStreams);
			return result;
		case '~':
			result = static_cast<int>(primary(tokenStreams));
			return ~static_cast<int>(result);
		case print:
			return 0.0;
		default:
			tokenStreams.putback(t);
			ErrorReportingSupport::error("primary expected!");
			return 0.0;

		}
	}

	double expression(TokenStream& tokenStreams)
	{
		double left = factorialParser(tokenStreams);

		Token t = tokenStreams.get();

		while (true)
		{
			switch (t.m_kind)
			{
			case '+':
				left += factorialParser(tokenStreams);
				t = tokenStreams.get();
				break;
			case '-':
				left -= factorialParser(tokenStreams);
				t = tokenStreams.get();
				break;
			case '*':
				left *= factorialParser(tokenStreams);
				t = tokenStreams.get();
				break;
			case '/':
			{
				double division{ factorialParser(tokenStreams) };
				if (division == 0) ErrorReportingSupport::error("Cannot Divide by zero!");
				left /= division;
				t = tokenStreams.get();
				break;
			}
			case '%':
			{
				double modulo{ factorialParser(tokenStreams) };
				if (modulo == 0.0) ErrorReportingSupport::error("Remainder: Cannot Divide by zero!");
				left = std::fmod(left, modulo);
				t = tokenStreams.get();
				break;
			}
			case '&':
				left = static_cast<int>(left) & static_cast<int>(factorialParser(tokenStreams));
				t = tokenStreams.get();
				break;
			case '|':
				left = static_cast<int>(left) | static_cast<int>(factorialParser(tokenStreams));
				t = tokenStreams.get();
				break;
			case '~':
				left = static_cast<int>(left) ^ static_cast<int>(factorialParser(tokenStreams));
				t = tokenStreams.get();
				break;
			case '<':
			{
				int shiftAmount = static_cast<int>(factorialParser(tokenStreams));
				if (shiftAmount < 0 || shiftAmount >= (sizeof(int) * 8))
				{
					ErrorReportingSupport::error("shift amount out of range");
				}
				left = static_cast<int>(left) << shiftAmount;
				t = tokenStreams.get();
				break;
			}
			case '>':
			{
				int shiftAmount = static_cast<int>(factorialParser(tokenStreams));
				if (shiftAmount < 0 || shiftAmount >= (sizeof(int) * 8))
				{
					ErrorReportingSupport::error("shift amount out of range");
				}
				left = static_cast<int>(left) >> shiftAmount;
				t = tokenStreams.get();
				break;
			}
			default:
				tokenStreams.putback(t);
				return left;
			}
		}
	}

	/*
	Assume we have seen "let" or "const"
	Handle: name = expression

	Declare a variable called "name" with the initial vallue "expression"  */
	double declaration(char kind, TokenStream& tokenStreams)
	{
		Token t = tokenStreams.get();
		if (t.m_kind != name) ErrorReportingSupport::error("name expected in declaration!");
		std::string varName = t.m_name;
		if (symbolTable.isDeclared(varName)) ErrorReportingSupport::error(varName, " declared twice!");

		// Check part by part of Declaration grammar rule behind "let" or "const"
		Token t2 = tokenStreams.get();
		if (t2.m_kind != '=') ErrorReportingSupport::error("= missing in declaration of ", varName);

		double value = expression(tokenStreams);
		symbolTable.declare(varName, value, t.m_kind == stable);
		return value;
	}

	// Function that handles declarations and expressions:
	double statement(TokenStream& tokenStreams)
	{
		Token t = tokenStreams.get();

		if (t.m_kind == let)
		{   // Handle Variable Declaration
			return declaration(let, tokenStreams);
		}
		else if (t.m_kind == stable)
		{
			return declaration(stable, tokenStreams);
		}
		else
		{
			tokenStreams.putback(t);
			return expression(tokenStreams);
		}
	}
	// Function to clean up After an error:
	void cleanUp(TokenStream& tokenStreams)
	{
		tokenStreams.ignore(print);
	}

	void printHelpMenu();
	void printExamples();
	void printAdvancedExamples()
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
			std::cout << prompt;
			std::cin >> returnMenu;
			switch (returnMenu)
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
				std::cout << "Thank you for using MCalculator 1.3's Interactive Help Menu! Advanced Page! \n";
				ProgramToolsFunctions::pauseConsole();
				return;
			default:
				throw std::runtime_error("printAdvancedExamples() does not recognize that command. Fatal Error Occured. Press Enter To Continue... \n");
				return;
			}
		}
	}
	// Function for Help Menu: This is where all commands will be relocated to:
	void printExamples()
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
			std::cout << prompt;
			// Add the Ability to Access the Advanced Commands Screen:
			char advancedExpressions{ ' ' };
			std::cin >> advancedExpressions;

			switch (advancedExpressions)
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
				std::cout << "Thank you for using MCalculator 1.3's Interactive Help Menu! -- Examples Page Now Exiting!\n";
				ProgramToolsFunctions::pauseConsole();
				return;
				
			default:
				throw std::runtime_error("printExamples() does not recognize that character! Fatal Error Occured. Press Enter To Continue... \n");
				return;
			}
		}
	}

	void printHelpMenu()
	{
		while (true)
		{
			std::system("CLS");
			std::cout << "Welcome to MCalculator 1.3's Help Menu: \n";
			std::cout << "\nThis page will contain the necessary key's to operate the program: \n";
			std::cout << "\n1.) To Access the Help Menu, enter h\n";
			std::cout << "\n2.) To Exit the Program, enter q\n";
			std::cout << "\n3.) This calculator can handle the following operations: +, -, *, /, %(Modulo or Remainder): \n";
			std::cout << "\n4.) With sqrt(Number here), you can find the sqrt of a number. \n";
			std::cout << "\n5.) If you want to determine exponents, you can do so with the ^ key. \n";
			std::cout << "\nTo end a Statement, use a ';', This is the program's print character!\n\n";
			std::cout << '\n';
			std::cout << "If you would like to see a list of examples of simple examples, press e now: \n";
			std::cout << "If you would like to see the Advanced Functions, enter a! \n";
			std::cout << "To get back to the calculator, press z at this time:  \n";
			std::cout << prompt;

			char examples{ ' ' };
			std::cin >> examples;

			switch (examples)
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
				std::cout << "Thank you for Using MCalculator 1.3's Interactive Help Menu! \n";
				ProgramToolsFunctions::pauseConsole();
				return;
			default:
				throw std::runtime_error("printHelpMenu(): Does Not recognize that command. Fatal Error Occured. Press Enter To Continue... ");
				return;
			}
		}
		
	}
	// Function to Handle our Calculations:
	void calculate(TokenStream& tokenStreams)
	{
		bool newLine = true;
		while (true)
		{
			try
			{
				if (newLine)
				{
					std::cout << prompt;
					newLine = false;
				}

				Token t = tokenStreams.get();

				while (t.m_kind == print) t = tokenStreams.get();

				if (t.m_kind == quit)
				{
					std::cout << "\nThank you for using MCalculator 1.3! \n" << std::endl;
					return;
				}

				if (t.m_kind == help)
				{
					std::system("CLS");
					printHelpMenu();
					tokenStreams.ignore(print);
					newLine = true;
					continue;
				}
				else
				{
					tokenStreams.putback(t);
					std::cout << result << std::setprecision(12) << statement(tokenStreams) << std::endl;
				}
				// Process the remaining expressions in the same line
				while (true)
				{
					t = tokenStreams.get();

					if (t.m_kind == print)
					{
						newLine = true;
						break;
					}
					else if (t.m_kind == quit)
					{
						std::cout << "\nThank you for using MCalculator 1.3! \n" << std::endl;
						return;
					}
					else if (t.m_kind == help)
					{
						printHelpMenu();
						tokenStreams.ignore(print);
						newLine = true;
						break;
					}
					else
					{
						tokenStreams.putback(t);
						std::cout << result << std::setprecision(12) << statement(tokenStreams) << std::endl;
					}
				}
			}
			catch (const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
				tokenStreams.ignore(print);
				cleanUp(tokenStreams);
				newLine = true;
			}
		}
	}

	void introText()
	{
		std::cout << "Welcome to MCalculator version 1.3!\n";
		std::cout << "This calculator is based on Tokens, and has a Token Stream built in.\n";
		std::cout << "\nThe basic premise: You enter 1 + 2; \n";
		std::cout << "This line has four Tokens in it: Token 1 = '1', Token 2 = '+', Token 3 = '2', and the final Token = ';'\n";
		std::cout << '\n' << '\n';
		std::cout << "To quit MCalculator 1.3, simply type in q, to view the help menu, for all avaliable commands, type in 'h' \n";
	}
	// Main Calculator Logic
	int calculatorLogic()
	{
		try
		{
			introText();
			// calculate();
			TokenStream tokenStreams;
			calculate(tokenStreams);
			// testingCalculate(tokenStreams);
			return 0;
		}
		catch (...)
		{
			std::cerr << "Oops! An Unknown Exception was caught!\n";
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