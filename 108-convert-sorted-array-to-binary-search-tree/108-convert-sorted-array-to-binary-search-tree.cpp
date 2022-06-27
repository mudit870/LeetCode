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
    TreeNode* construct(vector<int>& nums,int low, int high){
        if(low>high)return nullptr;
        int mid=low+(high-low)/2;
        
        TreeNode* curr=new TreeNode(nums[mid]);
        curr->left=construct(nums,low,mid-1);
        curr->right=construct(nums,mid+1,high);
        return curr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)return nullptr;
        return construct(nums,0,nums.size()-1);
    }
};