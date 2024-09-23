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
using namespace ProgramTools;

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
	{ // First Revision: (this line subject to change)
	  // mathPatterns namespace version 1.0    Date of Change: 07-06-2023
	  // Changes Performed

	  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	   * This namespace will be the primary location for all Math patterns     *  
	   * and algorithms that can assist in many current and future projects.   *
	   * While, these may seem silly, they could end up being useful!          *
	   *																	   *	
	   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

	   // Begin of namespace work area!


		
		/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*													   *	
		*		The next few functions, will print values,	   *	
		*	1-5 in unique patterns as seen below!              *
		*													   *
		* * * * * * * * * * * * * * * * * * * * * * * * * * * **/                                         
		
		void printPatternNormal()
		{
			/* * * * * * * * * * * * * * * * * 
			*	This pattern is simple:	     *
			*                                *
			*	1							 *	
			*	1 2                          *
			*	1 2 3                        *
			*	1 2 3 4                      *
			*	1 2 3 4 5                    *                  
			*                                *
			* * * * * * * * * * * * * * * * **/
			
			//Outer loops between 1 and 5
			int outer{ 1 };
			while (outer <= 5)
			{
				// For each iteration of the outer loop.
				// The code in the body of the loop executes once.
				int inner{ 1 };
				while (inner <= outer)
				{
					std::cout << inner << ' ';
					++inner;
				}

				//Print a newline at the end of each row
				std::cout << '\n';
				++outer;
			}
		} // end of Print Normal Pattern Function
		
		void invertNormalPattern()
		{ // The following function will invert the former pattern!
			/* * * * * * * * * * * * * * * * *
			*	This pattern is simple:	     *
			*                                *
			*	5 4 3 2 1				     *
			*	4 3 2 1                      *
			*	3 2 1                        *
			*	2 1                          *
			*	1                            *
			*                                *
			* * * * * * * * * * * * * * * * **/

			int outer{ 5 };
			while (outer >= 1)
			{
				// Loop between outer and 1
				int inner{ outer };
				while (inner >= 1)
				{
					std::cout << inner-- << ' ';
				}

				// Print a newline at the end of each row
				std::cout << '\n';
				--outer;
			}
		} // end of inverted Normal Function
	
		void reverseInvertedPattern()
		{	// The following function will print values 1 - 5 in a unique pattern
			// Logically it is a reverse inverted Pattern 
			/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
			*	This program will use a while loop to display some numbers shifted right!  *
			*  See the example below:													   *
			*  Instead of:																   *
			*																			   *
			*				1															   *
			*               1 2															   *
			*				1 2 3														   *
			*				1 2 3 4														   *
			*				1 2 3 4													       *
			*				1 2 3 4 5													   *
			*																			   *
			*	We will print this:														   *
			*																			   *
			*				1															   *
			*			  2 1															   *
			*			3 2 1															   *
			*		  4 3 2 1															   *
			*		5 4	3 2 1															   *
			*																			   *
			* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

			// There are 5 rows, we can loop from 1 to 5
			int outer{ 1 };
			
			while (outer <= 5)
			{
				// Row elements appear in appear in descending order, so start from 5 and loop 
				// to 1
				int inner{ 5 };

				while (inner >= 1)
				{
					// The first number in any row is the same as the row number
					// So number should be printed only if it is <= the row number, space otherwise
					if (inner <= outer)
					{
						std::cout << inner << ' '; // print the number and a single space
					}
					else
					{
						std::cout << "  "; // don't print a number, but print two spaces
					}
					--inner;
				}

				// A row has been printed, move to the next row
				std::cout << '\n';

				++outer;
			} // end of entire loop
			
		} // end of Reverse Inverted Function

		

		void reverseInvertedPatternTriangle()
		{  // The following function will print values 1 - 5 in a unique pattern
			// Logically it is a reverse inverted Pattern in a triangle formation !
			/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
			*	This program will use a while loop to display some numbers shifted right!  *
			*  See the example below:													   *
			*  Instead of:																   *
			*																			   *
			*				1															   *
			*               1 2															   *
			*				1 2 3														   *
			*				1 2 3 4														   *
			*				1 2 3 4													       *
			*				1 2 3 4 5													   *
			*																			   *
			*	We will print this:														   *
			*																			   *
			*				1															   *
			*			   2 1															   *
			*			  3 2 1															   *
			*		     4 3 2 1														   *
			*		    5 4	3 2 1														   *
			*																			   *
			* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

			// There are 5 rows, we can loop from 1 to 5
			int outer{ 1 };

			while (outer <= 5)
			{
				// Row elements appear in appear in descending order, so start from 5 and loop 
				// to 1
				int inner{ 5 };

				while (inner >= 1)
				{
					// The first number in any row is the same as the row number
					// So number should be printed only if it is <= the row number, space otherwise
					if (inner <= outer)
					{
						std::cout << inner << ' '; // print the number and a single space
					}
					else
					{
						std::cout << " "; // don't print a number, but print one space 
						// (creating the triangle)
					}
					--inner;
				}

				// A row has been printed, move to the next row
				std::cout << '\n';

				++outer;
			} // end of entire loop
			
		} // end of function

		// Future Function Development Here!

	} // end of namespace mathPatterns
	namespace UniversalScience
	{

	}
	namespace UniversalTesting
	{

	}
} // end of namespace programTools
