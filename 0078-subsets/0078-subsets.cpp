class Solution {
public:
    
    void fn( vector<vector<int>> &ans, vector<int> tmp, vector<int> nums){

        if(nums.size()==0){
            ans.push_back(tmp);
            return;   
        }

        int sex=nums[0];
        nums.erase(nums.begin());

        fn(ans,tmp,nums);

        tmp.push_back(sex);

        fn(ans,tmp,nums);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> tmp;
        fn(ans,tmp,nums);

        return ans;

    }
};