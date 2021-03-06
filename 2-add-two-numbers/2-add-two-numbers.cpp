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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy= new ListNode();
        ListNode *temp=dummy;
        int carry=0;
        while(l1!=0 || l2!=0 || carry){
            int sum=0;
            if(l1!=0){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=0){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode *node=new ListNode(sum%10); //create new node contain sum val
            temp->next=node;
            temp=temp->next;
        }
        return dummy->next;
    }
};