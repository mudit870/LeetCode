/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=1;
        int len2=1;
        ListNode *A=headA,*B=headB;
        //find length of headA
        while(A->next){
            len1++;
            A=A->next;
        }
        //find length of headB
        while(B->next){
            len2++;
            B=B->next;
        }
        if(A!=B)
            return nullptr;
        if(len1>len2){
            int len=len1-len2;
            while(len--){
                headA=headA->next;
            }
        }else if(len2>len1){
            int len=len2-len1;
            while(len--){
                headB=headB->next;
            }
        }
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};