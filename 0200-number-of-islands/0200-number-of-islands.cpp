class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int islands = 0;
        queue<pair<int,int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // New island found
                if (grid[i][j] == '1') {

                    islands++;

                    grid[i][j] = '0';        // mark visited
                    q.push({i, j});

                    // BFS to visit the entire island
                    while (!q.empty()) {

                        auto node = q.front();
                        q.pop();

                        int x = node.first;
                        int y = node.second;

                        for (int k = 0; k < 4; k++) {

                            int newX = x + dx[k];
                            int newY = y + dy[k];

                            if (newX >= 0 && newX < n &&
                                newY >= 0 && newY < m &&
                                grid[newX][newY] == '1') {

                                grid[newX][newY] = '0';
                                q.push({newX, newY});
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
};