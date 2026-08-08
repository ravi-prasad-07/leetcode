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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr){
            return {};
        }

        deque<TreeNode*> q;
        q.push_back(root);
        int ind=-1;
        vector<vector<int>> ans;

        while(!q.empty()){
            int n=q.size();
            vector<int> temp;
            ind++;

            while(n--){
                if(ind%2==0){
                    TreeNode* root=q.front();
                    temp.push_back(root->val);
                    q.pop_front();
                    
                    if(root->left){
                        q.push_back(root->left);
                    }
                    if(root->right){
                        q.push_back(root->right);
                    }

                }
                else{
                    TreeNode* root=q.back();
                    temp.push_back(root->val);
                    q.pop_back();

                    
                    if(root->right){
                        q.push_front(root->right);
                    }
                    if(root->left){
                        q.push_front(root->left);
                    }

                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};