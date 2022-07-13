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
    bool solve(TreeNode* root, long long mini, long long maxi){
        if(root==nullptr)return true;
        //out of range
        if(root->val<=mini || root->val>=maxi)return false;
        
        bool leftSide=solve(root->left,mini,root->val);
        bool rightSide=solve(root->right,root->val,maxi);
        bool ans =leftSide && rightSide;
        return ans;
    }
    bool isValidBST(TreeNode* root) {
        long long mini=pow(-2,31)-1;
        long long maxi=pow(2,31);
        return solve(root,mini,maxi);
    }
};