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
//     1 -> unwatched
// 2 -> watched but no camera
// 3 -> watched with camera
    int camera(TreeNode* root){
        if (root->left==NULL && root->right==NULL){
            root->val=1;
            return 0;
        }
        int res=0,l=2,r=2;
        if (root->left){
            res += camera(root->left);
            l = root->left->val;
        }
        if (root->right){
            res += camera(root->right);
            r = root->right->val;
        }
		// children are unwatched so camera needed
        if (l==1 || r==1){
            root->val = 3;
            return (res+1);
        }
		// camera present
        if (l==3 || r==3){
            root->val = 2;
            return res;
        }
		// current node is unwatched, so it will be watched from its parent node
        root->val=1;
        return res;
    }
    
    int minCameraCover(TreeNode* root) {
        int res = camera(root);
        if (root->val == 1){
            res++;
        }
        return res;
    }
};
// class Solution {
// private:    
//     int ans = 0;
//     int solve(TreeNode* root){
//         if(!root) return 2;
//         int left = solve(root->left);
//         int right = solve(root->right);
//         if(left == 0 or right == 0){
//             ans++;
//             return 1;
//         }
//         return (left == 1 or right == 1) ? 2 : 0;
//     }
// public:
//     int minCameraCover(TreeNode* root) {
//         return (solve(root) < 1 ? 1 : 0) + ans;
//     }
// };
