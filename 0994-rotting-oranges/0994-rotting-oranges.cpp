class Solution {
public:
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    int a,b;
    int orangesRotting(vector<vector<int>>& grid) {
        a = grid.size();
        b = grid[0].size();

        int ans=0;
        queue<pair<int,int>> q;
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int size = q.size();
            int temp=0;
            while(size--){
                auto node = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int i=node.first+dx[k] , j=node.second+dy[k];
                    if(i>=0 && j>=0 && i<a && j<b && grid[i][j]==1){
                        grid[i][j]=2;
                        temp=1;
                        q.push({i,j});
                    }
                }
            }
            ans+=temp;
        }
        for(auto v:grid){
            for(int x:v){
                if(x==1) return -1;
            }
        }
        return ans;
    }
};