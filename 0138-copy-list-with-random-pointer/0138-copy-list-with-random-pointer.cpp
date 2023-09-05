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

        unordered_map<Node* ,Node*> ump;

        if(head==NULL)
        return NULL;

        Node* newnode = new Node(head->val);

        Node* ptr=head;
        Node* head2=newnode;
        Node* ptr2=head2;

        ump[head]=head2;

        if(ptr!=NULL)
        ptr=ptr->next;


        while(ptr!=NULL){
            cout<<1<<endl;
            Node* newnode=new Node(ptr->val);
            newnode->next=NULL;

            ptr2->next=newnode;
            ptr2=ptr2->next;

            ump[ptr]=ptr2;

            ptr=ptr->next;

        }

        ptr=head;
        ptr2=head2;

        while(ptr!=NULL){
            
            ptr2->random=ump[ptr->random];
            ptr=ptr->next;
            ptr2=ptr2->next;

        }

        return head2;
    }
};