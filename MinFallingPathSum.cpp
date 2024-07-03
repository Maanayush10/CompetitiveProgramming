/*

931. Minimum Falling Path Sum
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100

*/

//shoutout to striver
/*
Approach
for each cell in the first row find minPath using DP and calculate the min out of it.
for each iteration you check the min of (left-Diagional-cell, below-cell, right-Diagonal-cell), and keep on adding till you reach the last cell, 
find min of all paths for current cell
*/

class Solution {

public:
    int f(int row, int col, int size, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (row == size -1) {
            return matrix[row][col];
        }
        if(dp[row][col]!=INT_MAX)
        {
            return dp[row][col];
        }
        int ldg=INT_MAX, rdg= INT_MAX;
        if (col > 0) {
            ldg = matrix[row][col] + f(row + 1, col - 1, size, matrix, dp);
        } else {
            ldg = INT_MAX;
        }
        int below = matrix[row][col] + f(row + 1, col, size, matrix, dp);
        if (col < size-1) {
            rdg = matrix[row][col] + f(row + 1, col + 1, size, matrix, dp);
        } else {
            rdg = INT_MAX;
        }
        return dp[row][col]=min(ldg, min(below, rdg));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int size = matrix.size();
        vector<vector<int>>dp(size, vector<int>(size, INT_MAX));
        int result=INT_MAX;
        for(int i=0; i<size; i++)
        {
            result= min(result, f(0, i, size, matrix, dp));
        }
        return result;
    }
};
