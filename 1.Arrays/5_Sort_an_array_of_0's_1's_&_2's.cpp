#include <bits/stdc++.h> 
void sort012(int *nums, int n)
{
    // <------------------------ Brute force approach ------------------------->

    // Sorting -> Not the expected solution but it can be considered as one of the approach;

        //  __________________________________________
        // |                                          |
        // |  Time Complexity = O(N*logN)             |  // for sorting
		// |  Space Complexity = O(1)                 |  // not using any extra space
		// |__________________________________________|


	// sort(nums,nums+n);

    //<------------------------- Better Approach ----------------------------->

    //-------------------- Keeping the Count of Values -----------------------------

    // Intuition : There are only 3 distinct values so, it's easy to maintain the count of all values.
    //             After that overwrite the array based on the count of values.

    
    // Step 1: Take 3 variable to maintain count of 0, 1 & 2.
    // Step 2: Traverse the array once and incrementing the corresponding count variable.
    // Step 3: Again traverse the array,Now over write the 
    //             1st 'a' indexes with 0,
    //             next 'b' indexes with 1,
    //             and remaining 'c' indexes with 2.


        //  __________________________________________
        // |                                          |
        // |  Time Complexity = O(N) + O(N)           |  //running 2 loops
		// |  Space Complexity = O(1)                 |  // not using any extra space
		// |__________________________________________|

    // //Step 1: Initialize the count variable for 0,1&2
	// int count_0 = 0, count_1 = 0, count_2 = 0;
	// //Step 2: Count the values and update their corresponding count variable
	// for(int i=0;i<n;i++){
	// 	if(nums[i]==0){
	// 		count_0++;
	// 	}
	// 	else if(nums[i]==1){
	// 		count_1++;
	// 	}
	// 	else{
	// 		count_2++;
	// 	}
	// }

    // //Step 3: Over write the array 
	// //Replacing 0
	// for(int i=0;i<count_0;i++){
	// 	nums[i] = 0;
	// }
	// //Replacing 1
	// for(int i=count_0;i<count_0+count_1;i++){
	// 	nums[i] = 1;
	// }
	// //Replacing 2
	// for(int i=count_0+count_1;i<n;i++){
	// 	nums[i] = 2;
	// }

    //<------------------------- Optimal Approach ----------------------------->

    //--------------------Dutch National Flag Algorithm -----------------------------

	This algo contains 3 pointers: low, mid & high 

	nums[0...low-1] contains 0. (Extreme left part)
	nums[low...mid-1] contains 1. 
	nums[high+1...n-1] contains 2. (Extreme right part)

	nums[mid...high] (middle part) is the unsorted segment


	1. Run a loop until mid<=high
	2. There can be 3 different cases of mid pointer i.e. nums[mid]
	    -> if(nums[mid]==0)
		        then swap nums[low] and nums[mid]

}