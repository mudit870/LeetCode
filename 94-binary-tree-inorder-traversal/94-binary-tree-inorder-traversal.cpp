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
    void addLeftSubtree(TreeNode* temp, stack<TreeNode*>&st){
        st.push(temp);
        while(temp->left){
            st.push(temp->left);
            temp=temp->left;
        }
        return;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*> st;
        if(root==nullptr)
            return ans;
        addLeftSubtree(root,st); // push all the left child of the root
        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            
            if(temp->right) // if right exists push right root and all left roots of right root
                addLeftSubtree(temp->right,st);
        }
        return ans;
    }
};