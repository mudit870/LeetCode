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
    
    void solve(TreeNode* root,vector<int>& a){
        if(root==nullptr)return;
        if(root->left==nullptr && root->right==nullptr)a.push_back(root->val);
        solve(root->left,a);
        solve(root->right,a);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>a1;
        vector<int>a2;
        solve(root1,a1);
        solve(root2,a2);
        int n=a1.size();
        int m=a2.size();
        if(n!=m)return false;
        for(int i=0;i<n;i++){
            if(a1[i]!=a2[i])return false;
        }
        return true;
    }
};