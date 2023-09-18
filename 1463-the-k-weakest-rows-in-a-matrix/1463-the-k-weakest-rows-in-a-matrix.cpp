class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> tmp;
        int n=mat.size(),m=mat[0].size();
        for(auto i=0;i<n;i++){
            int cnt=0;
            for(auto j=0;j<m;j++){
                cnt+=mat[i][j];
            }
            tmp.push_back(make_pair(cnt,i));
        }
        sort(tmp.begin(),tmp.end());
        int i=0;
        for(auto &it:tmp)
        cout<<it.first<<" "<<it.second<<endl;
        vector<int> ans;
        while(k--){
            ans.push_back(tmp[i].second);
            ++i;
        }
        return ans;
    }
};