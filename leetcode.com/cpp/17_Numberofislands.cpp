/*Approach->
  *First we iterate through the elements in the grid
  *Whenever we encounter '1'(land), we call DFS 
  *When we DFS-
             1.Make sure the current elemente is in bounds and is '1'
             2.Set the element = '2'
             3.Recurse in all 4 directions
*/

class Solution {
    void DFS(vector<vector<char>> &matrix,int x,int y,int r,int c)
    {
        if(x<0 || x>=r || y<0 || y>=c || matrix[x][y]!='1')  //Boundary case for matrix
            return;
        
        
        matrix[x][y] = '2';  //Mark current cell as visited
        
        //Make recursive call in all 4 adjacent directions
        DFS(matrix,x+1,y,r,c);  //DOWN
        DFS(matrix,x,y+1,r,c);  //RIGHT
        DFS(matrix,x-1,y,r,c);  //TOP
        DFS(matrix,x,y-1,r,c);  //LEFT
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        //For FAST I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int rows = grid.size();
        if(rows==0)     //Empty grid boundary case
            return 0;
        int cols = grid[0].size();
        
        //Iterate for all cells of the array
        int no_of_islands = 0;
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(grid[i][j]=='1')  // means if piece of land not visited
                {
                    DFS(grid,i,j,rows,cols);
                    no_of_islands += 1;
                }
            }
        }
        return no_of_islands;
    }
};