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

    // find the mistake
    // int max=0;
    // TreeNode* convertBST(TreeNode* root) {
    //     if(!root) return nullptr;
    //     TreeNode* curr=root;
    //     stack<TreeNode*> ms;
    //     while(!ms.empty() || curr!=nullptr){
    //         while(curr!=nullptr){
    //             ms.push(curr);
    //             curr=curr->right;
    //         }
    //         TreeNode curr=ms.pop();
    //         max+=curr->val;
    //         curr->val=max;
    //         curr=curr->left;
    //     }
    //     return root;
class Solution {
public:
    int max=0;
    TreeNode* successor(TreeNode*curr){
        TreeNode* succ= curr->right;
        while(succ->left!=nullptr && succ->left!=curr)
            succ=succ->left;
        return succ;
    }
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* curr= root;
        while(curr){
            if(curr->right==nullptr){
                max+=curr->val;
                curr->val=max;
                curr=curr->left;
            }
            else{
                TreeNode* succ = successor(curr);
                if(succ->left==nullptr){
                    succ->left=curr;
                    curr=curr->right;
                }
                else{
                    succ->left=nullptr;
                    max+=curr->val;
                    curr->val=max;
                    curr=curr->left;
                }
            }
        }
        return root;
    }
};