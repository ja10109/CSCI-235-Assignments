//
//  SortingComparison.cpp
//  SortTest
//
//  Created by Tiziana Ligorio on 10/4/19.
//  Course project, Hunter Collegge, CSci 235 - Software Design and Analysis II
//  Sorting functions implementation adapted from Big C++, Late Objects, Wiley
//  Copyright Ã‚Â© 2019 Tiziana Ligorio. All rights reserved.
//
// ********** ADD YOUR CONTRIBUTION INFORMATION HERE!!! ******************
//global function int comparisons = 0 at line 25 which is used
//in every sorting method function where it gets reset in the beginning
//of its call and provides the number of sorting comparison for each
//sorting function
//line 79 int sorted is used to compare a value of the array
//and check if it's greater than the following value
//line 259 a new function used to reset comparisons to 0
//new function reset is used to set comparisons to 0 each time a sorting function is called.

#include "SortingComparison.hpp"

//parameterized constructor allocate values_ with array_size
SortingComparison::SortingComparison(size_t array_size): SIZE(array_size), values_(new int[SIZE]) {}

/*****************************************************************/
/********************* SORTING FUNCTIONS *************************/
/*****************************************************************/

int comparisons = 0;

/*************** SELECTION SORT + HELPER **************************/

/**
 @post Gets the position of the smallest element in an array range.
 @param a the array
 @param from the beginning of the range
 @param to the end of the range
 @return the position of the smallest element in
 the range a[from]...a[to]
 */
int SortingComparison::minPosition(int a[], int from, int to)
{
    int min_pos = from;
    for (int i = from + 1; i <= to; i++)
    {
        if (a[i] < a[min_pos])
		{
			min_pos = i;
		}
		comparisons++;
	}
    return min_pos;
}

/**
 @post Sorts an array in ascending order using the selection sort algorithm.
 @return the number of comparisons made by the algorithm
 */
int SortingComparison::selectionSort(int a[], size_t size)
{
	comparisons = 0;//reset comparisons if multiple sort methods were called.
    for (int i = 0; i < size; i++)
    {
        // Find the position of the minimum
        int min_pos = minPosition(a, i, static_cast<int>(size - 1));
        std::swap(a[i], a[min_pos]);
    }
    return comparisons;  //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS
}

/*************** INSERTION SORT **************************/

/**
 @post Sorts an array in ascending order using insertion sort.
 @param a the array to sort
 @param size of the array
 @return the number of comparisons of two  array elements made by the algorithm
 */
int SortingComparison::insertionSort(int a[], size_t size)
{
	int sorted = 0;
	for(int i = 1;i < size;i++)
	{
		if(a[sorted] > a[i])
		//in the first call, if value of a[sorted] or a[0] is greater
		//than a[i], swap the values, comparisons increases
		{
			std::swap(a[sorted],a[i]);
			for(int j = i-1;j > 0;j--)
			{
				if(a[j] < a[j-1])
					std::swap(a[j],a[j-1]);
				comparisons++;
			}
		}
		comparisons++;
		sorted++;
	}
    return comparisons;  //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS
}
/************************* MERGE SORT + HELPER **************************/

/**
 @post Merges two adjacent subarrays.
 @param a the array with the elements to merge
 @param from the start of the first subarray
 @param mid the end of the first subarray
 @param to the end of the second subarray
 */
void SortingComparison::merge(int a[], int from, int mid, int to)
{
    int n = to - from + 1; // Size of the range to be merged
    // Merge both halves into a temporary array temp_array
    int* temp_array = new int[n];

    int i1 = from;
    // Next element to consider in the first half
    int i2 = mid + 1;
    // Next element to consider in the second half
    int j = 0; // Next open position in temp_array

    // Compare elements in subarrays for merging
    // As long as neither i1 nor i2 is past the end,
    // move the smaller element into temp_array

    while (i1 <= mid && i2 <= to)
    {
        if (a[i1] < a[i2])
        {
            temp_array[j] = a[i1];
            i1++;
            comparisons++;
        }
        else
        {
           temp_array[j] = a[i2];
           i2++;
           comparisons++;
        }
        j++;
    }


    // Note that only one of the two while loops below is executed

    // Copy any remaining entries of the first half
    while (i1 <= mid)
    {
        temp_array[j] = a[i1];
        i1++;
        j++;
        comparisons++;
    }
    // Copy any remaining entries of the second half
    while (i2 <= to)
    {
        temp_array[j] = a[i2];
        i2++;
        j++;
        comparisons++;
    }

    // Copy back from the temporary array
    for (j = 0; j < n; j++)
    {
        a[from + j] = temp_array[j];
    }

    delete[] temp_array;
}

/**
 @post Sorts the elements in a range of a array.
 @param a the array with the elements to sort
 @param from the first position in the range to sort
 @param to the last position in the range to sort (included)
 @return the number of comparisons made by the algorithm
 */
int SortingComparison::mergeSort(int a[], int from, int to)
{
    if (from == to){
		return 0;
	}
		
    int mid = (from + to) / 2;
    // Recursively sort the first and the second half
    mergeSort(a, from, mid);
    mergeSort(a, mid + 1, to);
    merge(a, from, mid, to);

    return comparisons;  //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS
}

/************************* QUICK SORT + HELPER**************************/

/**
   Partitions a portion of an array.
   @param a the array to partition
   @param from the first index of the portion to be partitioned
   @param to the last index of the portion to be partitioned
   @return the last index of the first partition
*/
int SortingComparison::partition(int a[], int from, int to)
{
   int pivot = a[from];
   int i = from - 1; //index of data item being compared from left
   int j = to + 1;   //index of data item being compared from right
   while (i < j)    // as long as i and j did not cross (meet)
   {
      i++;
      while (a[i] < pivot)//increment i until a[i] >= pivot
      {
      	i++;
      	comparisons++;
	  }

      j--;
      while (a[j] > pivot) //decrement j until a[j] <= pivot
      {
      	j--;
      	comparisons++;
	  }

      if (i < j) //assuming we do not increment comparisons here
	      std::swap(a[i], a[j]); //because it is the comparasion between 2 indices
   }
   return j; // the pivot index
}

/**
   @post Sorts an array in ascending order using quick sort.
   @param a the array to sort
   @param from the first index of the portion to be sorted
   @param to the last index of the portion to be sorted
  @return the number of comparisons made by the algorithm
*/
int SortingComparison::quickSort(int a[], int from, int to)
{
    if (from >= to){
		return 0;
	}

    int p = partition(a, from, to);
    quickSort(a, from, p);
    quickSort(a, p + 1, to);
    
    return comparisons;  //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS
}

/*****************************************************************/
/******************  TEST FUNCTION *******************************/
/*****************************************************************/
//setter and getter for comparisons(class private variable to store the number of comparasions)
//if another sorting method was called:
//BEFORE GOING INTO QUICKSORT AND MERGESORT YOU MUST CALL THE resetCount() function.

void SortingComparison::reset()
{
	comparisons = 0;
}

//*************  IMPLEMENT runComparison HERE!!!! ************//
void SortingComparison::runComparison(data_distribution array_type)
{
	srand(static_cast<unsigned>(time(0)));
	int values_[SIZE];
	switch(array_type)
	{
		case INCREASING:{
			for(int i =0; i < SIZE; i++)
			{
				values_[i] = i;
				//as i increments, values_[] increases
			}
			break;
		}
		case DECREASING:{
			for(int i = 0; i < SIZE; i++)
			{
				values_[i] = SIZE - i;
				//as i increments values_[i] decreases
			}
			break;
		}
		case RANDOM:{
			for(int i = 0; i < SIZE; i++)
			{
				values_[i] = rand() % SIZE;
				//values_[i] is set to random as array_type is random
			}
			break;
		}
	}
	
	int selection_sort[SIZE];
	int insertion_sort[SIZE];
	int merge_sort[SIZE];
	int quick_sort[SIZE];
	for(int i = 0; i < SIZE; i++)
	{
		selection_sort[i] = values_[i];
		insertion_sort[i] = values_[i];
		merge_sort[i] = values_[i];
		quick_sort[i] = values_[i];
		//values_[i] get set to each sorting array depending on what array_type is
	}
	
	std::cout << "Selection Sort Comparisons: " << selectionSort(selection_sort, SIZE) << "\n" << "\n";
	reset();
	std::cout << "Insertion Sort Comparisons: " << insertionSort(insertion_sort, SIZE) << "\n" << "\n";
	reset();
	std::cout << "Merge Sort Comparisons: " << mergeSort(merge_sort, 0, SIZE) << "\n" << "\n";
	reset();
	std::cout << "Quick Sort Comparisons: " << quickSort(quick_sort, 0, SIZE) << "\n" << "\n";
}
//end of implementation file
