/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head==NULL)
        return NULL;
        
        map<Node*,int> ump;
        map<int,Node*> ump2;

        int i=1;

        Node *node=new Node(-1);
        Node *head2=node , *ptr=head ;
        Node *ptr2=head2;

        ptr2->val=ptr->val;
        ptr2->next=NULL;

        ump2[i]=ptr2;
        ump[ptr]=i;

        ++i;
        
        if(ptr!=NULL)
        ptr=ptr->next;

        while(ptr!=NULL){

            Node *node=new Node(ptr->val);
            node->next=NULL;

            ptr2->next=node;
            ptr2=ptr2->next;

            ump2[i]=ptr2;
            ump[ptr]=i;
            ++i;

            ptr=ptr->next;

        }

        ptr=head;
        ptr2=head2;

        while(ptr!=NULL){
            ptr2->random=ump2[ump[ptr->random]];
            ptr=ptr->next;
            ptr2=ptr2->next;
        }
        
        return head2;

    }
};