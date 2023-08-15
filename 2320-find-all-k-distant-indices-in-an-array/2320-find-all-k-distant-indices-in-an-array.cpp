class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        
        queue<pair<int,int>> q;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
                q.push({nums[i],i});
            }
        }

        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            
            int x=q.front().second;

            if(i-x>k){
                q.pop();
                if(q.empty())
                break;
                
                x=q.front().second;
            }

            if(abs(i-x)<=k)
            ans.push_back(i);
        }

        return ans;
    }
};