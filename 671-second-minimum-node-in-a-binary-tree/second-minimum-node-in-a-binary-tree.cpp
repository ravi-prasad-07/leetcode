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

    void solve(TreeNode* root, long long& small, long long& ans){
        if(root==nullptr){
            return;
        }

        if(root->val<small){
            ans=small;
            small=root->val;
        }
        else if(root->val>small && root->val<ans){
            ans=root->val;
        }

        solve(root->left, small, ans);
        solve(root->right, small, ans);
    }

    int findSecondMinimumValue(TreeNode* root) {
        long long small=LLONG_MAX;        
        long long ans=LLONG_MAX;
        solve(root, small, ans);

        return ans==LLONG_MAX ? -1:ans;
    }
};