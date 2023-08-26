class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());

        vector<pair<int,int>> tmp;
        int s=1001,e=1001;        
        for(int i=n-1;i>=0;i--){
            if(pairs[i][1]<s){
                tmp.push_back({pairs[i][0],pairs[i][1]});
                s=pairs[i][0];e=pairs[i][1];
            }
        }

        return tmp.size();
    }
};