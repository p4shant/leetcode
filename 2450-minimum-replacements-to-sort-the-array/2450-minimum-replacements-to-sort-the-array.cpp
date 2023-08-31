class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        
        long long int n=nums.size(),cnt=0;
        long long int mx=nums[n-1];

        for(int i=n-2;i>=0;i--){

            if(nums[i]>mx){
                
                int tmp=ceil(nums[i]/double(mx));
                cnt+=tmp-1;
                mx=nums[i]/tmp;

            }
            else{
                mx=nums[i];
            }

            cout<<mx<<" "<<cnt<<endl;
        }

        return cnt;
    }
};