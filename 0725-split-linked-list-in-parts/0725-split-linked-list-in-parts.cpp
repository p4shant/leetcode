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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int cnt=0;
        for(ListNode* node=head;node;node=node->next)
        ++cnt;
        int sex=k;
        while(sex--){
            int sz=cnt/k;
            if(cnt%k!=0)
            ++sz;
            if(cnt==0){
                ans.push_back(NULL);
                continue;
            }
            cnt=cnt-sz;
            k--;
            cout<<cnt<<" ";
            ListNode* thead=head;
            for(int i=1;i<=sz;i++){

                if(i==sz){
                    ListNode* tmp=head->next;
                    head->next=NULL;
                    head=tmp;
                }
                else
                head=head->next;

            }
            ans.push_back(thead);
        }
        return ans;
    }
};