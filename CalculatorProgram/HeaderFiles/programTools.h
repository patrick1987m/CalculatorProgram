#pragma once

/*
* This is the main header for all universal headers.
* Included are: english Namespace, science Namespace, etc
* This programTools namespace is large, or will become large as time goes on.
* To access this namespace simply type programTools::(whatever sub-namespace you want)
*/

// This header file contains the standard libraries and includes
// Required for proper compilation and necessary stability features!

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
#include "universalCalculatorTokenStreams.h"
#include "universalFunctionalToolset.h"
#include "universalEnglish.h"
#include "universalGaming.h"
#include "universalMathPatterns.h"
#include "universalScience.h"
#include "universalTesting.h"


using namespace ErrorReportingSupport;
using namespace ProgramTools;

namespace ProgramTools
{
	namespace UniversalCalculatorTokenStreams
	{
		// Implementation found in /HeaderFiles/universalCalculatorTokenStreams.h
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
} // end of namespace  programTools

