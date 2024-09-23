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

		// This namespace is designed for building games
		// This namespace will have random number generators etc.

		// The following function will generate a random number for a 6 sided dice
		int numberGenerator(int number)
		{
			// Random device - Allows for random number verficication
			std::random_device rd;
			std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
			std::mt19937_64 mt{ ss };

			// Create a reusable random number generator for numbers 1-6
			std::uniform_int_distribution<> die6{ 1, 6 };
		tryAgain:
			std::cout << "Please enter the number of rolls you would like? " << '\n';
			std::cout << "Please note this program needs increments of 10: " << '\n';
			std::cout << "Please type -1 to exit this program.\n";
			std::cin >> number;
			char c{ };

			switch (number)
			{
			case -1:
				std::cout << "Thank you for rolling the Dice. This program will terminate!\n";
				return 0;

			case 10:
				for (int count{ 1 }; count <= 10; ++count)
				{
					std::cout << die6(mt) << '\t'; // generate a roll of the die
					// If we printed 10 numbers, new line
					if (count % 10 == 0)
						std::cout << '\n';
				}

				// First roll has finished here, ask user to roll again!
				std::cout << "Would you like to roll again?\n";
				std::cin >> c;
				if (c == 'y' || c == 'Y')
				{
					goto tryAgain;
				}
				else if (c == 'n' || c == 'N')
				{
					std::cout << "Thank you for playing!\n";
					return 0;
				}
				else
				{
					std::cout << "This program does not recognize that input. Terminating!\n";
					return -1;
				}
				break;

			case 20:
				for (int count{ 1 }; count <= 20; ++count)
				{
					std::cout << die6(mt) << '\t'; // generate a roll of the die
					// If we printed 10 numbers, new line
					if (count % 10 == 0)
						std::cout << '\n';
				}
				// First roll has finished here, ask user to roll again!
				std::cout << "Would you like to roll again?\n";
				std::cin >> c;
				if (c == 'y' || c == 'Y')
				{
					goto tryAgain;
				}
				else if (c == 'n' || c == 'N')
				{
					std::cout << "Thank you for playing!\n";
					return 0;
				}
				else
				{
					std::cout << "This program does not recognize that input. Terminating!\n";
					return -1;
				}
				break;

			case 30:
				for (int count{ 1 }; count <= 30; ++count)
				{
					std::cout << die6(mt) << '\t'; // generate a roll of the die
					// If we printed 10 numbers, new line
					if (count % 10 == 0)
						std::cout << '\n';
				}
				// First roll has finished here, ask user to roll again!
				std::cout << "Would you like to roll again?\n";
				std::cin >> c;
				if (c == 'y' || c == 'Y')
				{
					goto tryAgain;
				}
				else if (c == 'n' || c == 'N')
				{
					std::cout << "Thank you for playing!\n";
					return 0;
				}
				else
				{
					std::cout << "This program does not recognize that input. Terminating!\n";
					return -1;
				}
				break;

			case 40:
				for (int count{ 1 }; count <= 40; ++count)
				{
					std::cout << die6(mt) << '\t'; // generate a roll of the die
					// If we printed 10 numbers, new line
					if (count % 10 == 0)
						std::cout << '\n';
				}
				// First roll has finished here, ask user to roll again!
				std::cout << "Would you like to roll again?\n";
				std::cin >> c;
				if (c == 'y' || c == 'Y')
				{
					goto tryAgain;
				}
				else if (c == 'n' || c == 'N')
				{
					std::cout << "Thank you for playing!\n";
					return 0;
				}
				else
				{
					std::cout << "This program does not recognize that input. Terminating!\n";
					return -1;
				}
				break;

			case 50:
				for (int count{ 1 }; count <= 50; ++count)
				{
					std::cout << die6(mt) << '\t'; // generate a roll of the die
					// If we printed 10 numbers, new line
					if (count % 10 == 0)
						std::cout << '\n';
				}
				// First roll has finished here, ask user to roll again!
				std::cout << "Would you like to roll again?\n";
				std::cin >> c;
				if (c == 'y' || c == 'Y')
				{
					goto tryAgain;
				}
				else if (c == 'n' || c == 'N')
				{
					std::cout << "Thank you for playing!\n";
					return 0;
				}
				else
				{
					std::cout << "This program does not recognize that input. Terminating!\n";
					return -1;
				}
				break;

			case 60:
				for (int count{ 1 }; count <= 60; ++count)
				{
					std::cout << die6(mt) << '\t'; // generate a roll of the die
					// If we printed 10 numbers, new line
					if (count % 10 == 0)
						std::cout << '\n';
				}
				// First roll has finished here, ask user to roll again!
				std::cout << "Would you like to roll again?\n";
				std::cin >> c;
				if (c == 'y' || c == 'Y')
				{
					goto tryAgain;
				}
				else if (c == 'n' || c == 'N')
				{
					std::cout << "Thank you for playing!\n";
					return 0;
				}
				else
				{
					std::cout << "This program does not recognize that input. Terminating!\n";
					return -1;
				}
				break;

			case 70:
				for (int count{ 1 }; count <= 70; ++count)
				{
					std::cout << die6(mt) << '\t'; // generate a roll of the die
					// If we printed 10 numbers, new line
					if (count % 10 == 0)
						std::cout << '\n';
				}
				// First roll has finished here, ask user to roll again!
				std::cout << "Would you like to roll again?\n";
				std::cin >> c;
				if (c == 'y' || c == 'Y')
				{
					goto tryAgain;
				}
				else if (c == 'n' || c == 'N')
				{
					std::cout << "Thank you for playing!\n";
					return 0;
				}
				else
				{
					std::cout << "This program does not recognize that input. Terminating!\n";
					return -1;
				}
				break;

			case 80:
				for (int count{ 1 }; count <= 80; ++count)
				{
					std::cout << die6(mt) << '\t'; // generate a roll of the die
					// If we printed 10 numbers, new line
					if (count % 10 == 0)
						std::cout << '\n';
				}
				// First roll has finished here, ask user to roll again!
				std::cout << "Would you like to roll again?\n";
				std::cin >> c;
				if (c == 'y' || c == 'Y')
				{
					goto tryAgain;
				}
				else if (c == 'n' || c == 'N')
				{
					std::cout << "Thank you for playing!\n";
					return 0;
				}
				else
				{
					std::cout << "This program does not recognize that input. Terminating!\n";
					return -1;
				}
				break;

			case 90:
				for (int count{ 1 }; count <= 90; ++count)
				{
					std::cout << die6(mt) << '\t'; // generate a roll of the die
					// If we printed 10 numbers, new line
					if (count % 10 == 0)
						std::cout << '\n';
				}
				// First roll has finished here, ask user to roll again!
				std::cout << "Would you like to roll again?\n";
				std::cin >> c;
				if (c == 'y' || c == 'Y')
				{
					goto tryAgain;
				}
				else if (c == 'n' || c == 'N')
				{
					std::cout << "Thank you for playing!\n";
					return 0;
				}
				else
				{
					std::cout << "This program does not recognize that input. Terminating!\n";
					return -1;
				}
				break;

			case 100:
				for (int count{ 1 }; count <= 100; ++count)
				{
					std::cout << die6(mt) << '\t'; // generate a roll of the die
					// If we printed 10 numbers, new line
					if (count % 10 == 0)
						std::cout << '\n';
				}
				// First roll has finished here, ask user to roll again!
				std::cout << "Would you like to roll again?\n";
				std::cin >> c;
				if (c == 'y' || c == 'Y')
				{
					goto tryAgain;
				}
				else if (c == 'n' || c == 'N')
				{
					std::cout << "Thank you for playing!\n";
					return 0;
				}
				else
				{
					std::cout << "This program does not recognize that input. Terminating!\n";
					return -1;
				}
				break;
			default:
				std::cout << "You have not entered a number in a grouping of 10: 10, 20 etc.\n";
				goto tryAgain;
			}

			return number;
		} // End of function:
		// New Function here- future development


	}// End of namespace GamingTools
	namespace UniversalMathPatterns
	{

	}
	namespace UniversalScience
	{

	}
	namespace UniversalTesting
	{

	}

}// End of namespace ProgramTools