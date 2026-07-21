class Solution {
public:
    bool solve(vector<vector<char>>& board, string& word, int i, int j, int k){
        int n = board.size();
        int m = board[0].size();

        if(k == word.size()) return true;

        if(i<0 || j<0 || i>=n || j>=m) return false;

        if(board[i][j] != word[k]) return false;

        char ch = board[i][j];
        board[i][j] = '*';

        bool ans = solve(board, word, i + 1, j, k + 1) || solve(board, word, i - 1, j, k + 1) || solve(board, word, i, j + 1, k + 1) || solve(board, word, i, j - 1, k + 1);

        //backtrack 
        board[i][j] = ch;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (solve(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};