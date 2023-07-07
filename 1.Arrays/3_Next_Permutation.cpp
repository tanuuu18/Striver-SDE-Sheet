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

    next_permutation(nums.begin(),nums.end());
	return nums;
}