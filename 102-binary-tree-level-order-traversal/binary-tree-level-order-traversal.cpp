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
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root==nullptr){
            return {};
        }

    //     int n=height(root);

    //     vector<vector<int>> ans(n, vector<int>());

    //     solve(root, 0, ans);
    //     return ans;
    // }

    // int height(TreeNode* root) {
    //     if (root == nullptr) {
    //         return 0;
    //     }

    //     return max(height(root->left), height(root->right)) + 1;
    // }

    // void solve(TreeNode* root, int lvl, vector<vector<int>>& ans){
    //     if(root==nullptr){
    //         return;
    //     }

    //     ans[lvl].push_back(root->val);
    //     solve(root->left, lvl+1, ans);
    //     solve(root->right, lvl+1, ans);
    // }

        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;

        while(!q.empty()){
            int size=q.size();
            vector<int> temp;

            while(size--){
                TreeNode* root=q.front();
                q.pop();

                temp.push_back(root->val);

                if(root->left){
                    q.push(root->left);
                }
                if(root->right){
                    q.push(root->right);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};