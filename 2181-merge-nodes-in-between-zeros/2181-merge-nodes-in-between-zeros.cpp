/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* zero=head;
        ListNode* curr=head->next;
        while(curr!=nullptr){
            if(curr->val != 0){
                zero->val += curr->val;
            }
            else{
                //for last zero
                if(curr->next==nullptr){
                    zero->next=nullptr;
                }
                else{
                    zero->next=curr;
                }
                zero=curr;//now again we sum to this zero node
            }
            curr=curr->next;
        }
        return head;
    }
};