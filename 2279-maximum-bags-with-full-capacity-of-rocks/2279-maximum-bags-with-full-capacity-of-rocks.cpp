class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> v;
        for(int i=0;i<capacity.size();i++){
            v.push_back(capacity[i]-rocks[i]);
        }
        int cnt=0;
        sort(v.begin(),v.end());
        for(auto &it:v){
            if(it<=additionalRocks){
                additionalRocks-=it;
                ++cnt;
            }
        }
        return cnt;
    }
};