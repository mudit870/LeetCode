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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>mq;
        if(root==nullptr) return 0;
        int ans=0;
        mq.push({root,1});
        while(!mq.empty()){
            int left=mq.front().second;
            int right=mq.back().second;
            int size=mq.size();
            while(size--){
                TreeNode* temp=mq.front().first;
                long long int n=mq.front().second-left;//2*n overflow ho rha hai, dry run karke smajh lio khud
                mq.pop();
                if(temp->left){
                    mq.push({temp->left,2*n});
                }
                if(temp->right){
                    mq.push({temp->right,(2*n)+1});
                }
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};