class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {

        int n=groupSizes.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back(make_pair(groupSizes[i],i));
        }

        sort(v.begin(),v.end());

        vector<vector<int>> ans;
        int i=0;
        while(i<n){
            int tmp=v[i].first;
            vector<int> lodu;
            for(int j=i;j<i+tmp;j++){
                lodu.push_back(v[j].second);
            }
            i=i+tmp;
            ans.push_back(lodu);
        }
        return ans;
    }
};