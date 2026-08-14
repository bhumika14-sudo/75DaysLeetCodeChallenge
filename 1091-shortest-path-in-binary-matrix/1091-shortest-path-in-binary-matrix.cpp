class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        vis[0][0] = 1;
        q.push({{0,0}, 1});

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            int dr[] = {-1,-1,-1,0,0,1,1,1};
            int dc[] = {-1,0,1,-1,1,-1,0,1};

            if(row==n-1 && col==n-1) return dist;
            for (int k = 0; k < 8; k++) {
                int nr = row + dr[k];
                int nc = col + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] == 0) {
                    vis[nr][nc] = 1;
                    q.push({{nr, nc}, dist + 1});
                }
            }
        } 
        return -1;
    }
};