/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void buildString(TreeNode* root, string &res){
        if(root == NULL){   
            res += "null,";
            return;
        }
        res += to_string(root->val) + ",";
        buildString(root->left, res);
        buildString(root->right, res);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) { 
        string res = "";
        buildString(root, res);
        // cout<<res<<endl;
        return res;
    }
    TreeNode* buildTree(queue<string> &q) {
        string s = q.front();
        q.pop();
        
        if(s == "null")
            return NULL;
        
        TreeNode* root = new TreeNode(stoi(s));
        root->left = buildTree(q);
        root->right = buildTree(q);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string s = "";
        queue <string> q;
        
        for(char c: data){
            if(c == ',') {
                q.push(s);
                // cout<<s<<endl;
                s = "";
            }else
                s += c;
        }
        
        return buildTree(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));