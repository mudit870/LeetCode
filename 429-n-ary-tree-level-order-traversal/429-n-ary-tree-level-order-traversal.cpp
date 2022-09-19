/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        queue<Node*>mq;
        if(root==nullptr)return ans;
        mq.push(root);
        while(!mq.empty()){
            int size=mq.size();
            vector<int>temp;
            while(size--){
                Node* p=mq.front();
                mq.pop();
                temp.push_back(p->val);
                for(Node* curr: p->children){
                    mq.push(curr);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};