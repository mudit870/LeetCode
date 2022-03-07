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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        if(l1->val>l2->val) swap(l1,l2); //l1 choti value par aayega
        ListNode *ans=l1;
        while(l1 && l2){
            ListNode*tmp=nullptr;
            while(l1 && l1->val<=l2->val){
                tmp=l1;
                l1=l1->next;
            }
            tmp->next=l2;
            swap(l1,l2);
        }
        return ans;
    }
};