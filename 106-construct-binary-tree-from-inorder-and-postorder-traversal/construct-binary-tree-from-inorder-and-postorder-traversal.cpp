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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==1){
            TreeNode* root=new TreeNode(postorder[0]);
            return root;
        }

        unordered_map<int, int> hm;
        int n=inorder.size();

        for(int i=0; i<inorder.size(); i++){
            hm[inorder[i]]=i;
        }

        return solve(inorder, 0, n-1, postorder, 0, n-1, hm);
    }

    TreeNode* solve(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, unordered_map<int, int>& hm){
        if(is>ie || ps>pe){
            return nullptr;
        }

        int rootnode=postorder[pe];
        int inroot=hm[rootnode];

        TreeNode* root=new TreeNode(rootnode);

        root->left=solve(inorder, is, inroot-1, postorder, ps, ps+(inroot-is)-1, hm);
        root->right=solve(inorder, inroot+1, ie, postorder, ps+(inroot-is),pe-1, hm);

        return root;
    }
};