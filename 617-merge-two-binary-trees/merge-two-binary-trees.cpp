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

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        //Here I used DFS to solve this question

        if(root1==nullptr){
            return root2;
        }
        if(root2==nullptr){
            return root1;
        }
        /*

        root1->val+=root2->val;

        root1->left=mergeTrees(root1->left, root2->left);
        root1->right=mergeTrees(root1->right, root2->right);

        return root1;
        */

        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root1, root2});

        while(!q.empty()){
            TreeNode* r1=q.front().first;
            TreeNode* r2=q.front().second;
            q.pop();

            r1->val+=r2->val;

            if(r1->left && r2->left){
                q.push({r1->left, r2->left});
            }
            else if(!r1->left && r2->left){
                r1->left=r2->left;
            }

            if(r1->right && r2->right){
                q.push({r1->right, r2->right});
            }
            else if(!r1->right && r2->right){
                r1->right=r2->right;
            }

        }

        return root1;
    }
};