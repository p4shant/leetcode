class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx=0,length=0;
        for(int i=0;i<gain.size();i++){
            length+=gain[i];
            mx=max(length,mx);
        }
        return mx;
    }
};