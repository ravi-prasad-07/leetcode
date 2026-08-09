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

    void solve(TreeNode* root, long long sum, int& ans){
        if(root==nullptr){
            return;
        }
        if(sum==root->val){
            ans++;
        }

        solve(root->left, sum-root->val, ans);
        solve(root->right, sum-root->val, ans);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr){
            return 0;
        }

        int ans=0;

        solve(root, targetSum, ans);
        
        ans+=pathSum(root->left, targetSum);
        ans+=pathSum(root->right, targetSum);

        return ans;
    }
};