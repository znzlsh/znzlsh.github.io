//--------------------------------------------------------------------
//
//  Laboratory 15, In-lab Exercise 2                        sort.cpp
//
//  Implementation of a set of sorting routines
//
//--------------------------------------------------------------------

template < class LE >
void selectionSort ( LE keyList [], int numKeys )

// Selection sort routine. Sorts the first numKeys keys in keyList
// into ascending order.

{


}

//--------------------------------------------------------------------

template < class LE >
void quickSort ( LE keyList [], int numKeys )

// Quicksort routine. Sorts the first numKeys keys in keyList into
// ascending order.

{
    quickPartition(keyList,numKeys,0,numKeys-1);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void quickPartition ( LE keyList [], int numKeys,
                      int left, int right         )

// Recursive partner of the quickSort routine. Partitions the array
// entries between left and right into two subarrays. One subarray
// contains the keys that are less than or equal to splitValue, and
// the other contains the keys that are greater than splitValue.
// Recursively sorts each of these subarrays.

{


}

//--------------------------------------------------------------------

template < class LE >
void unknownSort ( LE keyList [], int numKeys )

// Unknown sort routine. Sorts the first numKeys keys in keyList into
// ascending order.

{




}