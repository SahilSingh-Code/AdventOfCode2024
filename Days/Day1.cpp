#include "Day1.h"
// ----------------------------------------------------
// Author: Sahil Singh
// Date: Febraury 21, 2025
//
// Solution implementations for day 1 of Advent of Code
// 2024. There are multiple solutions implemented here
// for comparison.
// 
// By difficulty of comprehension, we have:
// 
// - std::sort solution: easy to understand
// - naive solution: easy~medium to understand
// - quick sort solution: hard to understand
// 
// std::sort is the best choice, as it's the fastest
// and easiest to implement, the others are implemented
// for demonstration purposes.
// ----------------------------------------------------


// Dependencies
#include "Day1.h"
#include "Utilities/PrintUtilities.h"
#include "Utilities/Stopwatch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <unordered_map>

namespace Day1 
{
    // Function to run the different solutions
    // This is where the timing code goes, as well as the calls
    // to all of the different analysis methods
    // Start reading here for the solutions
    void Day1::runSolutions()
    {
        //---------------
        // Example
        // --------------
        
        // Let's read off the example input first and print it out
        // For validation
        std::string inputsPath = INPUTS_DIR;
        std::string inputFile = inputsPath + "/Day1/Example.txt";
        Lists twoLists = readTwoLists(inputFile);
        std::cout << std::endl << "Example inputs are: " << std::endl;
        PrintUtilities::printVectorAsRow(twoLists.first);
        PrintUtilities::printVectorAsRow(twoLists.second);
        std::cout << std::endl; // empty line for output formatting

        // Now, let's solve the distance problem using std::sort
        // std::sort modifies the original vector, but this function
        // copies the parameter into it's scope, so we're safe to call it
        int distanceUsingStdSort = findListDistanceUsingStdSort(twoLists);
        if (distanceUsingStdSort == -1) return; // error check
        PrintUtilities::printMessageAndNumber("Distance using std::sort", distanceUsingStdSort);

        // Let's solve the problem again using a naive iterative sort
        int distanceUsingNaiveSort = findListDistanceUsingNaiveSort(twoLists);
        if (distanceUsingNaiveSort == -1) return; // error check
        PrintUtilities::printMessageAndNumber("Distance using a naive sort", distanceUsingNaiveSort);

        // Let's solve the problem a third time using quick sort
        int distanceUsingQuickSort = findListDistanceUsingQuickSort(twoLists);
        if (distanceUsingQuickSort == -1) return; // error check
        PrintUtilities::printMessageAndNumber("Distance using quick sort", distanceUsingQuickSort);

        // Print an empty line as a separator between example and real results
        PrintUtilities::emptyLine();

        //---------------
        // Real Input
        // --------------

        // -- Part 1 --
        
        // Let's read off the actual input we want to solve,
        // And calculate the results, along with timing information
        // The real inputs are huge, so let's not print them
        inputFile = inputsPath + "/Day1/Input.txt";
        twoLists = readTwoLists(inputFile);

        // Create a stopwatch
        StopWatch stopWatch;

        // Find the distance using std:;sort
        stopWatch.start();
        distanceUsingStdSort = findListDistanceUsingStdSort(twoLists);
        stopWatch.stop();
        if (distanceUsingStdSort == -1) return; // error check
        PrintUtilities::printMessageAndNumber("Distance using std::sort", distanceUsingStdSort);
        stopWatch.printTime("Time elapsed using std::sort");

        // Let's solve the problem again using a naive iterative sort
        stopWatch.start();
        distanceUsingNaiveSort = findListDistanceUsingNaiveSort(twoLists);
        stopWatch.stop();
        if (distanceUsingNaiveSort == -1) return; // error check
        PrintUtilities::printMessageAndNumber("Distance using a naive sort", distanceUsingNaiveSort);
        stopWatch.printTime("Time elapsed using a naive sort");

        // Let's solve the problem a third time using quick sort
        stopWatch.start();
        distanceUsingQuickSort = findListDistanceUsingQuickSort(twoLists);
        stopWatch.stop();
        if (distanceUsingQuickSort == -1) return; // error check
        PrintUtilities::printMessageAndNumber("Distance using quick sort", distanceUsingQuickSort);
        stopWatch.printTime("Time elapsed using quick sort");

        // CONCLUSION
        // For the distance calculation, using std::sort is the best approach as it is a well documented
        // and optimized function. Quick sort works at comparable speeds, but is harder to implement and
        // understand.

        // -- Part 2 --

        // Let's solve the problem using the naive expensive approach
        stopWatch.start();
        int64_t similarityScore = findListSimilarityUsingNaiveTraverse(twoLists);
        stopWatch.stop();
        if (similarityScore == -1) return; // error check
        PrintUtilities::printMessageAndNumber("Simialrity Score using Naive Traverse", similarityScore);
        stopWatch.printTime("Time elapsed using naive traverse");

        // Let's solve the problem by using a traverse and remove method
        stopWatch.start();
        similarityScore = findListSimilarityUsingTraverseAndRemove(twoLists);
        stopWatch.stop();
        if (similarityScore == -1) return; // error check
        PrintUtilities::printMessageAndNumber("Simialrity Score using Traverse and Remove", similarityScore);
        stopWatch.printTime("Time elapsed using traverse and remove");

        // Let's solve the problem by using the single traverse method
        stopWatch.start();
        similarityScore = findListSimilarityUsingSingleTraverse(twoLists);
        stopWatch.stop();
        if (similarityScore == -1) return; // error check
        PrintUtilities::printMessageAndNumber("Simialrity Score using Single Traverse", similarityScore);
        stopWatch.printTime("Time elapsed using Single Traverse");

        // CONCLUSION
        // For the similarity score, the single traversal has the best complexity order of n vs n^2 for the
        // single traversal, but the overhead of creating the hash map involved does not make it faster for
        // the size of the lists provided in the advent of code challenges
    }

    // Calculate the result using std's built in
    // std::sort function
    int findListDistanceUsingStdSort(Lists lists)
    {
        // Check inputs
        auto errorCode = checkVectors(lists.first,lists.second);
        if( errorCode == InputValidity::vectorsAreNotSameLength )
        {
            return -1;
        }

        // Let's first sort the two lists
        std::vector<int>& v1 = lists.first;
        std::vector<int>& v2 = lists.second;
        std::sort(v1.begin(),v1.end());
        std::sort(v2.begin(),v2.end());

        return findDistanceOnSortedLists(v1,v2);
    }

    // Calculate the result using a naive sort
    int findListDistanceUsingNaiveSort(Lists lists)
    {
        // Check inputs
        auto errorCode = checkVectors(lists.first, lists.second);
        if (errorCode == InputValidity::vectorsAreNotSameLength)
        {
            return -1;
        }

        // Read off the two lists
        std::vector<int>& v1 = lists.first;
        std::vector<int>& v2 = lists.second;

        // A lambda for sorting vectors using the naive sort approach
        // Create a copy here as we will be modifying the original vector
        auto naiveSort = [](std::vector<int> v) 
            {
                
                // The container for the sorted vector
                std::vector<int> sortedV = {};

                // While there are still entries in v, keep looping
                while(v.size() > 0)
                {

                    // Let's find the smallest value in the current vector
                    // Start by setting the largest possible value
                    int min = std::numeric_limits<int>::max();

                    // Loop over the vector, and find the smallest value index
                    int minIndex = -1;
                    for( int i = 0; i < v.size(); i++ )
                    {
                        if( v[i] <= min)
                        {
                            minIndex = i;
                            min = v[i];
                        }
                    }

                    // Now we have the index of the smallest value. Push this
                    // value into our sorted vector, and remove it from our
                    // original
                    sortedV.push_back(min);
                    std::swap(v[minIndex], v.back());
                    v.pop_back();
                    
                }
                
                return sortedV;
            };
        std::vector<int> sortedV1 = naiveSort(v1);
        std::vector<int> sortedV2 = naiveSort(v2);
        return findDistanceOnSortedLists(sortedV1, sortedV2);
    }

    // Find the distance of the two lists using quick sort
    int findListDistanceUsingQuickSort(Lists lists)
    {
        // Check inputs
        auto errorCode = checkVectors(lists.first, lists.second);
        if (errorCode == InputValidity::vectorsAreNotSameLength)
        {
            return -1;
        }

        // Read off the two lists
        std::vector<int>& v1 = lists.first;
        std::vector<int>& v2 = lists.second;

        // Run quicksort
        quickSort(v1, 0, v1.size() - 1);
        quickSort(v2, 0, v2.size() - 1);
        return findDistanceOnSortedLists(v1,v2);
    }

    void quickSort(std::vector<int>& v, int start, int end)
    {
        // Do something only if the start is less than the end
        // If it's not and they're the same, this vector is empty
        // and we've reached the end of the recursion
        if (start < end)
        {
            // Pick the element on the far right as the pivot element
            int pivot = v[end];
            int i = start - 1;

            // Partition: move elements less than or equal to pivot to the left
            for (int j = start; j < end; j++) {
                if (v[j] <= pivot) {
                    i++;
                    std::swap(v[i], v[j]);
                }
            }

            // Place the pivot in its correct sorted position
            std::swap(v[i + 1], v[end]);
            int pivotIndex = i + 1;

            // Recursively sort the two partitions
            quickSort(v, start, pivotIndex - 1);
            quickSort(v, pivotIndex + 1, end);
        }
    }

    // Given sorted lists, find the distance
    int findDistanceOnSortedLists(const std::vector<int>& v1, const std::vector<int>& v2)
    {
        // Now that we've sorted the lists, and we're sure the lists
        // are the same length, let's loop over the values and calculate
        // the distance
        int distance = 0;
        for (int i = 0; i < v1.size(); i++)
        {
            distance += fabs(v1[i] - v2[i]);
        }

        return distance;
    }

    int64_t findListSimilarityUsingNaiveTraverse(Lists lists)
    {
        // Read off the two lists
        std::vector<int>& v1 = lists.first;
        std::vector<int>& v2 = lists.second;

        // Loop over all the entries in list 1, find all matching entries in list 2, and increment the cost
        int64_t totalCost = 0;
        for (const auto& entry : v1)
        {
            int nCount = 0;
            for (const auto& entry2 : v2)
            {
                if (entry == entry2)
                {
                    nCount++;
                }
            }
            totalCost += static_cast<int64_t>(entry) * static_cast<int64_t>(nCount);
        }

        return totalCost;
    }

    // For a given list, find the similarity score
    int64_t findListSimilarityUsingTraverseAndRemove(Lists lists)
    {
        // Read off the two lists
        std::vector<int>& v1 = lists.first;
        std::vector<int>& v2 = lists.second;

        // We will be keeping a map to track whether a certain value in list 1 has already been checked,
        // and how many entries there were in the second list
        // We want to remember, for a given number, how many we've found so far, and how many were in the the other list
        // Key: number in the left list
        // value: a pair, where first value is the count in the left list, and second is the count in the right list
        std::unordered_map<int64_t, std::pair<int64_t, int64_t>> trackMap;

        while (v1.size() > 0)
        {
            // Let's look at the first number, and remember what it is
            int64_t n = static_cast<int64_t>(v1[0]);

            // Now, let's remove it from the vector so we don't look at it again
            std::swap(v1[0], v1.back());
            v1.pop_back();

            // Is this entry already in the map? If so, all we need to do is increment the count
            if (trackMap.find(n) != trackMap.end())
            {
                trackMap[n].first++;
            }
            else
            {
                // Find how many of this entry are in the second list, and remove them from the second list
                int64_t nCount = 0;
                for (int i = 0; i < v2.size(); ) { // Do not increment the variable in the for loop header
                    if (v2[i] == n) {
                        nCount++;
                        std::swap(v2[i], v2.back());
                        v2.pop_back();
                        // Don't increment i here either, if we swapped, we stay where we are and look again
                    }
                    else {
                        // Now we are safe to move on from this entry and look at the next one
                        ++i;
                    }
                }

                // Now, we have the count of how many n's were in the second list, and those n's have been removed so we
                // don't look at them again. We can now create the entry in the map
                std::pair<int64_t, int64_t> result(1,nCount);
                trackMap[n] = result;
            }
        }

        // Now we have all of the relevant counts, let's compute the total cost
        int64_t totalCost = 0;
        for (const auto& entry : trackMap)
        {
            totalCost += entry.first * entry.second.first * entry.second.second;
        }

        return totalCost;
    }

    // Find the similarity score by only traversing the list once
    int64_t findListSimilarityUsingSingleTraverse(Lists lists)
    {
        // Read off the two lists
        std::vector<int>& v1 = lists.first;
        std::vector<int>& v2 = lists.second;

        // Let's generate a hash map of the counts of variables in the second list
        std::unordered_map<int, int> list2Counts;
        for (const auto& entry : v2)
        {
            if (list2Counts.find(entry) != list2Counts.end())
            {
                list2Counts[entry]++;
            }
            else
            {
                list2Counts[entry] = 1;
            }
        }

        // Now we loop over the first list, and compute the total cost
        int64_t totalCost = 0;
        for (const auto& entry : v1)
        {
            if (list2Counts.find(entry) != list2Counts.end())
            {
                totalCost += static_cast<int64_t>(entry) * static_cast<int64_t>(list2Counts[entry]);
            }
        }

        return totalCost;
    }



    // ---- Utility functions ----

    // Function to read and decipher the input formatted for day 1
    // Note, this is chat GPT'd. I don't care too much to look up
    // the syntax for file reading. This is such a common task that
    // it amounts to looking up how to do it. No point in remembering
    // or spending time in figuring it out. I am focused on the analysis,
    // not the reading of inputs
    Lists Day1::readTwoLists(const std::string& fileName)
    {
        std::ifstream input(fileName);
        if (!input.is_open()) {
            throw std::runtime_error("Could not open file: " + fileName);
        }

        std::vector<int> column1;
        std::vector<int> column2;
        int value1, value2;

        // Read pairs of integers from the file.
        while (input >> value1 >> value2) {
            column1.push_back(value1);
            column2.push_back(value2);
        }

        return std::make_pair(column1, column2);
    }

    // Function to check vector sizes, and print off an error if they are not
    // the same length
    InputValidity checkVectors(const std::vector<int>& v1, const std::vector<int>& v2)
    {
        if (v1.size() == v2.size())
        {
            return InputValidity::vectorsAreSameLength;
        }

        std::cout << "ERROR: Input vectors are not the same size, please check input." << std::endl;
        return InputValidity::vectorsAreNotSameLength;
    }

} // end of namesapce Day1
