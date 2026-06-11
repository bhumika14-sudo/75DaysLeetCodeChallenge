class Solution {
public:
    void dfs(int a, int b, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        if(a<0 || a>=n || b<0 || b>=m || grid[a][b]!=1) return;

        grid[a][b] = 2; //mark visited 

        dfs(a+1, b, grid);
        dfs(a-1, b, grid);
        dfs(a, b+1, grid);
        dfs(a, b-1, grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        //First and last column
        for(int i=0; i<n; i++){
            if(grid[i][0] == 1) dfs(i, 0, grid);
            if(grid[i][m-1] == 1) dfs(i, m-1, grid);
        }

        // first and last row 
        for(int j=0; j<m; j++){
            if(grid[0][j] == 1) dfs(0, j, grid);
            if(grid[n-1][j]) dfs(n-1, j, grid);
        }

        int count=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};