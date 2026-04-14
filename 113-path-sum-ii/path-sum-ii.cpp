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

    void sol(TreeNode* root, vector<vector<int>>& res, vector<int> help, int tsum, int sum){
        if(root==nullptr){
            return;
        }

        sum+=root->val;
        help.push_back(root->val);

        if(root->left==nullptr && root->right==nullptr){
            if(tsum==sum){
                res.push_back(help);
            }
        }
        else{

            sol(root->left, res, help, tsum, sum);
            sol(root->right, res, help, tsum, sum);

        }

        help.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> help;

        sol(root, res, help, targetSum, 0);
        return res;
    }
};