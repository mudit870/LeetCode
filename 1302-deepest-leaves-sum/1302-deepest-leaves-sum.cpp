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
    int deepestLeavesSum(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> mq;
        mq.push(root);
        int ans=0;
        while(!mq.empty()){
            ans=0;
            int n=mq.size();
            for(int i=0;i<n;i++){
                TreeNode*curr = mq.front();
                mq.pop();
                ans+=curr->val;
                if(curr->left)
                    mq.push(curr->left);
                if(curr->right)
                    mq.push(curr->right);
            }
        }
        return ans;
    }
};