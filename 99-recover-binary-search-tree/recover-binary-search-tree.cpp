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
    void recoverTree(TreeNode* root) {
        TreeNode* curr=root;
        TreeNode* prev=nullptr;
        TreeNode* first=nullptr;
        TreeNode* second=nullptr;

        while(curr!=nullptr){
            if(curr->left==nullptr){
                if(prev && prev->val > curr->val){
                    if(!first){
                        first=prev;
                    }
                    second=curr;
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
                else{
                    ip->right=nullptr;

                    if(prev && prev->val > curr->val){
                        if(!first){
                            first=prev;
                        }
                        second=curr;
                    }

                    prev=curr;
                    curr=curr->right;
                }
            }
        }

        if(first && second){
            swap(first->val, second->val);
        }
    }
};