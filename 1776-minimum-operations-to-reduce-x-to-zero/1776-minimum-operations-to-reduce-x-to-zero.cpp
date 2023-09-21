class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long int sum=0;
        for(auto &it:nums)sum+=it;
        sum-=x;
        if(sum<0)
        return -1;
        int n=nums.size(),cnt=INT_MAX,i=0,j=0,tmp=0;
        while(j<n&&i<n){
            tmp+=nums[j];
            if(tmp>=sum){
                while(tmp>sum){
                    tmp-=nums[i];
                    ++i;
                }
                if(tmp==sum){
                    cout<<tmp<<" ";
                    cnt=min(cnt,n-(j-i+1));
                    if(i<n)
                    tmp-=nums[i];
                    ++i;
                }
            }
            ++j;
        }
        if(cnt==INT_MAX)
        return -1;
        else
        return cnt;
    }
};