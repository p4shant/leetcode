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

        vector<int> small,large;

        ListNode *ptr=head;

        while(ptr!=NULL){

            if(ptr->val<x)
            small.push_back(ptr->val);
            else
            large.push_back(ptr->val);

            ptr=ptr->next;

        }

        ListNode *head2=NULL;
        ptr=head2;
        
        for(auto &it:small){

            ListNode *tmp=new ListNode();
            tmp->val=it;
            tmp->next=NULL;

            if(head2==NULL){
                head2=tmp;
                ptr=tmp;
            }
            else{
                ptr->next=tmp;
                ptr=ptr->next;
            }
        }

        for(auto &it:large){
            ListNode *tmp=new ListNode();
            tmp->val=it;
            tmp->next=NULL;

            if(head2==NULL){
                head2=tmp;
                ptr=tmp;
            }
            else{
                ptr->next=tmp;
                 ptr=ptr->next;
            }
        }

        return head2;
    }
};