#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &nums, int n){

    //  <----------------------------- Burte Force Approach ------------------------------------------>

    // 1. Generate all possible Permutations of given array.
    // 2. Find the given nums array in all permutations 
    //     if present 
    //        then return the next permutation right to it.
    //     if num is not present
    //        then return its first permutation.

        //  _______________________________________
        // |                                       |
        // |  Time Complexity = O(N * N!)          |  //n elements and N! to respresent all permutations
		// |  Space Complexity = O(N)              |  // to store permutation
		// |_______________________________________|


    // <-------------------- Using Built-in Function ------------------------>

    //    C++ provides an in-built function called next_permutation()
    //     which directly returns the lexicographically next greater permutation of the input.

    // next_permutation(nums.begin(),nums.end());
	// return nums;



    //<---------------------------------- Optimal Approach ---------------------------------------------->

    // 1. We will find the break point means 1st index from last where nums[i]<nums[i+1]
    // 2. If there is no break point exists (i.e. array is in decreasing order )
    //         then return the reverse of the given array
    // 3. If there is break point exists
    //         then find the just smaller element than nums[i] (break point value) (loop will start from last)
    //         and then swap with them.

    //         then reverse the array from after break point index to last.  

        // ________________________________________
        // |                                       |
        // |  Time Complexity = O(3*N)             |  
		// |  Space Complexity = O(1)              |  
		// |_______________________________________|



        	//Step 1: Find the break point
	int ind = -1;//break point
    for(int i=n-2;i>=0;i--){
		if(nums[i]<nums[i+1]){
			//index i is the break point
			ind = i;
			break;
		}
	}

	//If break point doesn't exist
	if(ind==-1){
		//reverse the whole given array
		reverse(nums.begin(),nums.end());
		return nums;
	}


	//Step 2: Find the next greater element than break point
	//        and swap them
	for(int i=n-1;i>ind;i--){
		if(nums[i]>nums[ind]){
			swap(nums[i],nums[ind]);
			break;
		}
	}

	//Step 3: Reverse the right half of the array
	reverse(nums.begin()+ind+1,nums.end());

	return nums;
  
}