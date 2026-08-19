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

    int best=INT_MIN;

    int solve(TreeNode* root){
        if(root==nullptr){
            return 0;
        }

        int leftGain=max(solve(root->left), 0);
        int rightGain=max(solve(root->right), 0);

        int pathsum=root->val + leftGain + rightGain;
        best=max(best, pathsum);

        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return best;
    }
};