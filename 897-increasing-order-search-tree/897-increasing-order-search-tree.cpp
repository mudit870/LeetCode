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
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* temp = new TreeNode();
        TreeNode* curr = temp;
        while(root || !st.empty()){
            while(root){
                st.push(root);
                root=root->left;
            }
            root=st.top();
            curr->right=root;
            curr=curr->right;
            st.pop();
            root=curr->right; 
            curr->left = nullptr;
        }
        return temp->right;
    }
};