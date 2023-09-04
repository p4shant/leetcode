class Solution {
public:
    
    void fn( vector<vector<int>> &ans, vector<int> tmp, vector<int> &nums, int start){

        ans.push_back(tmp);

        for(int i=start;i<nums.size();i++){

            tmp.push_back(nums[i]);
            fn(ans,tmp,nums,i+1);
            tmp.pop_back();

        }

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> tmp;
        fn(ans,tmp,nums,0);

        return ans;

    }
};