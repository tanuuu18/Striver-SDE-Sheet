#include <bits/stdc++.h> 
#include<iostream>



//<--------------- Rotate image by 90 deg ------------------------------>
void rotateMatrix(vector<vector<int>> &nums, int n, int m)
{
   
//    <-----------------Brute force Approach --------------------------->

//    Step 1:  Take the dummy matrix of size n*m .
//    Step 2: Take the 1st row of matrix and put it in the last volumn of dummy matrix.
//    Step 3: Take the 2nd row of matrix and pu it in the second last column of the dummy matrix and so on.

        //  __________________________________________
        // |                                          |
        // |  Time Complexity = O(N*N)                |  
		// |  Space Complexity = O(N*N)               | 
		// |__________________________________________|


   vector<vector<int>>rotated(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			rotated[j][n-i-1] = nums[i][j];
		}
	}
	nums = rotated;
   


       
}