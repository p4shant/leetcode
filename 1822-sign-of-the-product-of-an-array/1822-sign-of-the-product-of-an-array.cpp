class Solution {
public:
    int arraySign(vector<int>& nums) {
        int odd=0;
        for(auto it:nums){
            if(it==0)
                return 0;
            else if(it<0)
                odd++;
        }
        if(odd&1)
            return -1;
        else
            return 1;
    }
};