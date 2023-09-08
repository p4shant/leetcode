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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(left==right||head==NULL)return head;

        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* pre=dummy;
        for(int i=0;i<left-1;i++)pre=pre->next;
        ListNode* ptr=pre->next;
        for(int i=0;i<right-left;i++){
            ListNode* nxt=ptr->next;
            ptr->next=nxt->next;
            nxt->next=pre->next;
            pre->next=nxt;
        }
        return dummy->next;
    }
};