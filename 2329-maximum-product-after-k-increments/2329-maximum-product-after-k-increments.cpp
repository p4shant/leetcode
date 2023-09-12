class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        long long int mod=pow(10,9)+7;
        priority_queue <int, vector<int>, greater<int> > pq;
        for(auto &it:nums)
        pq.push(it);

        while(k--&&!pq.empty()){
            int sex=pq.top()+1;
            pq.pop();
            pq.push(sex);
        }
        long long int ans=1;
        while(!pq.empty()){
            ans=(ans*pq.top())%mod;
            pq.pop();
        }
        return ans;
    }
};