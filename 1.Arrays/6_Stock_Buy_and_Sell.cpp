#include <bits/stdc++.h> 
int maximumProfit(vector<int> &nums){
    // <-------------------- Brute Force Approach ------------------------------>

    // Intuition: -> Use 2 loops and track every transaction
    //            -> and maintain a variable maxi which contain max of all transactions.


    int n = nums.size();
    int maxi = 0;   //-> to contain max profit
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]<nums[j]){ //if prices of another day after buy is high then update maxi
                maxi = max(maxi,nums[j]-nums[i]);
            }
        }
    }
    return maxi;
}