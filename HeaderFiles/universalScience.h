#pragma once
// C++ Standard Libraries
#include<algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include<chrono>
#include<cmath>
#include <cstdarg>
#include <cstdint>
#include<cstdlib>
#include <format>
#include <forward_list>
#include<fstream>
#include<functional>
#include<iomanip>
#include<iostream>
#include <iterator>
#include <initializer_list>
#include <limits>
#include<list>
#include <map>
#include <memory>
// #include <mdspan>
#include <numeric>
#include<random>
#include<ranges>
#include <regex>
#include <set>
#include <span>
#include<sstream>
#include<stdexcept>
#include<string>
#include<stdint.h>
#include<string_view>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include<unordered_map>
#include <utility>
#include<vector>

// Error Reporting and Support!

#include "ErrorReportingSupport.h"

// User Defined HeaderFiles
#include "programTools.h"
#include "programToolsFunctions.h"
#include "universalEnglish.h"
#include "universalGaming.h"
#include "universalMathPatterns.h"
#include "universalScience.h"
#include "universalTesting.h"

namespace ErrorReportingSupport
{

}
using namespace ErrorReportingSupport;


namespace ProgramTools
{
	namespace UniversalFunctionsToolset
	{
		namespace BasicRandomGeneration
		{

		}
		namespace UniversalTimingCode
		{

		}
	}

	namespace UniversalEnglish
	{

	}
	namespace UniversalGaming
	{

	}
	namespace UniversalMathPatterns
	{

	}
	namespace UniversalScience
	{
		
		constexpr double gravity = 9.8;
		
		void printSizeof()
		{ // The usage of sizeof(type) allows the programmer 
			std::cout << "bool:\t\t" << sizeof(bool) << " bytes\n";
			std::cout << "char:\t\t" << sizeof(char) << " bytes\n";
			std::cout << "wchar:\t\t" << sizeof(wchar_t) << " bytes\n";
			std::cout << "char16_t:\t" << sizeof(char16_t) << " bytes\n";
			std::cout << "char32_t:\t" << sizeof(char32_t) << " bytes\n";
			std::cout << "short:\t\t" << sizeof(short) << " bytes\n";

			std::cout << "int:\t\t" << sizeof(int) << " bytes\n";
			std::cout << "long:\t\t" << sizeof(long) << " bytes\n";
			std::cout << "long long:\t" << sizeof(long long) << " bytes\n";
			std::cout << "float:\t\t" << sizeof(float) << " bytes\n";
			std::cout << "double:\t\t" << sizeof(double) << " bytes\n";
			std::cout << "long double:\t" << sizeof(long double) << " bytes\n";
		}

		// The following functions will allow for calculations based on + - * /
		// This is a grouped function set! All must be present for this to work!

		double getDouble()
		{
			while (true)
			{
				std::cout << "Enter a decimal number: ";
				double x{ };
				std::cin >> x;

				// check for failed extraction
				if (!std::cin) // if the previous extraction failed
				{
					if (std::cin.eof()) // if the stream was closed
					{
						std::exit(0);
					}

					// lets handle the failure
					std::cin.clear(); //puts us back into normal operating mode

					
					std::cout << "Oops, the input is invalid. Please try again. \n";
				}
				else
				{
					
					return x;
				}
			}
		}

		char getOperator()
		{
			while (true)
			{
				std::cout << "Enter one of the following: +, -, *, /: \n";

				char operation{ ' ' };
				std::cin >> operation;

				if (!std::cin) // if the previous extraction failed
				{
					if (std::cin.eof()) // if the stream was closed
					{
						std::exit(0); // terminate app
					}

					// Lets handle the failure
					std::cin.clear(); // put us back in normal operation mode

				}
				 // remove any extraneous input
				
				// Check the actual user input
				switch (operation)
				{
				case '+':
				case '-':
				case '*':
				case '/':
					return operation;
				default:
					std::cout << "Oops, that input is invalid. Please Try Again. \n";
				}
			}
		}

		void printResult(double x, char operation, double y)
		{
			switch (operation)
			{
			case '+':
				std::cout << x << " + " << y << " = " << x + y;
				break;
			case '-':
				std::cout << x << " - " << y << " = " << x - y;
				break;
			case '*':
				std::cout << x << " multiplied by " << y << " = " << x * y;
				break;
			case '/':
				std::cout << x << " divided by " << y << " = " << x / y;
				break;
			default:  // Being robust means handling unexpected parameters as well, even though getOperator() 
				// guarantees operation is valid in this particular program
				std::cout << "Something went wrong: printResult() got an invalid operator. \n";
				break;
			}
		}

		void calculatorPlus()
		{
			// This is the primary function, for which all the previous functions depend on for calling and execution.
			// One function necessary in main now!
			double x{ getDouble() };
			char operation{ getOperator() };
			double y{ getDouble() };

			printResult(x, operation, y);
		}

		// The following Code is to evaluate fractions + - * /
		
		struct Fraction
		{
			int numerator{ };
			int denominator{ };
			int common{ };
		};

		Fraction getFraction()
		{
			Fraction temp{ };
			std::cout << "\nPlease enter the value for the numerator: \n";
			std::cin >> temp.numerator;
			std::cout << "\nPlease enter the value for the denominator: \n";
			std::cin >> temp.denominator;
	
			return temp;
		}

		Fraction add(const Fraction& f1, const Fraction& f2)
		{
			return { f1.numerator + f2.numerator, f1.denominator + f2.denominator };
		}

		Fraction subtraction(const Fraction& f1, const Fraction& f2)
		{
			return { f1.numerator - f2.numerator, f1.denominator - f2.denominator };
		}
		Fraction multiply(const Fraction& f1, const Fraction& f2)
		{
			return { f1.numerator * f2.numerator, f1.denominator * f2.denominator };
		}

		Fraction division(const Fraction& f1, const Fraction& f2)
		{
			return { f1.numerator / f2.numerator, f1.denominator / f2.denominator };
		}

		void printFraction(const Fraction& f)
		{
			std::cout << '\t' << " " << f.numerator << '\n';
			std::cout << '\t' << "---" << '\n';
			std::cout << '\t' << " " << f.denominator << '\n';
		}

		void fractionMenu(const Fraction& menu)
		{
			std::cout << "************************************************" << '\n';
			std::cout << "* This program will evaluate fractions.        * " << '\n';
			std::cout << "* Several operations available: + - * /        *" << '\n';
			std::cout << "* 1 = +, 2 = -, 3 = *, 4 = /                   *" << '\n';
			std::cout << "************************************************" << '\n';

			while (true)
			{
				int selection{ };
				Fraction f1{ getFraction() };
				Fraction f2{ getFraction() };

				std::cout << '\n';
				std::cout << "Please select from the following: " << '\n';
				std::cout << "1. For Addition. " << '\n';
				std::cout << "2. For Subtraction. " << '\n';
				std::cout << "3. For Multiplication. " << '\n';
				std::cout << "4. For Division." << '\n';
				std::cout << '\n';
				std::cin >> selection;

				switch (selection)
				{
				case 1:
					std::cout << '\n';
					std::cout << "You have selected Fraction Addition: " << '\n';
					std::cout << '\n';
					printFraction(add(f1, f2));
					break;
				case 2:
					std::cout << '\n';
					std::cout << "You have selected Fraction Subtraction: " << '\n';
					std::cout << '\n';
					printFraction(subtraction(f1, f2));
					break;
				case 3:
					std::cout << '\n';
					std::cout << "You have selected Fraction multiplication: " << '\n';
					std::cout << '\n';
					printFraction(multiply(f1, f2));
					break;
				case 4:
					std::cout << '\n';
					std::cout << "You have selected Fraction division: " << '\n';
					std::cout << '\n';
					printFraction(division(f1, f2));
					break;
				default:
					std::cout << "That is not a recognizable number: " << '\n';
					std::cout << "Terminating Application... " << '\n';
					std::system("pause");
					std::exit(1);
				}

			}
		}
		// End of Fraction process

		/*int64_t pow(int base, int exponent) // disabling for namespace
		{                                        portability with std namespace
			int64_t total{ 1 };

			for (int count{ 0 }; count < exponent; ++count)
				total *= base;
			return total;
		}*/

		// User Defined Functions Below this Line
		double plusOne(static double s_state) // Simple algorithm that adds one to the previous number
		{

			++s_state;
			return s_state;
		} // End of function plusOne()

		// Ball Drop function - calculate drop to ground
		double calculateHeight(double initialHeight, int seconds)
		{
			double distanceFallen{ ProgramTools::UniversalScience::gravity * seconds * seconds / 2};
			double heightNow{ initialHeight - distanceFallen };

			// Check whether we have went sub-ground level
			if (heightNow < 0.0)
			{
				return 0.0;
			}
			else
			{
				return heightNow;
			}

		}
		// Auxillary function - calls ball drop function
		void calculatePrintHeight(double initialHeight, int time)
		{
			std::cout << "At " << time << " seconds, the ball is at height: "
				<< calculateHeight(initialHeight, time) << '\n';
		}

		// This function will determine if a number is prime
		bool isPrime(int x)
		{	// if x is negative, 0, or 1, the number is not prime
			if (x <= 1)
				return false;
			// If the number is 2 or higher, we need an algorithm to see if there is
			// a divisor
			int maxTest{ static_cast<int>(sqrt(x)) }; // compute the maximum number to test

			for (int test{ 2 }; test <= maxTest; ++test)
			{
				if (x % test == 0)
				{
					std::cout << "Sorry, that number is not a prime number!\n";
					return true;
				}

				}
				std::cout << "You have entered: " << x << " which is prime!\n";
				return true; // if we didnt fine any divisors, then x must be prime
		}

		// function to ask for and call isPrime() - 
		void printIsPrime()
		{
			while (true)
			{
				std::cout << "Please enter an integer: " << '\n';
				int x{ };
				std::cin >> x;

				if (x == -1)
				{
					std::cout << "isPrime() will now terminate!\n";
					std::exit(0);
				}
				else if (x >= 0)
				{
					isPrime(x);
				}
			}
		}

		// this function will print the values of range between two inputed values
		double rangePrinter(double x, double y)
		{
			x = 0.0;
			y = 0.0;
			std::cout << "Please enter two integers'('floating point is okay 0.0 for example')': " 
				<< std::endl;
			std::cin >> x >> y;

			while (x <= y)
			{
				std::cout << x << '\t';
				++x;
			}
			return x;
		}
		
		// this function is a running total calculator. Addition only!
		int runningTotalCalculate(int x, int sum)
		{
			x = 0;
			sum = 0;
			std::cout << "Enter as many numbers as you need added: ";
			std::cout << "Terminate with non number!";

			while (std::cin >> x)
			{
				sum += x;
			}
			std::cout << "The sum of all your numbers is " << sum;
			return sum;
		}

		// this function counts how many times a number is duplicated if at all
		// any duplicated number gets stored in a vector, later displayed.
		void printNumberCount()
		{
			std::vector<double> duplicateNumbers { };
			double currentValue{ };
			double value{ };
			std::cout << "This small program will detect duplicate numbers: " << '\n';
			std::cout << "Enter numbers at random or in repeat if you like. " << '\n';
			std::cout << "Enter a non number, to terminate! " << '\n';
			// read first number and ensure we have data to process
			if (std::cin >> currentValue)
			{
				double cnt = 1;  // store the count for the current value we are processing
				while (std::cin >> value)
				{ // read the remaining numbers
					if (value == currentValue)
					{
						++cnt;
						duplicateNumbers.push_back(value);
					}
					else
					{ // otherwise, print the count for the previous value
						std::cout << currentValue << " occurs "
							<< cnt << " times!" << '\n';
						currentValue = value; // remember the new value
						cnt = 1;      // reset the counter
					}
				}
				std::cout << currentValue << " occurs "
					<< cnt << " times!" << '\n';
				std::cout << "Here are the duplicate numbers listed in the duplicate number vector! ";
				for (int i = 0; i < duplicateNumbers.size(); i++)
				{
					std::cout << duplicateNumbers.at(i) << ' ';
				}
			}
		}

		// Future functions here...

	} // End of namespace ScienceTools

	namespace UniversalTesting
	{

	}

} // End of namespace ProgramTools


 