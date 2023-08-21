class Solution {
public:

    void dfs(int row,int col,vector<vector<int>>&grid,int& a){
        if(row >= 0 && row < grid.size() && col >= 0 && col <grid[0].size() && grid[row][col]){
            a++;
            grid[row][col] = 0;
            dfs(row,col+1,grid,a);
            dfs(row,col-1,grid,a);
            dfs(row+1,col,grid,a);
            dfs(row-1,col,grid,a);
        }
       
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size(), n = m ? grid[0].size() : 0, area = 0;

        for(int i = 0;i<m;i++){
            for(int j = 0; j < n ; j++){

                if(grid[i][j]){
                    int a = 0;
                    dfs(i,j,grid,a);
                    area = max(area,a);
                }
            }
        }
    return area;
    }
};