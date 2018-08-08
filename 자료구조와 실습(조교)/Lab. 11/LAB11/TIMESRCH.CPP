//--------------------------------------------------------------------
//
//  Laboratory 15, In-lab Exercise 1                    timesrch.cpp
//
//  Timing program for a set of searching routines
//
//--------------------------------------------------------------------

// Computes the length of time that it takes to execute a given
// searching routine. Searches for numSearches keys in an ordered
// array of numKeys integers.

#include <iostream.h>
#include <stdlib.h>     // For exit()
#include "timer.h"
#include "sort.cpp"
#include "search.cpp"

//--------------------------------------------------------------------

const int numSearches    = 1000;   // Number of searches to perform

const int numRepetitions = 10;     // Number of times to repeat each
                                   //   search -- several repetitions
                                   //   may be needed in order to
                                   //   produce a meaningful timing

//--------------------------------------------------------------------

void main ()
{
    Timer searchTimer;            // Timer for searching routine
    int *keyList,                 // Array of integer keys
        numKeys,                  // Number of array entries
        searchSet[numSearches],   // Array of keys to search for
        dummy,                    // Status returned by search
        index,                    // Index returned by search
        j, k;                     // Loop counters
    double timePerSearch;         // Time per search (in seconds)

    // Get the number of keys.

    cout << endl << "Enter the number of keys (must be at least "
         << numSearches << ") : ";
    cin >> numKeys;
    if ( numKeys < numSearches )
    {
       cout << "Number of keys is too small" << endl;
       exit(1);
    }

    // Allocate the array of keys.

    keyList = new int [numKeys];
    if ( keyList == 0 )
    {
       cout << "Cannot allocate enough memory for that many keys"
            << endl;
       exit(1);
    }

    // Initialize the array of keys and the search set.

    for ( j = 0 ; j < numKeys ; j++ )
        keyList[j] =  rand();
    quickSort(keyList,numKeys);

    for ( j = 0 ; j < numSearches ; j++ )
        searchSet[j] = rand();

    // Output header

    cout << endl;
    cout << "    Search        Time per search (secs.)" << endl;
    cout << "--------------    -----------------------" << endl;

    // Linear search --
    // Determine how long it takes to search for the keys in
    // searchSet. Repeat the searches numRepetitions times.

    searchTimer.start();
    for ( j = 0 ; j < numRepetitions ; j++ )
        for ( k = 0 ; k < numSearches ; k++ )
            dummy = linearSearch(keyList,numKeys,searchSet[k],index);
    searchTimer.stop();

    timePerSearch = searchTimer.elapsedTime() /
                    ( double(numSearches) * numRepetitions );

    cout << "linearSearch           " << timePerSearch << endl;

    // Binary search --
    // Determine how long it takes to search for the keys in
    // searchSet. Repeat the searches numRepetitions times.

    searchTimer.start();
    for ( j = 0 ; j < numRepetitions ; j++ )
        for ( k = 0 ; k < numSearches ; k++ )
            dummy = binarySearch(keyList,numKeys,searchSet[k],index);
    searchTimer.stop();

    timePerSearch = searchTimer.elapsedTime() /
                    ( double(numSearches) * numRepetitions );

    cout << "binarySearch           " << timePerSearch << endl;

    // Unknown search --
    // Determine how long it takes to search for the keys in
    // searchSet. Repeat the searches numRepetitions times.

    searchTimer.start();
    for ( j = 0 ; j < numRepetitions ; j++ )
        for ( k = 0 ; k < numSearches ; k++ )
            dummy = unknownSearch(keyList,numKeys,searchSet[k],index);
    searchTimer.stop();

    timePerSearch = searchTimer.elapsedTime() /
                    ( double(numSearches) * numRepetitions );

    cout << "unknownSearch          " << timePerSearch << endl;

    // Deallocate the array of keys.

    delete [] keyList;
}