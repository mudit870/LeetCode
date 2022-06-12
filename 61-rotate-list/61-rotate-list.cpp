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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr || k==0)
            return head;
        ListNode* dummy=head;
        int len=1;
        // //moving dummy to last node and count length
        while(dummy->next!=nullptr){
            len++;
            dummy=dummy->next;
        }
        // // join last node to first node i.e head
        dummy->next=head;
        k=k%len;
        k=len-k;//last to break point in circular
        while(k--){
            dummy=dummy->next;
        }
        head=dummy->next;
        dummy->next=nullptr;
        return head;
    }
};