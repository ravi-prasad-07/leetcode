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
    
    int tellSize(TreeNode* root){
        if(root==nullptr){
            return 0;
        }

        return 1+tellSize(root->left)+tellSize(root->right);
    }

    int getHeight(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }

        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    void dfs(TreeNode* root, vector<vector<string>>& res, int row, int left, int right){
        if(root==nullptr){
            return;
        }

        int mid=left+(right-left)/2;
        res[row][mid]=(to_string(root->val));

        dfs(root->left, res, row+1, left, mid-1);
        dfs(root->right, res, row+1, mid+1, right);
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int h = getHeight(root);
        int w = pow(2, h) - 1;
        vector<vector<string>> res(h, vector<string>(w, ""));

        dfs(root, res, 0, 0, w-1);

        return res;
    }
};