#pragma once
// ProgramTools Functions only!
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
	namespace Random
	{
		// Returns a seeded Mersenne Twister
		// Note: we'd prefer to return a std::seed_seq (to initialize a std::mt19937), but std::seed can't be copied, so it can't be returned by value.
		// Instead, we'll create a std::mt19937, seed it, and then return the std::mt19937 (which can be copied).
		inline std::mt19937 generate()
		{
			std::random_device rd{};

			// Create seed_seq with clock and 7 random numbers from std::random_device
			std::seed_seq ss{
				static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
					rd(), rd(), rd(), rd(), rd(), rd(), rd() };

			return std::mt19937{ ss };
		}

		// Here's our global std::mt19937 object.
		// The inline keyword means we only have one global instance for our whole program.
		inline std::mt19937 mt{ generate() }; // generates a seeded std::mt19937 and copies it into our global object

		// Generate a random int between [min, max] (inclusive)
		inline int get(int min, int max)
		{
			return std::uniform_int_distribution{ min, max }(mt);
		}

		// The following function templates can be used to generate random numbers
		// when min and/or max are not type int
		// See https://www.learncpp.com/cpp-tutorial/function-template-instantiation/
		// You can ignore these if you don't understand them

		// Generate a random value between [min, max] (inclusive)
		// * min and max have same type
		// * Return value has same type as min and max
		// * Supported types:
		// *    short, int, long, long long
		// *    unsigned short, unsigned int, unsigned long, or unsigned long long
		// Sample call: Random::get(1L, 6L);             // returns long
		// Sample call: Random::get(1u, 6u);             // returns unsigned int
		template <typename T>
		T get(T min, T max)
		{
			return std::uniform_int_distribution<T>{min, max}(mt);
		}

		// Generate a random value between [min, max] (inclusive)
		// * min and max can have different types
		// * Must explicitly specify return type as template type argument
		// * min and max will be converted to the return type
		// Sample call: Random::get<std::size_t>(0, 6);  // returns std::size_t
		// Sample call: Random::get<std::size_t>(0, 6u); // returns std::size_t
		// Sample call: Random::get<std::int>(0, 6u);    // returns int
		template <typename R, typename S, typename T>
		R get(S min, T max)
		{
			return get<R>(static_cast<R>(min), static_cast<R>(max));
		}
	}
	namespace ProgramToolsFunctions
	{
		/****************************************************************************************/
	/* This is a grouped function: characterToNumber() can not be called seperately requires*/
	/* characterPrinter() calls characterToNumber()                                         */
	/****************************************************************************************/
		inline void characterToNumber(double x)
		{
			std::cout << x << '\n';

		}
		inline void characterPrinter()
		{
			char input{ };
			std::cout << "This simple program will convert your symbol or character into a ASCII letter code. ";
			std::cout << "Please enter a number, character or symbol: " << '\n';
			std::cin >> input;

			characterToNumber(input);

		}
		/*** End of grouped function! */
		/******************************************************************************************/

		// Overloaded function to get a users input: either int or double allowed.
		inline int getValueFromUserReturn(int input)
		{ // this function will run as long as the user does not enter a non-number
			std::cout << "To terminate: (type in -1) " << '\n';
			while (true)
			{
				std::cout << "\nEnter an integer: " << '\n';
				std::cin >> input;

				if (input == -1)
				{
					std::cout << "That is a terminating character! " << '\n';
					return false;
				}

				else
				{
					std::cout << "\nInput = " << input;

				}
			}
			return input;
		}

		inline double getValueFromUserReturn(double input)
		{
			// this function will run as long as the user does not enter a non-number

			// this function will run as long as the user does not enter a non-number
			std::cout << "To terminate: (type in -1) " << '\n';
			while (true)
			{
				std::cout << "\nEnter an integer: " << '\n';
				std::cin >> input;

				if (input == -1)
				{
					std::cout << "That is a terminating character! " << '\n';
					return false;
				}

			}
			return input;
		}

		// ignoreLine() This function will ignore the rest of an input stream
		inline void ignoreLine()
		{ // ie: 7*9+3, only the 7 would be preserved with this function.
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		// pauseConsole() a function to pause the console and wait for a return input
		inline void pauseConsole()
		{
			// Reset any error flags
			std::cin.clear();

			// Ignore any characters in the input buffer until we find a newline
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Please Press any Key to continue . . . (Preferably Enter)\n";
			// Get one more character from the user 
			// (Waits for the user to press enter)
			// std::cin.get();
		}
	}
	namespace UniversalTimingCode
	{
		// A simple class to create a timer in your code:
		class Timer
		{
		public:
			void reset()
			{
				m_beg = Clock::now();
			}
			double elapsed() const
			{
				return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
			}
		private:
			using Clock = std::chrono::steady_clock;
			using Second = std::chrono::duration<double, std::ratio<1> >;

			std::chrono::time_point<Clock> m_beg{ Clock::now() };
		};
	}
}