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
    int ans=0;
    int checkBalance(TreeNode* root){
        if(root==nullptr)return 0;
        int left=checkBalance(root->left);
        int right=checkBalance(root->right);
        if(abs(left-right)>1)ans=1;
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)return true;
        checkBalance(root);
        if(ans==1)return false;
        return true;
    }
};