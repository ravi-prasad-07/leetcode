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

    int solve(TreeNode* root, int& ans){
        if(root==nullptr){
            return 0;
        }

        int left=solve(root->left, ans);
        int right=solve(root->right, ans);

        ans+=abs(left-right);

        return root->val+left+right;
    }

    int findTilt(TreeNode* root) {
        int ans=0;
        solve(root, ans);

        return ans;
    }
};