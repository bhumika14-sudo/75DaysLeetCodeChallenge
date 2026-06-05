class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> graph(n);
        for(int i = 0; i < flights.size(); i++) {
            int from = flights[i][0];
            int to   = flights[i][1];
            int wt   = flights[i][2];
            graph[from].push_back({to, wt});
        }
        queue<vector<int>> q;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        q.push({0, src, 0}); // stops, node, cost

        while(!q.empty()) {
            auto pr = q.front();
            q.pop();

            int stops_taken = pr[0];
            int node        = pr[1];
            int cost        = pr[2];

            if(stops_taken > k)
                continue;

            for(auto &nbr_info : graph[node]) {
                int nbr = nbr_info.first;
                int wt  = nbr_info.second;
                int new_cost = cost + wt;
                if(new_cost < dist[nbr]) {
                    dist[nbr] = new_cost;
                    q.push({stops_taken + 1, nbr, new_cost});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};