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

    bool leaf(TreeNode* root, vector<int>& ans, int& i) {
        if (root == nullptr) {
            return true;
        }

        // Current node is a leaf
        if (root->left == nullptr && root->right == nullptr) {

            // No corresponding leaf or values don't match
            if (i >= ans.size() || ans[i] != root->val) {
                return false;
            }

            i++;
            return true;
        }

        return leaf(root->left, ans, i) &&
               leaf(root->right, ans, i);
    }

    void solve(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) {
            return;
        }

        // Store leaf value
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(root->val);
        }

        solve(root->left, ans);
        solve(root->right, ans);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;

        // Store leaf sequence of root1
        solve(root1, ans);

        int i = 0;

        // Compare leaf sequence of root2
        if (!leaf(root2, ans, i)) {
            return false;
        }

        // Make sure root2 has no extra leaves
        return i == ans.size();
    }
};
