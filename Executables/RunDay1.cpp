// ----------------------------------------------------
// Author: Sahil Singh
// Date: Febraury 21, 2025
//
// 
// Entry point for running Day 1 solution for Advent
// of Code 2024. Contains no actual solution, merely
// the executable entry point.
// ----------------------------------------------------

// Dependencies
#include <Days/Day1.h>

// The main entry point for this executable
// This code will only invoke the function that runs
// everything, it should not have any actual code logic
// in it. The main function is simply the entry point
// and nothing else
int main()
{
	// Run all of the solutions and return
	Day1::runSolutions();

	//  Example inputs are :
	//  3, 4, 2, 1, 3, 3
	//	4, 3, 5, 3, 9, 3
	//
	//	Distance using std::sort : 11
	//	Distance using a naive sort : 11
	//	Distance using quick sort : 11
	//
	//	Distance using std::sort : 2367773
	//	Time elapsed using std::sort runtime : 76 us
	//
	//	Distance using a naive sort : 2367773
	//	Time elapsed using a naive sort runtime : 446 us
	//
	//	Distance using quick sort : 2367773
	//	Time elapsed using quick sort runtime : 63 us
	//
	//	Simialrity Score using Naive Traverse : 21271939
	//	Time elapsed using naive traverse runtime : 58 us
	//
	//	Simialrity Score using Traverse and Remove : 21271939
	//	Time elapsed using traverse and remove runtime : 416 us
	//
	//	Simialrity Score using Single Traverse : 21271939
	//	Time elapsed using Single Traverse runtime : 64 us

	return 0;
}
