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
     TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return NULL;
        if(!root->left && !root->right){
            if(root->val >= low && root->val<=high)
                return root;
            return NULL;
        }
       root->right = trimBST(root->right,low,high);
        root->left = trimBST(root->left,low,high);
        if(root->val < low)
            root = root->right;
        else if(root->val >high)
            root = root->left;
        return root;
    }
};