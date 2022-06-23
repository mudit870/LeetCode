class Solution {
public:
    vector<int>ans;
    void inorder(TreeNode* root){
        if(root==nullptr)return;
        
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
};