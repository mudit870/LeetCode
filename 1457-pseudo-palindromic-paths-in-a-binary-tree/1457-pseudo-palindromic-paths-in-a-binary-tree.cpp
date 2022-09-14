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
private:
    int solve(TreeNode* root,unordered_set<int> &st){
        if(!root){return 0;}
        
        if(!root->left and !root->right) {
            if(st.count(root->val)) return (st.size()-1) < 2;
            return st.size()+1 < 2;
        }
        
        bool f = false;
        
        if(st.count(root->val)) f = true, st.erase(root->val);
        else st.insert(root->val);
        
        int l = solve(root->left,st);
        int r = solve(root->right,st);
        
        if(f) st.insert(root->val);
        else st.erase(root->val);
        
        return l+r;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_set<int> st;
        return solve(root,st);
    }
};