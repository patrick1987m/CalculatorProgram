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


// Using Declarations (simplifies access to both ErrorReportingSupport and programTools namespaces and sub-namespaces)
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

	}
	namespace UniversalTesting
	{ // This namespace is for testing purposes only. 
	  // Generally, my practice will end up here, as I am learning C++ 
	  // If the function variable, is deemed useable and useful, 
	  // it will be transfered.

		// basic function that prints Hello World!
		
		void printHello()
		{
			std::cout << "Hello World" << '\n';
		}

		// !!! Infinite loop! Take care when executing this function  !!!
		// !!! If this program is allowed to run continuously,        !!!
		// !!! it can crash the computer!					          !!!

		void dangerousLoop()
		{
			for (;;) // Primary ingredient for infinite loop! 
			{
				std::cout << "Warning! This is an infinite loop!" << '\n';
				std::cout << '\n';
				std::cout << '\n';
			}
		}

		// This function converts int to short, long, and char
		// Undesired results are to be expected! 

		void numericConversions()
		{
			short s = 3; // convert int to short
			std::cout << s << '\n';
			long l = 3; // convert int to long
			std::cout << l << '\n';
			char ch = s; // convert short to char
			std::cout << "Short to char = " << s << '\n';
			unsigned int u = 3; // convert int to unsigned int
		}

		void valuePreserver()
		{
			// converts int 3 to long and back
			int n = static_cast<int>(static_cast<long>(3));
			std::cout << n << '\n'; // prints 3

			// converts 'c' to double and back to char
			char c = static_cast<char>(static_cast<double>('c'));
			std::cout << c << '\n';
		}

		void printBadValue(unsigned int u) // note:: unsigned!
		{
			std::cout << u << '\n';
		}

		

		/*
		*The following group of functions are actual useable functions.
		* They simply determine what happens when you try to overflow
		* an unsigned integer!
		*/

		void doPrintReverseunSigned(); // forward declaration

		// Function to check for overflow of unsigned ints! 
		void doPrintunSigned()
		{
			unsigned short x{ 65535 };
			std::cout << "This simple program will show what happens: " << '\n';
			std::cout << "When you attempt to put a number larger than an accepted value: " << '\n';
			std::cout << "This is for (unsigned short) - 65535 - Largest 16-bit unsigned bit possible! " << '\n';
			std::cout << "\nx was: " << x << '\n';

			x = 65536; // 65536 is out of our range, so we get modulo wrap-around
			std::cout << "\nX will now wrap around out of unsigned range! " << '\n';
			std::cout << '\n';
			std::system("pause");
			std::cout << '\n';
			std::cout << "x { 65536}; is now: " << x << '\n';
			std::cout << "\nX will wrap one more time! " << '\n';
			std::cout << '\n';
			x = 65537;
			std::system("pause");
			std::cout << '\n';

			std::cout << "x { 65537 }; is now: " << x << '\n';
			doPrintReverseunSigned();

		}

		// Function to check for overflow if x = 0!
		void doPrintReverseunSigned()
		{
			unsigned short x{ 0 };
			std::cout << '\n';
			std::cout << "\nThe same could happen at the lower end of this range. " << '\n';
			std::cout << "if x { 0 };, x = -1; Would result in a wrap around the other way! " << '\n';
			x = -1; // -1 is out of our range now!
			std::cout << '\n';
			std::system("pause");
			std::cout << '\n';
			std::cout << "Under unsigned ints, when the initial value is set to 0 " << '\n';
			std::cout << "x being set to -1, will result in: " << x << '\n';
			std::cout << "\nOne more wrap around " << '\n';

			x = -2;
			std::cout << '\n';
			std::system("pause");

			std::cout << "When x is set to -2, the result is as follows: " << x << '\n';
		}

		/*
		** End of function case! 
		*****************************************************************/

		// The following function nullifies pointers!
		// It appears this is the only place I can make it work
		// I will be attempting to move it in the future.
		
		void nullify(int*& refptr) // refptr is now a reference to a pointer
		{
			refptr = nullptr; // Make the function parameter a null pointer
		}
		
	

		
	} // End of TestingPrograms Namespace
	
} // End of ProgramTools namespace

