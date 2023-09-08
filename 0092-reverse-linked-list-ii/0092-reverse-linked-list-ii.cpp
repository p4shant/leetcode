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

        if(left==right)return head;

        // just before left
        int cnt=0;
        ListNode* node=head;
        while(node){
            ++cnt;
            if( cnt>=left-1){
                break;
            } 
            node=node->next; 
        }

        
        ListNode* thead=node;
        ListNode* ptr=node->next;
        ListNode* tmp=node->next;

        if(left==1){
            ptr=node;
            tmp=node;
        }

        int sex=right-left;

        if(ptr->next)
        ptr=ptr->next;

        while(sex--){
            ListNode* lodu=ptr->next;
            ptr->next=tmp;
            tmp=ptr;
            ptr=lodu;
        }
        if(left!=1){
            thead->next->next=ptr;
            thead->next=tmp;
        }
        else{
            thead->next=ptr;
            head=tmp;
        }
        return head;

    }
};