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
     int findDiameter(TreeNode* root){
        if(root==nullptr)return 0;
        int leftValue=findDiameter(root->left);
        int rightValue=findDiameter(root->right);
        ans=max(ans,leftValue+rightValue);
        return 1+max(leftValue,rightValue);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)return 0;
        findDiameter(root);
        return ans;
    }
};