class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        set<vector<int>> st;
        vector<vector<int>> ans;

        int n=nums.size();
        for(int i=0;i<pow(2,n);i++){

            vector<int> tmp;
            for(int j=0;j<n;j++){
                if((i&(1<<j))==0)
                tmp.push_back(nums[j]);
            }
            if(st.count(tmp)==0){
                ans.push_back(tmp);
                st.insert(tmp);
            }

        }
        return ans;
    }
};