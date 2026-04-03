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

    void traverse(queue<int>& q, TreeNode* root){
        if(root==NULL){
            return;
        }

        q.push(root->val);
        traverse(q, root->left);
        traverse(q, root->right);
    }

    void emptyTree(TreeNode* root){
        if(root==nullptr){
            return;
        }

        emptyTree(root->left);
        emptyTree(root->right);

        delete root;
    }

    void insert(TreeNode* root, queue<int>& q){

        root->val=q.front();
        q.pop();
        root->left=nullptr;

        TreeNode* curr=root;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            curr->right=new TreeNode(node);
            curr->left=nullptr;
            curr=curr->right;
        }

        curr->right=nullptr;
    }

    void flatten(TreeNode* root) {
        if(root==nullptr){
            return;
        }

        queue<int> q;
        traverse(q, root);

        emptyTree(root->left);
        root->left=nullptr;

        emptyTree(root->right);
        root->right=nullptr;

        insert(root, q);
    }
};