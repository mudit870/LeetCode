/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
        queue<Node*>mq;
        mq.push(root);
        while(!mq.empty()){
            int n=mq.size();
            while(n--){
                Node* temp=mq.front();
                mq.pop();
                if(n>0)temp->next=mq.front(); //except the last node at each level, all node
                                             //next should point to right node of it
                if(temp->left)mq.push(temp->left);
                if(temp->right)mq.push(temp->right);
            }
        }
        return root;
    }
};