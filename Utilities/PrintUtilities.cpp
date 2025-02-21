// ----------------------------------------------------
// Author: Sahil Singh
// Date: Febraury 21, 2025
// 
// This file contains some basic print functions that
// are used commonly across a lot of different problems
// Since I'm using templates here, I've had to use
// explicit instantiation to be able to define these
// functions in this folder instead of in the header.
// We could get rid of this by moving all definitions
// to the header, but I'm going to keep it like this
// for now
//-----------------------------------------------------

#include "PrintUtilities.h"
#include <iostream>
#include <vector>
#include <string>

namespace PrintUtilities
{
	// Print an empty line
	void emptyLine()
	{
		std::cout << std::endl;
	}


	// Input any vector, and print it out as a column in the
	// terminal
	template <typename T>
	void printVectorAsColumn(std::vector<T> v)
	{
		// Empty line for spacing purposes
		std::cout << std::endl;

		// Loop over each entry and print them on a new line
		for( const auto & entry : v )
		{
			std::cout << entry << std::endl;
		}

		// Empty line for spacing purposes
		emptyLine();

		return;
	}


	// Input any vector, and print it out as a row in the
	// terminal
	template <typename T>
	void printVectorAsRow(std::vector<T> v)
	{
		// Loop over each entry and print them on a new line
		for (int i = 0; i < v.size(); i++)
		{
			// We don't want an extra , at the end of the list, so
			// let's do an index check and end the line appropriately
			if( i < v.size() - 1 )
			{
				std::cout << v[i] << ", ";
			}
			else
			{
				std::cout << v[i] << std::endl;
			}
		}
		return;
	}


	// Often times, we want to print a message like "result is: x"
	// This is a utility to do so
	template <typename T>
	void printMessageAndNumber(const std::string& message, const T& value)
	{
		std::cout << message << ": " << value << std::endl;
	}


	// Explicit instantiations for different types of the template
	// This is needed as for templating, the compiler wants to see
	// the templated code in included file directly
	// I want to keep the implementation and declaration separate,
	// so we have to explicitly instantiate different types we need
	// here. A little annoying, but it's ok.
	template void printVectorAsColumn<int>(std::vector<int>);
	template void printVectorAsColumn<int64_t>(std::vector<int64_t>);
	template void printVectorAsColumn<double>(std::vector<double>);

	template void printVectorAsRow<int>(std::vector<int>);
	template void printVectorAsRow<int64_t>(std::vector<int64_t>);
	template void printVectorAsRow<double>(std::vector<double>);

	template void printMessageAndNumber<int>(const std::string& message, const int& value);
	template void printMessageAndNumber<int64_t>(const std::string& message, const int64_t& value);
	template void printMessageAndNumber<double>(const std::string& message, const double& value);

} // end of namespace PrintUtilities