#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &nums)
{
	//<------------------ Brute Force Approach -------------------------->

	// 1. Whenever we find 0, then go through its row and make all elements to -1 
	// and same go through column and make all elements to -1.

	// 2. After checking the whole matrix, then change -1 to 0.

	// 3. Final matrix will be our answer.
	    //  ________________________________________________
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
    //    make value of that particular index to 0.
	    //  _______________________________________
        // |                                       |
        // |  Time Complexity = O(2*(N*M))         |
		// |  Space Complexity = O(N) + O(M)       |
		// |_______________________________________|

	// int n = nums.size();
	// int m = nums[0].size();

	// vector<int>dummyRow(n,-1);
	// vector<int>dummyCol(m,-1);

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		if(nums[i][j]==0){
	// 			dummyRow[i]=0;
	// 			dummyCol[j]=0;
	// 		}
	// 	}
	// }

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		if(dummyRow[i]==0 || dummyCol[j]==0){
	// 			nums[i][j]=0;
	// 		}
	// 	}
	// }


	//<------------------ Most Optimized Approach -------------------------->

	// Reducing the space complexity

	// 1. Instead of using 2 dummy array ,we will use 1st row and 1st column as dummy row and column.
        // ___________________________________________________________________________________________________
	    // |    Problem: 1st row and 1st column as dummy array serve the purpose but nums[0][0] taken twice. |
        // |                                                                                                 |
		// |    Solution: Take a variable col0 and initialized it to 1.                                      |
		// |              Now, 1st row of the matrix will work as dummy row and                              |
		// |		       1st column of the matrix and col0 will work as dummy column.                      |
        // |_________________________________________________________________________________________________|


	// 2. Then start a loop i and check
	//        if 0th col is 0 then
	//            mark col0 = 0 
	//        start loop j from 1st column and check if element is 0 then
	//              mark ith index of row -> nums[i][0] as 0  (like ith index of dummy row we marked as 0)
	//              and mark jth index of col -> nums[0][j] as 0 (like jth index of dummy col we marked as 0)
 
	// 3. Then Traverse the matrix in reverse direction from (n-1 -> 0) & (m-1 -> 0)
    //    if either ith index of col 0 or jth index of row 0 is 0
	//         then mark nums[i][j]=0
	//    and if col0 = 0 then mark ith row of col 0 as 0  (i.e. nums[i][0]=0)
	    //  _______________________________________
        // |                                       |
        // |  Time Complexity = O(2*(N*M))         |
		// |  Space Complexity = O(1)              |
		// |_______________________________________|


	int n = nums.size();
	int m = nums[0].size();
	int col0 = 1;


	for(int i=0;i<n;i++){
		//check if 0th column is 0 or not
		if(nums[i][0]==0){
			col0 = 0;
		}
		for(int j=1;j<m;j++){
			if(nums[i][j]==0){
				nums[i][0] = 0;
				nums[0][j] = 0;
			}
		}
	}

    //Traverse the array in reverse direction and checking 
	//if either row or col has 0 or not the set the matrix accordingly
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=1;j--){
			if(nums[i][0]==0 || nums[0][j]==0){
				nums[i][j]=0;
			}
			if(col0==0){
				nums[i][0] = 0;
			}
		}
	}
}
