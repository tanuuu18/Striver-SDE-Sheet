#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &nums)
{
	//<------------------ Brute Force Approach -------------------------->

	// 1. Whenever we find 0, then go through its row and make all elements to -1 
	// and same go through column and make all elements to -1.

	// 2. After checking the whole matrix, then change -1 to 0.

	// 3. Final matrix will be our answer.
	    //  _______________________________________________
        // |                                               |
        // |  Time Complexity = O((N*M)+(N+M)) + O(N*M)    |
		// |  Space Complexity = O(1)                      |
		// |_______________________________________________|
		

	// int n = nums.size();
	// int m = nums[0].size();

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		if(nums[i][j]==0){

	// 			//Above 0
	// 			int ind = i-1;
	// 			while(ind>=0){
	// 				if(nums[ind][j]!=0){
	// 					nums[ind][j]=-1;
	// 				}
	// 				ind--;
	// 			}

	// 			//Below 0
	// 			ind = i+1;
	// 			while(ind<n){
	// 				if(nums[ind][j]!=0){
	// 					nums[ind][j]=-1;
	// 				}
	// 				ind++;
	// 			}

	// 			//Left to 0
	// 			ind = j-1;
	// 			while(ind>=0){
	// 				if(nums[i][ind]!=0){
	// 					nums[i][ind]=-1;
	// 				}
	// 				ind--;
	// 			}

	// 			//Right to 0
    //             ind = j+1;
	// 			while(ind<m){
	// 				if(nums[i][ind]!=0){
	// 					nums[i][ind]=-1;
	// 				}
	// 				ind++;
	// 			}
	// 		}
	// 	}
	// }

    // //Traverse and Change -1 to 0
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		if(nums[i][j]==-1){
	// 			nums[i][j]=0;
	// 		}
	// 	}
	// }


	//<------------------ Optimized Approach -------------------------->

	// Reducing the time complexity

	// 1. Create 2 dummy array for row and column and initialized them to -1.

	// 2. Then Linearly Traverse the matrix ,
	//    if you find any 0 
	//        then make 0 in jth index of dummyCol array & ith index of dummyRow array.

	// 3. Then Traverse the matrix if either dummyRow or dummyCol is 0 then
    //     make make value of that particular index to 0.
	    //  _______________________________________
        // |                                       |
        // |  Time Complexity = O(2*(N*M))         |
		// |  Space Complexity = O(N) + O(M)       |
		// |_______________________________________|

	int n = nums.size();
	int m = nums[0].size();

	vector<int>dummyRow(n,-1);
	vector<int>dummyCol(m,-1);

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(nums[i][j]==0){
				dummyRow[i]=0;
				dummyCol[j]=0;
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(dummyRow[i]==0 || dummyCol[j]==0){
				nums[i][j]=0;
			}
		}
	}
}