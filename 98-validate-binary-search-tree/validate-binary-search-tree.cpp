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

    bool recurssion(TreeNode* root, long minVal, long maxVal){
        if(root==NULL){
            return true;
        }

        if(root->val<=minVal || root->val>=maxVal){
            return false;
        }

        return recurssion(root->right, root->val, maxVal) && recurssion(root->left, minVal, root->val);
    }

    bool isValidBST(TreeNode* root) {
        return recurssion(root,LONG_MIN, LONG_MAX);
    }
};