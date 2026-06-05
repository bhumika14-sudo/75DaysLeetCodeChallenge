class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, 1, -1, 0};

    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()) {

            auto pr = pq.top();
            pq.pop();

            int dist_of_par = pr.first;
            int x = pr.second.first;
            int y = pr.second.second;

            if(dist_of_par > dist[x][y])
                continue;

            if(x == n - 1 && y == m - 1)
                return dist_of_par;

            for(int k = 0; k < 4; k++) {

                int ii = x + dx[k];
                int jj = y + dy[k];

                if(ii < 0 || jj < 0 || ii >= n || jj >= m)
                    continue;

                int new_dist =
                    max(dist_of_par,
                        abs(heights[x][y] - heights[ii][jj]));

                if(new_dist < dist[ii][jj]) {

                    dist[ii][jj] = new_dist;

                    pq.push({new_dist, {ii, jj}});
                }
            }
        }

        return 0;
    }
};