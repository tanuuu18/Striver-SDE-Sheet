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
    

    // //to store maximum sum
    // int maxi = INT_MIN;
    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         //subarray = nums[i....j]
    //         int sum = 0;
    //         //calculate sum of all elements
    //         for(int k=i;k<=j;k++){
    //             sum += nums[k];
    //         }
    //         //if sum is negative
    //         if(sum<0){
    //             sum=0;
    //         }
    //         maxi = max(maxi,sum);
    //     }
    // }
    // return maxi;



    //<-------------------- Better Approach ----------------------------->

    //-> Carefully observe that to get the current subarray sum 
    //   add current element to the previous subarry sum.
    //   So, we can remove the 3rd loop

    // 1. Start loop i = 0 to n-1
    //           start loop j = i to n-1
    //                 add the current element in the previous subarray sum

        //  __________________________________________
        // |                                          |
        // |  Time Complexity = O(N*N) = O(N^2)       |  //running 2 nested loops
		// |  Space Complexity = O(1)                 |  // not using any extra space
		// |__________________________________________|

    // to store maximum sum
    // int maxi = INT_MIN;
    // for(int i=0;i<n;i++){
    //     int sum =0;
    //     for(int j=i;j<n;j++){
    //         //current subarray sum
    //         sum += nums[j];
    //         // if sum is negative
    //         if(sum<0){
    //             sum=0;
    //         }
    //         //finding the max
    //         maxi = max(maxi,sum);
    //     }
    // }
    // return maxi;


    //<-------------------- Optimal Approach ----------------------------->
     
    // Intuition: not consider the subarray as part of answer
    //             If it's sum less than 0.

    // A subarray with a sum less than 0 will always reduce our answer 
    // and so this type of subarray cannot be a part of the subarray with maximum sum.

    
    //   So, we can solve this using a single loop

    // 1. Start loop i = 0 to n-1
    //         add the current element in to sum
    //         and update maxi with max result
    //         if sum is negative then set sum to 0

        //  __________________________________________
        // |                                          |
        // |  Time Complexity = O(N)                  |  //running a single loop
		// |  Space Complexity = O(1)                 |  // not using any extra space
		// |__________________________________________|

    // To store the maximum sum
    long long maxi = INT_MIN;
    long long sum = 0;
    for(int i=0;i<n;i++){
        sum += nums[i];
        maxi = max(maxi,sum);
        //If sum <0 then discard it
        if(sum<0){
            sum = 0;
        }
    }

    //To consider the sum of empty array as 0
    if(maxi<0){
        maxi = 0;
    }
    return maxi;



    //<------------------- Follow up Question -------------------------------->

    // There might be more than one subarray with max sum.We need to print any of them.

    // Intuition: Store the starting index and ending index of the subarray
    //            so, we can easily get the subarray without storing the subarray elements.


    // Observation: Subarray always starts at the particular index where the sum = 0 
    //              and ends at the ending index where the sum always crosses the
    //              prev max sum (i.e. maxi)


    //    1. Keep track of the starting index inside the loop using start
    //    2. Take 2 variables ansStart and ansEnd and initialized them with -1
    //    3. When the sum crosses the max sum
    //             then set ansStart = start and ansEnd = current index


    //Rest of the spproach is same as Kadane's algorithm.


    // long long maxi = LONG_MIN;
    // long long sum = 0;

    // int start = 0;
    // int ansStart = -1, ansEnd = -1;

    // for(int i=0;i<n;i++){
    //     if(sum==0){
    //         start = i; //starting index
    //     }
    //     sum += nums[i];
    //     // if sum crosses maxi
    //     if(sum>maxi){
    //         maxi = sum;
    //         ansStart = start;
    //         ansEnd = i;
    //     }
    //     //if sum < 0 then discard it
    //     if(sum<0){
    //         sum = 0;
    //     }
    // }

    // cout<<"Subarray: [";
    // for(int i= ansStart;i<=ansEnd;i++){
    //     cout<<nums[i]<<" ";
    // }
    // cout<<"]";

    // return maxi;
}