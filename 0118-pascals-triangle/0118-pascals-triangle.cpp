class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tri(numRows);

        for(int n=1; n<=numRows; n++){
            tri[n-1].resize(n);

            tri[n-1][0] = 1;
            tri[n-1][n-1] = 1;

            if(n>2){
                for(int i=0, j=1; i+1 < n-1; i++, j++){
                    tri[n-1][j] = tri[n-2][i] + tri[n-2][i+1];
                }
            }    
        }
        return tri;
    }
};