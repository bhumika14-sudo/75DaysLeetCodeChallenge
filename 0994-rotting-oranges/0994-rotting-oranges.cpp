class Solution {
public:
    int nr[4] = {-1,0,0,1};
    int nc[4] = {0,-1,1,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;

        int fresh = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int time = 0;
        while(!q.empty() && fresh>0){
            int size = q.size();
            while(size--){
                auto node = q.front();
                q.pop();

                int x = node.first;
                int y = node.second;

                for(int k=0; k<4; k++){
                    int newX = x + nr[k];
                    int newY = y + nc[k];

                    if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY] == 1){
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                        fresh--;
                    }
                }
            }
            time++;
        }
        if(fresh > 0) return -1;
        return time;
    }
};