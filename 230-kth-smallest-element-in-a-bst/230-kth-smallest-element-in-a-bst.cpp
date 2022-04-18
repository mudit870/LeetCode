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
  //we can traverse tree store value of node after that we can sort the array and return the kth from beginning. It will take O(n) space and time complexity will be O(n)+O(nlogn)i.e traverse+sorting
 //if we do inorder traversal T.C. will be only O(n) as inorder is already sorted for BST
    
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>st;
        TreeNode* node=root;
        int count=0; //we will count node during inorder traversal and increment it if we get a node, as it goes in sorted way so when count==k we will return that node.
        
        while(true){
            if(node!=nullptr){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty())
                    break;
                node=st.top();
                st.pop();
                count++;
                if(count==k)
                    return node->val;
                node=node->right;
            }
        }
        return -1;
    }
};