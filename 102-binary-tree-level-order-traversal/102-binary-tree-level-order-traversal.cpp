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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>mq;
        vector<vector<int>>ans;
        if(root==nullptr)return ans;
        mq.push(root);
        while(!mq.empty()){
            int size=mq.size();
            vector<int> res;
            while(size--){
                TreeNode* temp=mq.front();
                mq.pop();
                res.push_back(temp->val);
                if(temp->left)mq.push(temp->left);
                if(temp->right)mq.push(temp->right);
            }
            ans.push_back(res);
        }
        return ans;
    }
};