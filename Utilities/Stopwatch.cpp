// ----------------------------------------------------
// Author: Sahil Singh
// Date: Febraury 21, 2025
// 
// This file contains the implementation for a basic
// stopwatch class to help with timing any code in this
// project.
//-----------------------------------------------------

// Dependencies
#include "Stopwatch.h"
#include "PrintUtilities.h"
#include <iostream>
#include <chrono>

// Start the timer
void StopWatch::start()
{
	// If we try starting a clock that is already running, print
	// out an error message, but don't stop the code from
	// running. An error with the stopwatch is not reason to
	// stop the code
	if (clockIsRunning_)
	{
		std::cout << std::endl <<
			"WARNING: Tried to start a stopwatch that is already running."
			<< std::endl << std::endl;

		return;
	}

	clockIsRunning_ = true;
	start_ = std::chrono::high_resolution_clock::now();
}

// Stop the timer
void StopWatch::stop()
{
	// If we try stopping the timer before it's running, print
	// out an error message, but don't stop the code from
	// running. An error with the stopwatch is not reason to
	// stop the code
	if( !clockIsRunning_ )
	{
		std::cout << std::endl << 
			"WARNING: Tried to stop a stopwatch that is not running." 
			<< std::endl << std::endl;

		return;
	}

	stop_ = std::chrono::high_resolution_clock::now();
	clockIsRunning_ = false;
}

// Print out the timing
void StopWatch::printTime(const std::string & message, TimeGranularity granularity) const
{
	// If the clock is still running, print out a warning, but don't stop
	// the timer. We should let users print timing as things run without
	// stopping the clock
	if( clockIsRunning_ )
	{
		std::cout <<
			"WARNING: Printing time with the clock still running."
			<< std::endl;
	}

	// Measure the duration
	// This measures by default in seconds, which is way to big a time
	// unit for our cases
	std::chrono::duration<double> timeElapsed = stop_ - start_;

	// Print off the correct units of time based on the user-specificed
	// granularity
	switch( granularity )
	{
		case TimeGranularity::milliseconds:
		{
			std::chrono::milliseconds elapsed_ms =
				std::chrono::duration_cast<std::chrono::milliseconds>(timeElapsed);
			std::cout << message << " runtime: " << elapsed_ms.count() << " ms" << std::endl;
			break;
		}

		case TimeGranularity::microseconds:
		{
			std::chrono::microseconds elapsed_ms =
				std::chrono::duration_cast<std::chrono::microseconds>(timeElapsed);
			std::cout << message << " runtime: " << elapsed_ms.count() << " us" << std::endl;
			break;
		}

		case TimeGranularity::nanoseconds:
		{
			std::chrono::nanoseconds elapsed_ns =
				std::chrono::duration_cast<std::chrono::nanoseconds>(timeElapsed);
			std::cout << message << " runtime: " << elapsed_ns.count() << " ns" << std::endl;
			break;
		}
	}

	// Empty line for spacing
	PrintUtilities::emptyLine();
}