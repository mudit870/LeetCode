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
        ListNode *slow=head,*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *prev=nullptr, *curr=slow, *forw;
        while(curr!=nullptr){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        curr=prev;
        while(curr){
            if(curr->val==head->val){
                curr=curr->next;
                head=head->next;
            }
            else 
                return false;
        }
        return true;
    }
};