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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>mq;
        if(root==nullptr)return ans;
        mq.push(root);
        int a=0;
        while(!mq.empty()){
            int size=mq.size();
            vector<int>temp;
            while(size--){
                TreeNode* t=mq.front();
                mq.pop();
                temp.push_back(t->val);
                if(t->left)
                    mq.push(t->left);
                if(t->right)
                    mq.push(t->right);
            }
            if(a%2!=0){
                reverse(temp.begin(),temp.end());
            }
            ans.push_back(temp);
            a++;
        }
        return ans;
    }
};