class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> dist(n , vector<int>(m,-1));

        //Sbhi 0's ko queue me daldo 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        int d1[4] = {-1,1,0,0};
        int d2[4] = {0,0,-1,1};

        while(!q.empty()){
            auto [a,b] = q.front();
            q.pop();

            for(int k=0; k<4; k++){
                int ii = a+d1[k];
                int jj = b+d2[k];
                
                if(ii>=0 && ii<n && jj>=0 && jj<m && dist[ii][jj]==-1){
                    dist[ii][jj] = dist[a][b]+1;
                    q.push({ii,jj});
                }
            }
        }
        return dist;
    }
};