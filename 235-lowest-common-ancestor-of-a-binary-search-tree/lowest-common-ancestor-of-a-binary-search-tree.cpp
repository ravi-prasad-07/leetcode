/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : vaintl(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr || root==p || root==q){
            return root;
        }

        TreeNode* leftn=solve(root->left, p, q);
        TreeNode* rightn=solve(root->right, p, q);

        if(leftn && rightn){
            return root;
        }

        if(leftn){
            return leftn;
        }

        return rightn;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {;
        return solve(root, p, q);
    }
};