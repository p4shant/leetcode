class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        int tmp=0,mx=0;
        if(n==1)
        return true;

        for(int i=0;i<n-1;i++){
            mx=max(mx,nums[i]+i);

            if(i==tmp)
            tmp=mx;

            if(tmp>=n-1)
            return 1;

        }

        return 0;
    }
};