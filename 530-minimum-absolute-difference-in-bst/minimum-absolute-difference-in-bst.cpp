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
    int getMinimumDifference(TreeNode* root) {
        TreeNode* curr=root;
        TreeNode* prev=nullptr;
        int diff=INT_MAX;
        
        while(curr!=nullptr){
            if(curr->left==nullptr){

                if(prev!=nullptr){
                    diff=min(diff,abs(curr->val - prev->val));
                }
                prev=curr;

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

                    if(prev!=nullptr){
                        diff=min(diff,abs(curr->val - prev->val));
                    }
                    prev=curr;

                    curr=curr->right;
                }
            }
        }

        return diff;
    }
};