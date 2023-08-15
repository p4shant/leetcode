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
    ListNode* partition(ListNode* head, int x) {
        ListNode *ptr=head;
        ListNode *tmp=NULL;

        while(ptr!=NULL&&ptr->val!=x&&ptr->val<x){
            if(ptr->val<x){
                tmp=ptr;
            }
            ptr=ptr->next;

        }




        while(ptr!=NULL&&ptr->next!=NULL){

            if(ptr->next->val<x){

                ListNode *t1=ptr->next;
                ptr->next=ptr->next->next;
                
                if(tmp){
                    if(tmp->next!=NULL){
                        t1->next=tmp->next;
                        tmp->next=t1;
                        tmp=tmp->next;
                    }
                    else{
                        t1->next=tmp;
                        head=t1;
                    }
                }
                else{
                    t1->next=head;
                    head=t1;
                    tmp=t1;
                }
            }
            else{
                if(ptr->next!=NULL)
                ptr=ptr->next;
            }

        }

        return head;

    }
};