class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue < pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        int n=mat.size(),m=mat[0].size();
        for(auto i=0;i<n;i++){
            int cnt=0;
            for(auto j=0;j<m;j++){
                cnt+=mat[i][j];
            }
            pq.push(make_pair(cnt,i));
        }
        vector<int> ans;
        while(k--){
            int x=pq.top().second;
            ans.push_back(x);
            pq.pop();
        }
        return ans;
    }
};