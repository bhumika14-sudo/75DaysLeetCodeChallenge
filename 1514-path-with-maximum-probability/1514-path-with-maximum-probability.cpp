class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];

            adj[u].push_back({v,prob});
            adj[v].push_back({u, prob});
        }

        vector<double> dist(n, 0.0);
        dist[start_node] = 1.0;
        priority_queue<pair<double,int>> pq;
        pq.push({1.0, start_node});
    
        while(!pq.empty()){
            auto it = pq.top();

            double prob = it.first;
            int node = it.second;
            pq.pop();

            if(node == end_node){
                return prob;
            }

            if(prob < dist[node]) continue;

            for(auto nbr : adj[node]){
                int adjNode = nbr.first;
                double edgeProb = nbr.second;

                double newProb = prob * edgeProb;

                if(newProb > dist[adjNode]){
                    dist[adjNode] = newProb;
                    pq.push({newProb, adjNode});
                }
            }
        }
        return 0.0;
    }
};