class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto &it:stones)
            pq.push(it);
        while(pq.size()>1){
            int tmp=pq.top();
            pq.pop();
            int tmp2=pq.top();
            pq.pop();
            if(tmp!=tmp2)
                pq.push(abs(tmp2-tmp));
        }
        if(pq.size()==1)
        return pq.top();
        else
        return 0;
    }
};