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
    void flatten(TreeNode* root) {
        if(root == NULL) return;

        // Recursively flatten left and right subtrees
        flatten(root->left);
        flatten(root->right);

        // Store the original right subtree
        TreeNode* temp = root->right;

        // Move left subtree to right and set left to NULL
        root->right = root->left;
        root->left = NULL;

        // Go to the end of the new right subtree
        TreeNode* curr = root;
        while(curr->right != NULL){
            curr = curr->right;
        }

        // Attach the original right subtree at the end
        curr->right = temp;
    }
};

// this question is in 4 steps :
//   preorder traversal 
//   shift left to right 
//   left==null 
//   attach right at the end of left 


