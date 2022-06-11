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
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return true;
        ListNode*slow=head,*fast=head;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=nullptr,*curr=slow,*forw;
        while(curr){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        curr=prev; // now curr is at last of reversed right side
        //head will be start of left side
        while(curr){
            if(curr->val==head->val){
                curr=curr->next;
                head=head->next;
            }else{
                return false;
            }
        }
        return true;
    }
};