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
    int solve(TreeNode* root, int curr){
        if(root == NULL){
            return 0;
        }


        curr = curr * 10 + root->val;

        if(root->left == NULL && root->right == NULL){
            return curr;
        }

        return solve(root->left, curr) + solve(root->right, curr);
    }

    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};