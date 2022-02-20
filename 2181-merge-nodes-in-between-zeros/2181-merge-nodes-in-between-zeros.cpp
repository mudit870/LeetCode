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
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        ListNode* he=head;
        he=he->next;
        int sum=0;
        while(he!=nullptr){
            if(he->val!=0){
                sum+=he->val;
                he=he->next;
            }
            else{
                curr->next=new ListNode(sum);
                sum=0;
                he=he->next;
                curr=curr->next;
            }
        }
        return dummy->next;
    }
};