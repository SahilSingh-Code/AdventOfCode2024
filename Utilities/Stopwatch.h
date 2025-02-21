// ----------------------------------------------------
// Author: Sahil Singh
// Date: Febraury 21, 2025
// 
// This file contains a basic stopwatch implementation
// to time code using std::chrono
// Only supports ms/us/ns timing granularity at the
// moment. Can add more as needed going forward.
//-----------------------------------------------------

// Dependencies
#include <chrono>
#include <string>

// An enum used to specify which granularity/units to
// print stopwatch timings in
enum TimeGranularity
{
	milliseconds,
	microseconds,
	nanoseconds
};

// The stopwatch object class
// Provides the basic stopwatch functionality of
// start/stop, and printing out the time
class StopWatch
{
public:
	// Creating an instance of this class requires no
	// extra instantiation
	StopWatch() = default;

	// Destruction of the stopwatch also requires no
	// extra work
	~StopWatch() = default;

	// Start and stop the stopwatch
	void start();
	void stop();

	// Print out the time with the given message and
	// time granularity
	void printTime(const std::string& message,
		TimeGranularity granularity = TimeGranularity::microseconds) const;

private:
	// The start and stop times contained in this stopwatch
	// currently. This get initialized to epoch time.
	std::chrono::high_resolution_clock::time_point start_{};
	std::chrono::high_resolution_clock::time_point stop_{};

	// A flag for tracking whether the stopwatch is running
	// or not
	bool clockIsRunning_ = false;
};