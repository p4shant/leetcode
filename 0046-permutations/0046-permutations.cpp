class Solution {
public:

    void fn(vector<vector<int>>& ans, vector<int> tmp, vector<int>&nums){

        if(tmp.size()==nums.size()){
            ans.push_back(tmp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            
            if(std::find(tmp.begin(), tmp.end(), nums[i]) != tmp.end()) continue;
            tmp.push_back(nums[i]);
            fn(ans,tmp,nums);
            tmp.pop_back();

        }

    }
        
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> tmp;

        fn(ans,tmp,nums);
        return ans;
        
    }
};