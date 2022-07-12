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
    ListNode* merge(ListNode* l, ListNode* h){
        ListNode* dummy=new ListNode(0);
        ListNode* ans=dummy;
        while(l!=nullptr && h!=nullptr){
            if(l->val<h->val){
                dummy->next=l;
                l=l->next;
            }else{
                dummy->next=h;
                h=h->next;
            }
            dummy=dummy->next;
        }
        if(l)dummy->next=l;
        if(h)dummy->next=h;
        return ans->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return nullptr;
        ListNode* temp=lists[0];
        for(int i=1;i<lists.size();i++){
            temp=merge(lists[i],temp);
        }
        return temp;
    }
};