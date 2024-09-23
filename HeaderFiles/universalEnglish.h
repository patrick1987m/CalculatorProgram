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
{ // universalEnglish.h	
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
	{ // This namespace will hold many different parsers/ functions!
		// Create EnglishTools Class
		class EnglishTools
		{
		public:
			EnglishTools(char period = '.', char semicolon = ';', char comma = ',', char questionM = '?', char exclamation = '!', char colon = ':', char quotation = '"')
				: m_Period(period), m_Semicolon(semicolon), m_Comma(comma), m_QuestionM(questionM), m_ExclamationP(exclamation), m_Colon(colon), m_QuotationM(quotation) 
			{
			
			}

			

			// Define some functions to access the english Tool variables below:
			char getPeriod() { return m_Period; }
			char getSemicolon() { return m_Semicolon; }
			char getComma() { return m_Comma; }
			char getQuestionM() { return m_QuestionM; }
			char getExclamation() { return m_ExclamationP; }
			char getColon() { return m_Colon; }
			char getQuotation() { return m_QuotationM; }
		private:
			char m_Period{ '.' };
			char m_Semicolon{ ';' };
			char m_Comma{ ',' };
			char m_QuestionM{ '?' };
			char m_ExclamationP{ '!' };
			char m_Colon{ ':' };
			char m_QuotationM{ '"' };
		};
		// The following functions will print the alphabet a-z and A-Z (two seperate Functions)
		char printAlphabet() // prototype function: will improve over time! 
		{
			std::cout << '\n';
			std::cout << "This program will print the alphabet after the letter you entered. \n";
			std::cout << '\n';
			std::cout << "Press -1 to exit! \n";
			while (true)
			{
				char alphaBet{ ' ' };
				std::cout << "Please enter a character: (a-z or A-Z) \n";
				std::cin >> alphaBet;


				switch (alphaBet)
				{
				case 'a':
				case 'b':
				case 'c':
				case 'd':
				case 'e':
				case 'f':
				case 'g':
				case 'h':
				case 'i':
				case 'j':
				case 'k':
				case 'l':
				case 'm':
				case 'n':
				case 'o':
				case 'p':
				case 'q':
				case 'r':
				case 's':
				case 't':
				case 'u':
				case 'v':
				case 'w':
				case 'x':
				case 'y':
				case 'z':
					while (alphaBet <= 'z')
					{
						std::cout << alphaBet << ' ';
						++alphaBet;
					}
					break;
				case 'A':
				case 'B':
				case 'C':
				case 'D':
				case 'E':
				case 'F':
				case 'G':
				case 'H':
				case 'I':
				case 'J':
				case 'K':
				case 'L':
				case 'M':
				case 'N':
				case 'O':
				case 'P':
				case 'Q':
				case 'R':
				case 'S':
				case 'T':
				case 'U':
				case 'V':
				case 'W':
				case 'X':
				case 'Y':
					while (alphaBet <= 'Z')
					{
						std::cout << alphaBet << ' ';
						++alphaBet;
					}
					return true;
					break;

				default:
					std::cout << "That is an invalid character! \n";
					return false;
					break;
				}
				
			} // End of alphabet code
			std::cout << '\n';
			
		}
		//Function to determine if a letter is a vowel
		bool isVowel(char c)
		{

			switch (c)
			{
			case 'a':  // if c is 'a'
			case 'e': // or if c is 'e'
			case 'i':
			case 'o':
			case 'u':
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				std::cout << '\n';
				std::cout << "Your entered character is: " << c << '\n';
				std::cout << "According to the english rules, this is a vowel! " << '\n';
				std::cout << '\n';
				return true;
				break;
			default:
				std::cout << "That is not a valid character! " << '\n';
				return false;
				break;


			}
			return true;
		} // End of function isVowel()

		// Function to determine if a letter is a consonant

		bool isConsonants(char d)
		{

			switch (d)
			{
			case 'b':
			case 'c':
			case 'd':
			case 'f':
			case 'g':
			case 'h':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':
			case 'B':
			case 'C':
			case 'D':
			case 'F':
			case 'G':
			case 'H':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
				std::cout << '\n';
				std::cout << "Your entered character is: " << d << '\n';
				std::cout << "According to the english rules, this is a consonant! " << '\n';
				std::cout << '\n';
				return true;
				break;

			default:
				std::cout << "That is not a valid character! " << '\n';
				return  false;
				break;
			}
			return true;
		} // end of function isConsonant()

		//
		char englishParser(char input) // Beginning of englishParser()
		{ // This function is a front port for the boolean functions above
		  // Those are considered nested functions, inaccessable from this namespace

			std::cout << "English Parser 1.2: \"Updated edition expanded\"\n";
			std::cout << "********************************************************************************\n";
			std::cout << "* Updated: 06-23-2023:	Reworked program to not perform a nested function call!*\n";
			std::cout << "* The updated version, simplifies design, with the same output!		       *\n";
			std::cout << "* Please note: This program requires a character (A-Z or a-z)                  *\n";
			std::cout << "* To exit, any non letter character will work.                                 *\n";
			std::cout << "********************************************************************************\n";
			std::cout << '\n' << '\n';

			while (true)
			{
				std::cout << "Please enter a character: " << '\n';
				std::cin >> input;

				switch (input)
				{
				case 'a':  // if c is 'a'
				case 'e': // or if c is 'e'
				case 'i':
				case 'o':
				case 'u':
				case 'A':
				case 'E':
				case 'I':
				case 'O':
				case 'U':
					isVowel(input);
					break;
				case 'b':
				case 'c':
				case 'd':
				case 'f':
				case 'g':
				case 'h':
				case 'j':
				case 'k':
				case 'l':
				case 'm':
				case 'n':
				case 'p':
				case 'q':
				case 'r':
				case 's':
				case 't':
				case 'v':
				case 'w':
				case 'x':
				case 'y':
				case 'z':
				case 'B':
				case 'C':
				case 'D':
				case 'F':
				case 'G':
				case 'H':
				case 'J':
				case 'K':
				case 'L':
				case 'M':
				case 'N':
				case 'P':
				case 'Q':
				case 'R':
				case 'S':
				case 'T':
				case 'V':
				case 'W':
				case 'X':
				case 'Y':
				case 'Z':
					isConsonants(input);
					break;
				default:
					std::cout << "You entered: " << input << '\n';
					std::cout << "That is not a valid character! " << '\n';
					std::cout << "Now terminating! " << "....." << '\n';
					return false;
				}

			}
			return input;

		} // End of Function englishParser()


		

		

		// The following function will compare two string_views
		// Alphabetical!

		std::string_view firstAlphabetical(std::string_view s1, std::string_view s2)
		{
			return s1 < s2 ? s1 : s2;
		}

		// Future Functions here...


	} // End of namespace englishTools
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
	{

	}

	
} // End of namespace programTools