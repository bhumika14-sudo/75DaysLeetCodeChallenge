/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int row, int col, map<int, map<int, multiset<int>>>& mp){
        if(!root) return;
        mp[col][row].insert(root->val);
        solve(root->left, row+1, col-1, mp);
        solve(root->right, row+1, col+1, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        map<int, map<int, multiset<int>>> mp;
        solve(root, 0, 0, mp);  
        vector<vector<int>> ans;

        for(auto it : mp){
            vector<int> temp;
            for(auto row : it.second){
                for(int val : row.second){
                    temp.push_back(val);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};