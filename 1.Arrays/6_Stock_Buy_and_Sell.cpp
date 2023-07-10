#include <bits/stdc++.h> 
int maximumProfit(vector<int> &nums){
    // <-------------------- Brute Force Approach ------------------------------>

    // Intuition: -> Use 2 loops and track every transaction
    //            -> and maintain a variable maxi which contain max of all transactions.


        //  __________________________________________
        // |                                          |
        // |  Time Complexity = O(N^2)                |  //running 2 nested loop
		// |  Space Complexity = O(1)                 |  // not using any extra space
		// |__________________________________________|



    // int n = nums.size();
    // int maxi = 0;   //-> to contain max profit
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(nums[i]<nums[j]){ //if prices of another day after buy is high then update maxi
    //             maxi = max(maxi,nums[j]-nums[i]);
    //         }
    //     }
    // }
    // return maxi;


    //<------------------------------ Optimal Approach ---------------------------->

    // Intuition: ->Linearly traverse the array.
    //            -> Maintain a mini from start and compare it with every elemnt of array
    //                 if current element greater than mini 
    //                     then take difference and maintain it in maxi
    //                 else
    //                     update the mini


    // Step 1: Create maxi = 0 and mini = INT_MAX
    // Step 2: start loop i=0 to n 
    //             update mini if it's greater than current element
    //             take the diff of mini and current element and compare with maxi and update it
    // Step 3: return maxi


        //  __________________________________________
        // |                                          |
        // |  Time Complexity = O(N)                  |  //running a single loop
		// |  Space Complexity = O(1)                 |  // not using any extra space
		// |__________________________________________|



    int n = nums.size();
    int maxi = 0,mini = INT_MAX;
    for(int i=0;i<n;i++){
        mini = min(mini,nums[i]);
        maxi = max(maxi,nums[i]-mini);
    }
    return maxi;
}