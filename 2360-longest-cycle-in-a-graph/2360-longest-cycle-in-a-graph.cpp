class Solution {
public:
    int longCycLen = -1;
    void dfsFindLongCycLen(int cycLen , int node , vector<int> &visited , vector<int> &curr_path , vector<int> &edges){
        visited[node]=1;

        cycLen++;
        curr_path[node]=cycLen;

        int nbr = edges[node];
        if(nbr != -1){
            if(!visited[nbr]){
                dfsFindLongCycLen(cycLen , nbr , visited , curr_path , edges);
            }
            else{
                if(curr_path[nbr]!=0){
                    int currCycLen = curr_path[node] - curr_path[nbr] + 1;
                    longCycLen = max(longCycLen , currCycLen);
                }
            }
        }
        curr_path[node]=0;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n,0);
        vector<int> curr_path(n,0);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfsFindLongCycLen(0, i , visited , curr_path, edges);
            }
        }
        return longCycLen;
    }
};