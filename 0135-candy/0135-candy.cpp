class Solution {
public:
    int candy(vector<int> nums) {

        int n=nums.size();
        long long int sex=0;
        vector<int> ans(n,1);
        vector<int> dec(n,1);

        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1])
            dec[i]=dec[i+1]+1;
        }
        ans[0]=dec[0];
        sex+=ans[0];
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                ans[i]=max(ans[i-1]+1,dec[i]);
            }
            else
            ans[i]=max(dec[i],ans[i]);
            sex+=ans[i];
        }
        return sex;
    }
};