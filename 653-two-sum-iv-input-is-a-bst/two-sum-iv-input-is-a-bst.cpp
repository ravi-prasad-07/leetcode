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

    bool findTarget(TreeNode* root, int k) {
        if(root==nullptr){
            return false;
        }
        vector<int> res;
        
        TreeNode* curr=root;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                res.push_back(curr->val);
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
                    res.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }

        int i=0,j=res.size()-1;
        while(i<j){
            int sum=res[i]+res[j];

            if(sum==k){
                return true;
            }
            else if(sum<k){
                i++;
            }
            else{
                j--;
            }
        }

        return false;
    }
};