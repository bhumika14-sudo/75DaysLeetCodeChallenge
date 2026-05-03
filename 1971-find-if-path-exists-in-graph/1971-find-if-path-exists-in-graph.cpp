class Solution {
public:
    void dfshelper(int node , vector<vector<int>> &adj, vector<int> &ans , vector<bool> &visited){
        visited[node] = true;
        ans.push_back(node);

        for(auto neighbor : adj[node]){
            if(!visited[neighbor]){
                dfshelper(neighbor , adj , ans , visited);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int src , int par) {
        int V = n;

        // make adjacency list out of edges 
        vector<vector<int>> adj(V);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(V,false);
        vector<int> ans;

        dfshelper(src , adj , ans , visited);

        return visited[par];
    }
};