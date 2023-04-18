class Solution {
public:
    static bool cmp(pair<int,int>a ,pair<int,int>b){
        return a.second>b.second;
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>> v;
        for(int i=0;i<boxTypes.size();i++){
            v.push_back({boxTypes[i][0],boxTypes[i][1]});
        }
        sort(v.begin(),v.end(),cmp);
        long long int tmp=truckSize,ans=0;
        for(auto &it:v){
            if(tmp>=it.first){
                tmp=tmp-it.first;
                ans+=it.first*it.second;
            }
            else{
                ans+=tmp*it.second;
                return ans;
            }
        }
        return ans;
    }
};