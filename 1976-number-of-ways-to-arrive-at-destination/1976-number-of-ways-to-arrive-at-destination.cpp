class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0; i<roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int time = roads[i][2];

            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            long long d = it.first;
            int node = it.second;
            
            if(d > dist[node]) continue;

            for(auto nbr : adj[node]){
                int adjNode = nbr.first;
                int wt = nbr.second;

                if(wt + d < dist[adjNode]){
                    dist[adjNode] = wt + d;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                else if(d + wt == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};