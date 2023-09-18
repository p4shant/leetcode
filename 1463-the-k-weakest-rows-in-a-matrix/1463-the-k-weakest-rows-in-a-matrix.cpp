class Solution {
public:

    int fn(vector<int> tmp){
        int low=0,high=tmp.size()-1;
        while(low<high){
            int md=(low+high)/2;
            if(tmp[md]==1){
                low=md+1;
            }
            else{
                high=md;
            }
        }
        if(tmp[high]==1)
        return high+1;
        else
        return low;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue < pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        int n=mat.size(),m=mat[0].size(),i=0;
        for(auto &it:mat){
            int cnt=fn(it);
            cout<<cnt<<" ";
            pq.push(make_pair(cnt,i));
            ++i;
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