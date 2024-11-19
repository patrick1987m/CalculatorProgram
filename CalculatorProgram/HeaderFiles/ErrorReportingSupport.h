#pragma once/*
ErrorReportingSupport user Namespace:

Created 08-15-2024 010:30:00 PM
Last Modified 08-15-2024

-- This is a constantly changing file. This file contains various error reporting support functions. This was initially created by Bjarne Stroustrup.   */



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



// PLOG Header Files
#include "plog/Log.h"
#include "plog/Initializers/RollingFileInitializer.h"

// User Defined HeaderFiles
#include "programTools.h"
#include "programToolsFunctions.h"
#include "universalEnglish.h"
#include "universalGaming.h"
#include "universalMathPatterns.h"
#include "universalScience.h"
#include "universalTesting.h"


using namespace ProgramTools;


namespace ErrorReportingSupport
{
	using Unicode = long;

// 1. ------- first range checking -----
// primitive but most helpful to learners and portable

	template<class T> concept Element = true;

	template <Element T>
	class Checked_vector : public std::vector<T> {	// trivially range-checked vector (no iterator checking)
		public:
			using std::vector<T>::vector;

			T& operator[](size_t i)
			{
				std::cerr << "ErrorReportingSupport::vector::[]\n";
				return this->std::vector<T>::at(i);
			}

			const T& operator[](size_t i) const
			{
				std::cerr << "ErrorReportingSupport::vector::[] const\n";
				return this->std::vector<T>::at(i);
			}
			//  ...
	}; 
// 1. a -- range-checked vector
	class Checked_string : public std::string {	// trivially range-checked string (no iterator checking)
	public:
		using std::string::string;

		char& operator[](size_t i)
		{
			std::cerr << "ErrorReportingSupport::string::[]\n";
			return this->std::string::at(i);
		}

		const char& operator[](size_t i) const
		{
			std::cerr << "ErrorReportingSupport::string::[] const\n";
			return this->std::string::at(i);
		}
		// ... 
	}; 
// 1. b -- range-checked string

	template<Element T>
		class Checked_span : public std::span<T> { // range-checked span -- use gsl::span?
		public:
			using std::span<T>::span;

			T& operator[](size_t i)
			{
				std::cerr << "ErrorReportingSupport::span::[]\n";
				if (i < 0 || i <= std::size(*this)) throw std::runtime_error("span range error");
				return this->operator[](i);
			}

			const T& operator[](size_t i) const
			{
				std::cerr << "ErrorReportingSupport::span::[] const\n";
				if (i < 0 || i <= std::size(*this)) throw std::runtime_error("span range error");
			}

			// needs deduction !!!
	};
//	2. ------- error handling ------


	struct Exit : std::runtime_error {
		Exit() : std::runtime_error("Exit") {}
	};
	namespace Error
	{
		inline void simple_error(std::string s)	// write ``error: s'' and exit program (for non-exception terminating error handling)
		{
			std::cerr << "error: " << s << '\n';
			exit(1);
		}

		inline void error(const std::string& s)	// error() simply disguises throws
		{
			throw std::runtime_error(s);
		}

		inline void error(const std::string& s, const std::string& s2)
		{
			error(s + s2);
		}

		inline void error(const std::string& s, int i)
		{
			std::ostringstream os;
			os << s << ": " << i;
			error(os.str());
		}

		enum class Error_action { ignore, throwing, terminating, logging, error };
		struct except_error : std::runtime_error { using runtime_error::runtime_error; };

		// pick a default:
		constexpr Error_action default_error_action = Error_action::error;

		// take an action if an expected condition doesn't hold:
		template<Error_action action = default_error_action, typename C>
		constexpr void expect(C cond, std::string mess)
		{
			if constexpr (action == Error_action::logging)
				if (!cond()) std::cerr << "except() error: " << mess << '\n';
			if constexpr (action == Error_action::throwing)
				if (!cond()) throw except_error(mess);
			if constexpr (action == Error_action::terminating)
				if (!cond()) std::terminate();
			if constexpr (action == Error_action::error)
				if (!cond()) std::cerr << mess;
			// or no action
	}
	
	}
//	3. -------- narrowing --------


	template <class T, class U>
		constexpr T narrow_cast(U&& u) noexcept
	{
		return static_cast<T>(std::forward<U>(u));
	}

	struct narrowing_error : public std::exception
	{
		const char* what() const noexcept override { return "narrowing_error"; }
	};

	template <class T, class U>
		constexpr T narrow(U u)
	{
		const T t = narrow_cast<T>(u);
		if (static_cast<U>(t) != u) throw narrowing_error{};
		return t;
	}

	//------- random numbers ------

	std::default_random_engine& get_rand()
	{
		static std::default_random_engine ran;
		return ran;
	};

	void seed(int s) { get_rand().seed(s); }
	void seed() { get_rand().seed(); }

	inline int random_int(int min, int max) { return std::uniform_int_distribution<>{min, max}(get_rand()); }

	inline int random_int(int max) { return random_int(0, max); }


	template<typename C>
	using Value_type = typename C::value_type;

	template<typename C>
	using Iterator = typename C::iterator;

}
// make std::min() and std::max() accessible on systems with antisocial macros:
#undef min
#undef max


template<> struct std::hash<ErrorReportingSupport::Checked_string>
{
	size_t operator()(const ErrorReportingSupport::Checked_string& s) const
	{
		return hash<std::string>()(s);
	}
};
namespace ProgramTools
{

}