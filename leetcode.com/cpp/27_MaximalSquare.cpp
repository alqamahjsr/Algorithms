/*Maximal Square

Solution
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4

*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int rows = matrix.size();
        if(rows==0)
            return 0;
        int cols = matrix[0].size();
        
        vector<vector<int>> dp(rows+1,vector<int>(cols+1,0));
        int largest = 0;
        for(int i=1;i<=rows;++i)
        {
            for(int j=1;j<=cols;++j)
            {
                if(matrix[i-1][j-1]=='1')
                {
                    dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                    if(largest < dp[i][j])
                        largest = dp[i][j];
                }
            }
        }
        return largest*largest;
    }
};