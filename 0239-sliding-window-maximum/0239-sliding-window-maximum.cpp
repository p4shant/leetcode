class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int i=0,j=0,n=nums.size();
        map<int,int> mp;

        while(j<n){
            if(j-i+1<k){
                mp[nums[j]]++;
                ++j;
            }
            else{
                mp[nums[j]]++;
                ans.push_back(mp.rbegin()->first);
                mp[nums[i]]--;

                if(mp[nums[i]]==0)
                mp.erase(nums[i]);
                
                ++i;++j;
            }
        }

        return ans;
    }
};