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

    int maxDepth(TreeNode* root) {

        if (root == nullptr) return 0;

        int depth = max(traverse(root->left, 1), traverse(root->right, 1));
        

        return depth;
    }

    int traverse(TreeNode* root, int depth)
    {
        if (root == nullptr) return depth;

        depth++;
        
        int maxDepth = max(traverse(root->left, depth), traverse(root->right, depth));
        
        return maxDepth;
    }
};
