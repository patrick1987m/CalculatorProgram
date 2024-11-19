#pragma once
// C++ Standard Libraries
#include<algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include<chrono>
#include<cmath>
#include <cstdarg>
#include <cstdint>
#include<cstdlib>
#include<ctime>
// #include <date/date.h>
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
#include<locale>
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
#include <unordered_set>
#include<unordered_map>
#include <utility>
#include<vector>

// Error Reporting and Support!

#include "ErrorReportingSupport.h"

// PLOG Header Files
#include "plog/Log.h"
#include "plog/Initializers/RollingFileInitializer.h"

// User Defined HeaderFiles
#include "programTools.h"
#include "universalFunctionalToolset.h"
#include "universalEnglish.h"
#include "universalGaming.h"
#include "universalMathPatterns.h"
#include "universalScience.h"
#include "universalTesting.h"
/*This File Will Contain the processes for the TokenStream Calculator with help menu*/
using namespace ProgramTools;



namespace ProgramTools
{
    namespace UniversalCalculatorTokenStreams
    {
        namespace ProgramKeys
        {
            // Program Keys: These are reserved Tokens for program operations:
            const char number = '8';
            const char quit = 'q';
            const char print = ';';
            const char name = 'b';
            const char underscore = '_';
            const char romanNumerals = 'r';
            const char let = 'L';
            const char stable = 'C';
            const char sqrtt = 'S';
            const char poww = 'P';
            const char help = 'h';
            const char advancedExamples = 'a';
            const char basicExamples = 'e';
            const char hQuit = 'z';
            const char colonText = ':';
            // A vector that TokenStream::get() function uses
            const std::vector<char> tokenKinds{ number, quit, name, underscore, romanNumerals, let, stable, sqrtt, poww,
                help, advancedExamples, basicExamples, hQuit };
            // Constant Keywords
            const std::string letKey = "let";
            const std::string stableKey = "const";
            const std::string sqrtKey = "sqrt";
            const std::string powKey = "pow";
            const std::string helpKey = "help";
            const std::string advExKey = "adv";
            const std::string baseKey = "baseK";
            const std::string helpQuit = "helpQuit";
            const std::string romanKey = "roman";
            // A vector that the TokenStream::get() function uses, to determine the key
            const std::vector<std::string> keywords{ letKey, stableKey, sqrtKey, powKey, helpKey, advExKey,
            baseKey, helpQuit, romanKey };
            // Constants for a prompt and output:
            const std::string prompt = "> ";
            const std::string result = "= ";
        }

        // For our Calculator, we first need to establish the Help Menu System:
        class HelpMenu
        {
        public:
            HelpMenu() = default;

            HelpMenu(std::function<void()> callback) : callback(callback) { }
            void printHelpMenu();
            void printExamples();
            void printAdvancedExamples();

        private:
            const std::string helpPrompt = "\nEnter your choice: ";
            std::function<void()> callback;
            
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
                    callback();
                    return;
                default:
                    std::cout << "Unrecognized Command. Please Try Again! \n";
                    break;
                }
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
                    std::cout << "Thank you for using MCalculator 1.35's Interactive Help Menu!\n";
                    callback();
                    return;
                default:
                    std::cout << "Unrecognized Command. Please Try Again! \n";
                    break;
                }
                
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
                    std::cout << "Thank you for using MCalculator 1.35's Interactive Help Menu!\n";
                    callback();
                    return;
                default:
                    std::cout << "Unrecognized Command. Please Try Again! \n";
                    break;
                }
                
            }
        }
        // Roman Numeral Calculations:
        class RomanNum
        {
        public:
            RomanNum() : m_value(0) { }
            RomanNum(int value) : m_value(value) { }
            RomanNum(const std::string& roman) : m_value(romanToInt(roman)) { }

            // Additional Functions
            int asInt() const { return m_value; }

            // Arithmetic operators:
            RomanNum operator+(const RomanNum& other) const { return RomanNum(m_value + other.m_value); }
            RomanNum operator-(const RomanNum& other) const { return RomanNum(m_value - other.m_value); }
            RomanNum operator*(const RomanNum& other) const { return RomanNum(m_value * other.m_value); }
            RomanNum operator/(const RomanNum& other) const {
                if (other.m_value == 0) throw std::runtime_error("Division by zero");
                return RomanNum(m_value / other.m_value);
            }
            // Comparison Operators:
            bool operator==(const RomanNum& other) const { return m_value == other.m_value; }
            bool operator!=(const RomanNum& other) const { return m_value == other.m_value; }

            friend std::ostream& operator<<(std::ostream& os, const RomanNum& r);
            friend std::istream& operator>>(std::istream& is, RomanNum& r);
        private:
            int m_value;

            static int romanToInt(const std::string& roman);
            static std::string intToRoman(int value);
        };
        // Roman Numeral Function to convert a Roman Numeral into an integer
        int RomanNum::romanToInt(const std::string& roman)
        {
            std::map<char, int> romanMap = {
                {'I', 1}, {'V', 5}, {'X', 10}, {'L', 500},
                {'C', 100}, {'D', 500}, {'M', 1000}
            };
            int result = 0;
            int prevValue = 0;

            for (auto it = roman.rbegin(); it != roman.rend(); ++it)
            {
                int currentValue = romanMap[*it];

                if (currentValue < prevValue)
                {
                    result -= currentValue;
                }
                else
                {
                    result += currentValue;
                }

                prevValue = currentValue;
            }
            return result;
        }
        // Function to convert an integer into a Roman Numeral
        std::string RomanNum::intToRoman(int value)
        {
            std::map<int, std::string> romanMap = {
                {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
                {100, "C"}, {90, "XC"}, {50, "L"},{40, "XL"},
                {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
            };

            std::string result;

            for (const auto& pair : romanMap)
            {
                while (value >= pair.first)
                {
                    result += pair.second;
                    value -= pair.first;
                }
            }
            return result;
        }
        // Functions to handle input and output of Roman Numerals
        std::ostream& operator<<(std::ostream& os, const RomanNum& r)
        {
            os << RomanNum::intToRoman(r.m_value);

            return os;
        }
        std::istream& operator>>(std::istream& is, RomanNum& r)
        {
            std::string roman;

            is >> roman;
            r.m_value = RomanNum::romanToInt(roman);
            return is;
        }
        // Token and TokenStream implementations:
        class Token
        {
        public:
            char m_kind;
            double m_value;
            std::string m_name;
            RomanNum m_roman;

            Token(char ch) : m_kind(ch), m_value(0), m_roman() { }
            Token(char ch, double val) : m_kind(ch), m_value(val), m_roman() { }
            Token(char ch, const std::string& name) : m_kind(ch), m_value(0), m_name(name), m_roman() { }
            Token(char ch, const RomanNum& roman) : m_kind(ch), m_value(0), m_roman(roman) { }
        };
        // TokenStream: This is the Stream that processes the individual Tokens from above:
        class TokenStream
        {
        public:
            // Constructors:
            TokenStream();
            TokenStream(const std::string& inputFilename, const std::string& outputFilename);
            TokenStream(std::istream& is, std::ostream& os);

            // Delete copy constructor and copy assignment operator
            TokenStream(const TokenStream&) = delete;
            TokenStream& operator=(const TokenStream&) = delete;
            // Implement move constructor and move assignment operator
            TokenStream(TokenStream&& other) noexcept;
            TokenStream& operator=(TokenStream&& other) noexcept;

            // Methods to handle file streams
            bool openInputFile(const std::string& filename);
            bool openOutputFile(const std::string& filename);
            void closeFiles();
            // Methods to set and get streams
            void setInputStream(std::istream& input);
            void setOutputStream(std::ostream& output);
            void setErrorStream(std::ostream& error);
            std::istream& getInputStream();
            std::ostream& getOutputStream();
            std::ostream& getErrorStream();

            // Function to get a Token
            Token get();

            // Function to Put a Token back
            void putback(Token t);
            // Discards characters up to and including a c
            void ignore(char c);
        private:
            // Helper Functions to reduce the complexity of the get function:
            bool readChar(char& ch);
            Token readNumber(char ch);
            bool isRomanNumeral(char ch);
            Token readRomanNumeral(char ch);
            Token readIdentifierOrKeyword(char ch);
            // Necessary Parts for the TokenStream
            bool full;
            Token m_buffer;
            std::ifstream inputFileStream;
            std::ofstream outputFileStream;
            std::istream* inputStream;
            std::ostream* outputStream;
            std::ostream* errorStream;
        };
        // Default Constructor Definition:
        TokenStream::TokenStream()
            : full{ false }, m_buffer{ 0 }, inputStream{ &std::cin }, outputStream{ &std::cout },
            errorStream{ &std::cerr } { }
        // TokenStream Constructor Definition for file input and output:
        TokenStream::TokenStream(const std::string& inputFilename,
            const std::string& outputFilename)
            : full{ false }, m_buffer{ 0 }, inputStream{ nullptr }, outputStream{ nullptr },
            errorStream{ &std::cerr }
        {
            openInputFile(inputFilename);
            openOutputFile(outputFilename);
        }
        // TokenStream Constructor for choosing input and output Streams:
        TokenStream::TokenStream(std::istream& is, std::ostream& os)
            : full{ false }, m_buffer{ 0 }, inputStream(&is), outputStream(&os),
            errorStream{ &std::cerr } { }
        // Functions to determine if the input and output file is open:
        bool TokenStream::openInputFile(const std::string& filename)
        {
            inputFileStream.open(filename);

            if (!inputFileStream)
            {
                throw std::runtime_error("Failed to open input file: " + filename);
            }
            inputStream = &inputFileStream;
            return true;
        }
        // Move Constructor
        TokenStream::TokenStream(TokenStream&& other) noexcept
            : full(other.full), m_buffer(std::move(other.m_buffer)),
            inputFileStream(std::move(other.inputFileStream)),
            outputFileStream(std::move(other.outputFileStream)),
            inputStream(other.inputStream), outputStream(other.outputStream),
            errorStream(other.errorStream)
        {
            other.inputStream = nullptr;
            other.outputStream = nullptr;
            other.errorStream = nullptr;
        }

        // Move assignment operator
        TokenStream& TokenStream::operator=(TokenStream&& other) noexcept {
            if (this != &other)
            {
                full = other.full;
                m_buffer = std::move(other.m_buffer);
                inputFileStream = std::move(other.inputFileStream);
                outputFileStream = std::move(other.outputFileStream);
                inputStream = other.inputStream;
                outputStream = other.outputStream;
                errorStream = other.errorStream;

                other.inputStream = nullptr;
                other.outputStream = nullptr;
                other.errorStream = nullptr;
            }
            return *this;
        }
        bool TokenStream::openOutputFile(const std::string& filename)
        {
            outputFileStream.open(filename);

            if (!outputFileStream)
            {
                throw std::runtime_error("Failed to open output file: " + filename);
            }
            outputStream = &outputFileStream;
            return true;
        }
        // Function to Close opened files:
        void TokenStream::closeFiles()
        {
            if (inputFileStream.is_open())
            {
                inputFileStream.close();
            }
            if (outputFileStream.is_open())
            {
                outputFileStream.close();
            }
        }
        // Functions to set the Input Stream, Output Stream, and the Error Stream
        void TokenStream::setInputStream(std::istream& input)
        {
            inputStream = &input;
        }
        void TokenStream::setOutputStream(std::ostream& output)
        {
            outputStream = &output;
        }
        void TokenStream::setErrorStream(std::ostream& error)
        {
            errorStream = &error;
        }
        // Functions to get the Input Stream, Output Stream, and the Error Stream:
        std::istream& TokenStream::getInputStream()
        {
            return *inputStream;
        }
        std::ostream& TokenStream::getOutputStream()
        {
            return *outputStream;
        }
        std::ostream& TokenStream::getErrorStream()
        {
            return *errorStream;
        }
        // Function to put back a Token
        void TokenStream::putback(Token t)
        {
            if (full)
            {
                throw std::runtime_error("putback() failed to operate on a full buffer!");
            }
            m_buffer = t;
            full = true;
        }
        // Function to read characters from std::cin to compose Tokens
        Token TokenStream::get()
        {   // Check if we had already a Token!
            if (full)
            {
                full = false;
                return m_buffer;
            }
            char ch{ };
            if (!readChar(ch))
            {
                return Token(ProgramKeys::quit);
            }

            while (std::isspace(ch) && ch != '\n')
            {
                if (!readChar(ch))
                {
                    return Token(ProgramKeys::quit);
                }
            }
            if (ch == '\n')
            {
                return Token(ProgramKeys::print);
            }
            // Now to go through our Tokens
            switch (ch)
            {
            case ProgramKeys::advancedExamples:
            case ProgramKeys::print:
            case ProgramKeys::quit:
            case ProgramKeys::help:
            case '!':
                return Token(ch);
            case '^':
            case '(':
            case ')':
            case '{':
            case '}':
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '&':
            case '|':
            case '~':
            case '<':
            case '>':
            case '=':
                return Token(ch);
            case '.':
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                return readNumber(ch);
            default:
                if (isRomanNumeral(ch))
                {
                    return readRomanNumeral(ch);
                }
                else if (std::isalpha(ch))
                {
                    return readIdentifierOrKeyword(ch);
                }
                throw std::runtime_error("Bad Token!");
            }
        }
        // Function To Determine if we can read a character:
        bool TokenStream::readChar(char& ch)
        {
            if (inputStream->get(ch))
            {
                return true;
            }
            else
            {
                if (inputStream->eof())
                {
                    return false;
                }
                else
                {
                    throw std::runtime_error("Error reading from input stream.");
                }
            }
        }
        // Function to Read a number:
        Token TokenStream::readNumber(char ch)
        {
            inputStream->putback(ch);
            double value;
            *inputStream >> value;

            return Token(ProgramKeys::number, value);
        }
        // Function to Determine if a number is Roman Numeral:
        bool TokenStream::isRomanNumeral(char ch)
        {
            return ch == 'I' || ch == 'V' || ch == 'X' || ch == 'L' || ch == 'C' || ch == 'D' || ch == 'M';
        }
        // Function to Read in a Roman Numeral
        Token TokenStream::readRomanNumeral(char ch)
        {
            std::string roman;
            roman += ch;
            while (inputStream->get(ch) && isRomanNumeral(ch))
            {
                roman += ch;
            }
            inputStream->putback(ch);
            RomanNum romanNums(roman);
            return Token(ProgramKeys::romanNumerals, romanNums);
        }
        // Function To read in an Identified Keyword:
        Token TokenStream::readIdentifierOrKeyword(char ch)
        {
            std::string s;
            s += ch;
            while (inputStream->get(ch) && (std::isalpha(ch) || std::isdigit(ch)
                || ch == ProgramKeys::underscore))
            {
                s += ch;
            }
            inputStream->putback(ch);

            for (int i = 0; i != ProgramKeys::keywords.size(); ++i)
            {
                if (s == ProgramKeys::keywords[i])
                {
                    return Token(ProgramKeys::tokenKinds[i]);
                }
            }

            return Token(ProgramKeys::name, s);
        }
        // Function to Ignore Tokens up to a specific kind:
        void TokenStream::ignore(char c)
        {   // First look into the buffer
            if (full && m_buffer.m_kind == c)
            {
                full = false;
                return;
            }

            char ch{ ' ' };

            while (*inputStream >> ch)
            {
                if (ch == c || ch == '\n')
                {
                    return;
                }
            }
        }
        // The Symbol Table Declaration: This is what deals with let and const and variables
        class SymbolTable
        {
        public:
            // Return the value of the Variable named s
            double get(const std::string& varName);
            // Set the Variable named s
            void set(const std::string& s, double d);
            // Is our Variable already in the varTable?
            bool isDeclared(const std::string& var) const;
            // Add (var, val) to varTable
            void declare(const std::string& varName, double value, bool isConst = false);
            // Function to Print
            void print() const;
        private:
            struct Variable
            {
                std::string m_name;
                double m_value;
                bool m_isConstant;
            };
            // A vector of Variables
            std::vector<Variable> varTable;
            std::istream* inputStream;
            std::ostream* outputStream;
        };
        // Is the variable in varTable?
        bool SymbolTable::isDeclared(const std::string& var) const
        {
            for (const Variable& v : varTable)
            {
                if (v.m_name == var) return true;
            }
            return false;
        }
        // Declare: A function to add (var, val) into std::vector<Variable> varTable:
        void SymbolTable::declare(const std::string& varName, double value, bool isConst)
        {
            if (isDeclared(varName))
            {
                std::cerr << varName << " is declared twice!";
                return;
            }

            varTable.push_back(Variable{ varName, value, isConst });
        }
        // Return the value of the Variable named s
        double SymbolTable::get(const std::string& varName)
        {
            for (const Variable& var : varTable)
            {
                if (var.m_name == varName) return var.m_value;
            }
            std::cerr << "get: undefined variable " << varName;
            return 0.0;
        }
        // Function to set the variable named s to d
        void SymbolTable::set(const std::string& varName, double value)
        {
            for (Variable& var : varTable)
            {
                if (var.m_name == varName)
                {
                    if (var.m_isConstant)
                    {
                        std::cerr << "set: cannot modify a constant variable!" << varName;
                        return;
                    }
                    var.m_value = value;
                    return;
                }
            }
            std::cerr << "set: undefined variable " << varName;
        }
        // A function to print a symbol:
        void SymbolTable::print() const
        {
            for (const Variable& var : varTable)
            {
                std::cout << var.m_name << " = " << var.m_value;
                if (var.m_isConstant) std::cout << " (constant)";
                std::cout << '\n';
            }
        }
        // Merged individiual calculator Functions into a new Type called Calculator
        class Calculator
        {
        public:
            Calculator()
                : tokenStream(), outputStream(&std::cout),
                inputStream(&std::cin), inputFile(""), fileInputStream(),
                interactiveHelpSystem(std::bind(&Calculator::calculate, this)) 
            {
                tokenStream.setInputStream(*inputStream);
                tokenStream.setOutputStream(*outputStream);
            
            }
            // Calculator class constructor using move semantics
            Calculator(TokenStream&& tokenStream, std::ostream* output, std::istream* input)
                : tokenStream(std::move(tokenStream)), outputStream(output), inputStream(input),
                interactiveHelpSystem(std::bind(&Calculator::calculate, this)) 
            {
                tokenStream.setInputStream(*inputStream);
                tokenStream.setOutputStream(*outputStream);
            }

            Calculator(const std::string& inputFilename, const std::string& outputFilename)
                : fileInputStream(inputFilename), outFileStream(outputFilename),
                tokenStream(fileInputStream, outFileStream), outputStream(&outFileStream),
                inputStream(&fileInputStream),
                interactiveHelpSystem(std::bind(&Calculator::calculate, this)) 
            {
                if (!fileInputStream)
                {
                    throw std::runtime_error("Failed to open input file: " + inputFilename);
                }
                if (!outFileStream)
                {
                    throw std::runtime_error("Failed to open output file: " + outputFilename);
                }

                tokenStream.setInputStream(*inputStream);
                tokenStream.setOutputStream(*outputStream);
            
            }
            // Function To Calculate:
            void calculate();

            // Function to write console results to an output File
            void writeResultsToFile(const std::string& filename)
            {
                std::ofstream outFile(filename);

                if (!outFile)
                {
                    throw std::runtime_error("Unable to open file for writing results.");
                }
                outFile << "These are the results of your calculations: \n";
                // Process the results:
                int resultCounter = 1;
                for (const auto& r : m_results)
                {
                    outFile << resultCounter << ProgramKeys::colonText << ProgramKeys::result << r << std::endl;
                    ++resultCounter;
                }
            }
            
            // Function to process an input file and print the results to an output file
            void processFile(const std::string& inputFilename, const std::string& outputFilename);
        
            // Cleanup function
            void cleanUp();

            // Function to reset the results of the vector
            void resetResults()
            {
                m_results.clear();
            }

        private:
            // Calculation Implementations:
            bool factorialOverflow(int n);
            int factorial(int n);
            double factorialParser();
            double primary();
            double expression();

            // Roman Numerals Implementations:
            RomanNum statementRoman();
            
            // Declarations and Statements:
            double declaration(char kind);
            double statement();

            // Mandatory items:
            TokenStream tokenStream;
            SymbolTable symbols;
            std::ostream* outputStream;
            std::istream* inputStream;
            std::ifstream fileInputStream;
            std::ofstream outFileStream;
            std::string inputFile;
            std::vector<double> m_results;

            HelpMenu interactiveHelpSystem;
        };
        // Function to determine overflow in our factorial cases:
        bool Calculator::factorialOverflow(int n)
        {
            return 0 > std::numeric_limits<int>::max() - n;
        }
        // Function to Compute Factorial of n!
        int Calculator::factorial(int n)
        {
            if (n < 0)
            {
                std::cerr << "factorial: Factorial is only defined for non-negative numbers!";
            }
            int res = 1;

            while (n > 1)
            {
                res *= n--;

                if (factorialOverflow(res)) std::cerr << "factorial: Factorial Overflow detected!";
            }
            return res;
        }
        // Function To deal with our Factorial Cases:
        double Calculator::factorialParser()
        {
            double left = primary();
            Token t = tokenStream.get();
            while (true)
            {
                if (t.m_kind == '!')
                {
                    if (left != static_cast<int>(left) || left < 0)
                    {
                        std::cerr << "Factorial is only defined for non-negative integers!";
                    }
                    left = factorial(static_cast<int>(left));
                    t = tokenStream.get();
                }
                else if (t.m_kind == '^')
                {
                    double factorialExponent = primary();
                    left = std::pow(left, factorialExponent);
                    t = tokenStream.get();
                }
                else
                {
                    tokenStream.putback(t);
                    return left;
                }
            }
        }

        // Function To handle primary cases:
        double Calculator::primary()
        {
            Token t = tokenStream.get();
            double result = 0.0;
            switch (t.m_kind)
            {
            case '(':
            {
                result = expression();
                t = tokenStream.get();
                if (t.m_kind != ')') std::cerr << "')' expected!";

                return result;
            }
            case '{':
            {
                result = expression();
                t = tokenStream.get();
                if (t.m_kind != '}') std::cerr << "'}' expected!";

                return result;
            }
            case '^':
            {
                double base = primary();
                double exponent = primary();
                return std::pow(base, exponent);
            }
            case '!':
                return factorialParser();
            case ProgramKeys::number:
                return t.m_value;
            case ProgramKeys::name:
            {
                std::string varName = t.m_name;

                return symbols.get(varName);
            }
            case ProgramKeys::romanNumerals:
                return t.m_roman.asInt();
            case ProgramKeys::sqrtt:
            {
                t = tokenStream.get();
                if (t.m_kind != '(')
                {
                    std::cerr << "'(' expected after 'sqrt' \n";
                }
                double result = expression();
                t = tokenStream.get();

                if (t.m_kind != ')')
                {
                    std::cerr << "')' expected!";
                }
                if (result < 0)
                {
                    std::cerr << "sqrt: Cannot process a negative number!";
                }
                return std::sqrt(result);
            }
            case ProgramKeys::poww:
            {
                t = tokenStream.get();

                if (t.m_kind != '(') std::cerr << "\'(\' expected after pow keyword";

                double base = expression();

                t = tokenStream.get();
                if (t.m_kind != ',') std::cerr << "\',\' expected after the base";
                int exp = static_cast<int>(expression());
                t = tokenStream.get();
                if (t.m_kind != ')') std::cerr << "\')\' expected after exp";

                return std::pow(base, exp);
            }
            case '-':
                result = -primary();
                return result;
            case '+':
                result = primary();
                return result;
            case '~':
                result = static_cast<int>(primary());
                return ~static_cast<int>(result);
            case ProgramKeys::print:
                return 0.0;
            default:
                tokenStream.putback(t);
                std::cerr << "primary expected!";
                return 0.0;
            }
        }
        // Function to handle the expressions:
        double Calculator::expression()
        {
            double left = factorialParser();

            Token t = tokenStream.get();

            while (true)
            {
                switch (t.m_kind)
                {
                case '+':
                    left += factorialParser();
                    t = tokenStream.get();
                    break;
                case '-':
                    left -= factorialParser();
                    t = tokenStream.get();
                    break;
                case '*':
                    left *= factorialParser();
                    t = tokenStream.get();
                    break;
                case '/':
                {
                    double division{ factorialParser() };
                    if (division == 0) std::cerr << "Cannot Divide by zero!";
                    left /= division;
                    t = tokenStream.get();
                    break;
                }
                case '%':
                {
                    double modulo{ factorialParser() };
                    if (modulo == 0.0) std::cerr << "Remainder: Cannot Divide by zero!";
                    left = std::fmod(left, modulo);
                    t = tokenStream.get();
                    break;
                }
                case '&':
                    left = static_cast<int>(left) & static_cast<int>(factorialParser());
                    t = tokenStream.get();
                    break;
                case '|':
                    left = static_cast<int>(left) | static_cast<int>(factorialParser());
                    t = tokenStream.get();
                    break;
                case '~':
                    left = static_cast<int>(left) ^ static_cast<int>(factorialParser());
                    t = tokenStream.get();
                    break;
                case '<':
                {
                    int shiftAmount = static_cast<int>(factorialParser());
                    if (shiftAmount < 0 || shiftAmount >= (sizeof(int) * 8))
                    {
                        std::cerr << "shift amount out of range";
                    }
                    left = static_cast<int>(left) << shiftAmount;
                    t = tokenStream.get();
                    break;
                }
                case '>':
                {
                    int shiftAmount = static_cast<int>(factorialParser());
                    if (shiftAmount < 0 || shiftAmount >= (sizeof(int) * 8))
                    {
                        std::cerr << "shift amount out of range";
                    }
                    left = static_cast<int>(left) >> shiftAmount;
                    t = tokenStream.get();
                    break;
                }
                default:
                    tokenStream.putback(t);
                    return left;
                }
            }
        }
        // Function that handles declarations and expressions:
        double Calculator::declaration(char kind)
        {
            Token t = tokenStream.get();

            if (t.m_kind != ProgramKeys::name) std::cerr << "name expected in declaration";
            std::string varName = t.m_name;
            if (symbols.isDeclared(varName)) std::cerr << varName, " declared twice!";
            // Check part by part of declaration grammar rule behind "let" or "const"
            Token t2 = tokenStream.get();

            if (t2.m_kind != '=') std::cerr << "= missing in declaration of ", varName;
            double value = expression();
            symbols.declare(varName, value, t.m_kind == ProgramKeys::stable);
            return value;
        }
        // Function that handles declarations and expressions:
        double Calculator::statement()
        {
            Token t = tokenStream.get();
            if (t.m_kind == ProgramKeys::let)
            {   // Handle Variable Declaration
                return declaration(ProgramKeys::let);
            }
            else if (t.m_kind == ProgramKeys::stable)
            {
                return declaration(ProgramKeys::stable);
            }
            else if (t.m_kind == ProgramKeys::romanNumerals)
            {
                tokenStream.putback(t);
                RomanNum result = statementRoman();

                std::cout << result << std::endl;
                return result.asInt();
            }
            else
            {
                tokenStream.putback(t);
                return expression();
            }
        }
        // Function to handle our Roman Numeral Cases:
        RomanNum Calculator::statementRoman()
        {
            Token t = tokenStream.get();

            if (t.m_kind != ProgramKeys::romanNumerals)
            {
                throw std::runtime_error("Roman Numeral Expected!");
            }
            RomanNum left = t.m_roman;

            t = tokenStream.get();

            while (true)
            {
                switch (t.m_kind)
                {
                case '+':
                    t = tokenStream.get();
                    if (t.m_kind != ProgramKeys::romanNumerals) throw std::runtime_error("Roman Numeral Expected!");

                    left = left + t.m_roman;
                    t = tokenStream.get();
                    break;
                case '-':
                    t = tokenStream.get();

                    if (t.m_kind != ProgramKeys::romanNumerals) throw std::runtime_error("Roman Numeral Expected!");
                    left = left - t.m_roman;
                    t = tokenStream.get();
                    break;
                case '*':
                    t = tokenStream.get();
                    if (t.m_kind != ProgramKeys::romanNumerals) throw std::runtime_error("Roman Numeral Expected!");

                    left = left * t.m_roman;
                    t = tokenStream.get();
                    break;
                case '/':
                    t = tokenStream.get();

                    if (t.m_kind != ProgramKeys::romanNumerals) throw std::runtime_error("Roman Numeral Expected!");

                    if (t.m_roman == 0) throw std::runtime_error("Cannot divide by zero!");
                    left = left / t.m_roman;
                    t = tokenStream.get();
                    break;
                default:
                    tokenStream.putback(t);
                    return left;
                }
            }
        }
        // Function for Console Calculations:
        void Calculator::calculate()
        {

            bool newLine = true;

            while (true)
            {
                try
                {
                    if (newLine)
                    {
                        std::cout << ProgramKeys::prompt;
                        newLine = false;
                    }

                    Token t = tokenStream.get();

                    if (t.m_kind == ProgramKeys::quit)
                    {
                        std::cout << "\nThank you for using MCalculator 1.3!\n" << std::endl;
                        return;
                    }
                    if (t.m_kind == ProgramKeys::print)
                    {
                        newLine = true;
                        continue;
                    }

                    if (t.m_kind == ProgramKeys::help)
                    {
                        std::system("CLS");
                        HelpMenu consoleInteractive(std::bind(&Calculator::calculate, this));
                        consoleInteractive.printHelpMenu();
                        tokenStream.ignore(ProgramKeys::print);
                        newLine = true;
                        continue;
                    }
                    else if (t.m_kind == ProgramKeys::romanNumerals)
                    {
                        tokenStream.putback(t);
                        RomanNum resultRomans = statementRoman();
                        std::cout << ProgramKeys::result << resultRomans << ", Converted to Integer: " << resultRomans.asInt() << '\n';
                        m_results.push_back(resultRomans.asInt());

                    }
                    else
                    {
                        tokenStream.putback(t);
                        double res = statement();
                        std::cout << ProgramKeys::result << std::setprecision(12) << res << std::endl;
                        m_results.push_back(res);

                    }
                    // Process the remaining expressions in the same line
                    while (true)
                    {
                        t = tokenStream.get();

                        if (t.m_kind == ProgramKeys::print)
                        {
                            newLine = true;
                            break;
                        }
                        else if (t.m_kind == ProgramKeys::quit)
                        {
                            std::cout << "Thank you for using MCalculator 1.3!\n" << std::endl;
                            return;
                        }
                        else if (t.m_kind == ProgramKeys::help)
                        {
                            
                            tokenStream.ignore(ProgramKeys::print);
                            newLine = true;
                            break;
                        }
                        else if (t.m_kind == ProgramKeys::romanNumerals)
                        {
                            tokenStream.putback(t);
                            RomanNum resultedRomans = statementRoman();
                            std::cout << ProgramKeys::result << resultedRomans << std::endl;
                            m_results.push_back(resultedRomans.asInt());
                        }
                        else
                        {
                            tokenStream.putback(t);
                            double res = statement();
                            std::cout << ProgramKeys::result << std::setprecision(12) << res << std::endl;
                            m_results.push_back(res);

                        }
                    }
                }
                catch (const std::exception& ex)
                {
                    std::cerr << ex.what() << std::endl;
                    tokenStream.ignore(ProgramKeys::print);
                    cleanUp();
                    newLine = true;
                }
            }
        }
        
        // Function To Process The Files: Input evaluate and then output to another file:
        void Calculator::processFile(const std::string& inputFilename, const std::string& outputFilename)
        {
            std::ifstream inFile(inputFilename);
            if (!inFile.is_open())
            {
                std::cerr << "Error opening file: " << inputFilename << std::endl;
                return;
            }
            std::ofstream outFile(outputFilename);

            if (!outFile.is_open())
            {
                std::cerr << "Error opening output file. " << std::endl;
                return;
            }
            TokenStream& tStream = tokenStream;
            tStream.setInputStream(inFile);
            tStream.setOutputStream(outFile);
            bool newLine = true;

            while (true)
            {
                try
                {
                    Token t = tStream.get();

                    if (inFile.fail())
                    {
                        outFile << "Error reading from file: " << inputFilename << std::endl;
                        return;
                    }

                    if (t.m_kind == ProgramKeys::quit)
                    {
                        break;
                    }
                    if (t.m_kind == ProgramKeys::print)
                    {
                        newLine = true;
                        continue;
                    }
                    else if (t.m_kind == ProgramKeys::romanNumerals)
                    {
                        tStream.putback(t);
                        RomanNum resultsRomans = statementRoman();
                        outFile << ProgramKeys::result << resultsRomans;
                    }
                    else
                    {
                        tStream.putback(t);
                        outFile << ProgramKeys::result << std::setprecision(12) << statement() << std::endl;
                    }

                    // Process the remaining expressions in the same line
                    while (true)
                    {
                        t = tStream.get();

                        if (inFile.fail())
                        {
                            outFile << "Error reading token from file: " << inputFilename << std::endl;
                            return;
                        }
                        if (t.m_kind == ProgramKeys::quit)
                        {
                            return;
                        }
                        if (t.m_kind == ProgramKeys::print)
                        {
                            newLine = true;
                            break;
                        }
                        else if (t.m_kind == ProgramKeys::romanNumerals)
                        {
                            tStream.putback(t);
                            RomanNum resultedRomans = statementRoman();
                            outFile << ProgramKeys::result << resultedRomans << std::endl;
                        }
                        else
                        {
                            tStream.putback(t);
                            outFile << ProgramKeys::result << std::setprecision(12) << std::endl;
                        }
                    }
                }
                catch (const std::exception& ex)
                {
                    outFile << "Error Evaluating expression: " << ex.what() << std::endl;
                    tStream.ignore(ProgramKeys::print);
                    cleanUp();
                    newLine = true;
                }
            }
        }
        // Function to Cleanup after errors:
        void Calculator::cleanUp()
        {
            tokenStream.ignore(ProgramKeys::print);
        }

    }

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
	{

	}
    
}