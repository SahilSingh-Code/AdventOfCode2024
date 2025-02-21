// ----------------------------------------------------
// Author: Sahil Singh
// Date: Febraury 21, 2025
// 
// This file contains some basic print functions that
// are used commonly across a lot of different problems
//-----------------------------------------------------

// Dependencies
#include <vector>
#include <string>

namespace PrintUtilities
{
	// Function to print an empty line, often used for spacing/aesthetics
	void emptyLine();

	// Function that will print a vector as a column
	template <typename T>
	void printVectorAsColumn(std::vector<T> v);

	// Function that will print a vector as a row
	template <typename T>
	void printVectorAsRow(std::vector<T> v);

	// Function to print a message following by a single number
	template <typename T>
	void printMessageAndNumber(const std::string & message, const T & value);
}