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
    int solve(TreeNode* root, vector<int>& curr){
        if(!root) return 0;
        int ans = 0;
        for(int x : curr){
            ans = max(ans, abs(root->val - x)); //curr node ka ancestor ka diff
        }

        curr.push_back(root->val);

        ans = max(ans, solve(root->left, curr));
        ans = max(ans, solve(root->right, curr));
        curr.pop_back(); // backtracking

        return ans;
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        vector<int> curr;
        return solve(root, curr);
    }
};