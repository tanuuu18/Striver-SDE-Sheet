#include <bits/stdc++.h> 

//Kadane’s Algorithm : Maximum Subarray Sum in an Array
long long maxSubarraySum(int arr[], int n)
{
    //<-------------------- Brute force Approach ----------------------------->

    //-> To get every possible subarry sum ,We will be using 3 nested loops

    // 1. Start loop i = 0 to n-1
    //           start loop j = i to n-1
    //                 Start loop from i to j 
    //                     calculate sum of evements from i to j of that particular subarry

        //  __________________________________________
        // |                                          |
        // |  Time Complexity = O(N*N*N) = O(N^3)     |  //running 3 nested loops
		// |  Space Complexity = O(1)                 |  // not using any extra space
		// |__________________________________________|
    

    //to store maximum sum
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            //subarray = nums[i....j]
            int sum = 0;
            //calculate sum of all elements
            for(int k=i;k<=j;k++){
                sum += nums[k];
            }
            //if sum is negative
            if(sum<0){
                sum=0;
            }
            maxi = max(maxi,sum);
        }
    }
    return maxi;
}