/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    void solve(vector<int>& ans, Node* root){
        if(root==nullptr){
            return;
        }

        int n=root->children.size();
        for(int i=0; i<n; i++){
            solve(ans, root->children[i]);
        }

        ans.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> ans;
        solve(ans, root);

        return ans;
    }
};
