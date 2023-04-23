class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        stack<pair<int,int>> stk;
        int n=temperatures.size();
        for(int i=n-1;i>=0;i--){
            if(stk.empty())
                ans.push_back(0);
            else{
                if(stk.top().first>temperatures[i])
                    ans.push_back(1);
                else{
                    while(stk.size()>0&&stk.top().first<=temperatures[i])
                        stk.pop();
                    if(stk.empty())
                        ans.push_back(0);
                    else
                        ans.push_back(stk.top().second-i);
                }
            }
            stk.push({temperatures[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};