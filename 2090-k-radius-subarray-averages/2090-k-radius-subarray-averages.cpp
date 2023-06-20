class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        //finding the prefix sum of array
        vector<long long int> prfx(n);
        prfx[0]=nums[0];
        for(int i=1;i<n;i++)
            prfx[i]=prfx[i-1]+nums[i];
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(i-k>0&&i+k<n){
                ans[i]=(prfx[i+k]-prfx[i-k-1])/(2*k+1);
            }
            else if(i-k==0&&i+k<n){
                ans[i]=(prfx[i+k])/(2*k+1);
            }
            else
                ans[i]=-1;
        }
        return ans;
    }
};