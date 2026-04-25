/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* curr=cloned;
        TreeNode* temp=nullptr;
        int n=target->val;

        while(curr!=nullptr){
            if(curr->left==nullptr){
                if(curr->val==n){
                    temp=curr;
                }
                curr=curr->right;
            }
            else{
                TreeNode* ip=curr->left;
                while(ip->right!=nullptr && ip->right!=curr){
                    ip=ip->right;
                }

                if(ip->right==nullptr){
                    ip->right=curr;
                    curr=curr->left;
                }
                else if(ip->right==curr){
                    ip->right=nullptr;

                    if(curr->val==n){
                        temp=curr;
                    }

                    curr=curr->right;
                }
            }
        }

        return temp;
    }
};