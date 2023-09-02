class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n=nums.size();

        if(n==1)
        return 0;

        int cnt=0,tmp=0,mx=0;
        
        for(int i=0;i<n;i++){

            mx=max(mx,i+nums[i]);

            if(i==tmp){
                tmp=mx;
                ++cnt;
            }

            if(tmp>=n-1)
            return cnt;

            cout<<i<<" "<<tmp<<" "<<mx<<" "<<cnt<<endl;

        }

        return cnt;
    }
};