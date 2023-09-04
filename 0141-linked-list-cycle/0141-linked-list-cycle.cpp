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
    bool hasCycle(ListNode *head) {

        ListNode *ptr=head;
        ListNode *sex=head;

        while( ptr!=NULL && sex!=NULL ){

            if( sex->next!=NULL && ptr->next!=NULL && ptr->next->next!=NULL  ){

                ptr=ptr->next->next;
                sex=sex->next;

            }
            else
            return false;

            if(sex==ptr)
            return true;

        }

        return false;

    }
};