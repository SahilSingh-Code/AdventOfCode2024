// ----------------------------------------------------
// Author: Sahil Singh
// Date: Febraury 21, 2025
//
// Solutions for Day 1 of Advent of Code 2024
// I'm going to implement multiple methods here to run
// and compare the timings and see which is best
// ----------------------------------------------------

// Dependencies
#include <vector>
#include <string>

namespace Day1
{
	// Defining a custom error type and check for vector length checking
	// Overkill, but we're overengineering today
	enum InputValidity
	{
		vectorsAreNotSameLength,
		vectorsAreSameLength
	};
	InputValidity checkVectors(const std::vector<int> & v1, const std::vector<int> & v2);

	// Define a custom type for lists
	using Lists = std::pair<std::vector<int>, std::vector<int>>;

	// Just run all of the cases
	void runSolutions();

	// A function that, give the filename formatted correctly for Day 1, will
	// return two vectors corresponding to the columns in the input
	Lists readTwoLists(const std::string& fileName);

	// A function that, given sorted lists, will calculate the distances
	int findDistanceOnSortedLists(const std::vector<int> & v1, const std::vector<int> & v2);

	// Calculate the distance of these two lists using std::sort as a precursor
	// Note that this function *copies* the lists into the function scope, as
	// std::sort will rearrange the original vector. Since the goal is to
	// analyze the vector multiple times, we don't want to pre-sort it before
	// other functions
	// The order of std::sort is n Log n
	int findListDistanceUsingStdSort(Lists lists);

	// Calculate the distance between these two lists using a naive sort
	// The sort will just run over each list and then find the smallest entry,
	// and then remove that entry from the list, and repeat the process
	// We will have n*(n-1)*(n-2)... = n! operations for this sort
	// Using a taylor's expansion, this is of order n^n. Slowwww
	int findListDistanceUsingNaiveSort(Lists lists);

	// Calculate the distance between these two lists using quick sort
	int findListDistanceUsingQuickSort(Lists lists);

	// The recursive quicksort algorithm
	// This is it's own function because of recursion
	// This sort creates a random partion, creates two vectors of values that
	// are less than or greater than that partition, and then recursively
	// sorts the subsequent child vectors. In doing this partition, the partition
	// value is placed in it's correct location.
	// The order is n log n
	void quickSort(std::vector<int>& v, int start, int end);
}