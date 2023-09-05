class Solution {
public:

    void fn(vector<vector<int>>& ans, vector<int> tmp, vector<int>& candidates, long long int sum, int target, int start){

        if(sum==target){
            ans.push_back(tmp);
        }
        if(sum>target){
            return;
        }

        for(int i=start;i<candidates.size();i++){

            if(i!=start&&candidates[i]==candidates[i-1])continue;
            sum+=candidates[i];
            tmp.push_back(candidates[i]);
            fn(ans,tmp,candidates,sum,target,i+1);
            sum=sum-tmp.back();
            tmp.pop_back();

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        vector<int> tmp;
        vector<vector<int>> ans;
        fn(ans,tmp,candidates,0,target,0);
        return ans;

    }
};