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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *head=NULL,*tmp=NULL;
        
        if(list1==NULL)
            return list2;
        else if(list2==NULL)
            return list1;
        
        if(list1->val <= list2->val)
            head=list1,list1=list1->next;
        else
            head=list2,list2=list2->next;
        
        
        tmp=head;
        
        while(list1 && list2){
            
            if(list1->val > list2->val){
                tmp->next=list2;
                tmp=tmp->next;
                list2=list2->next;
            }
            else{
                tmp->next=list1;
                tmp=tmp->next;
                list1=list1->next;
            }
            
        }
        
        while(list1!=NULL){
            tmp->next=list1;
            tmp=list1;
            list1=list1->next;
        }
        
        while(list2!=NULL){
            tmp->next=list2;
            tmp=list2;
            list2=list2->next;
        }
        return head;
    }
};