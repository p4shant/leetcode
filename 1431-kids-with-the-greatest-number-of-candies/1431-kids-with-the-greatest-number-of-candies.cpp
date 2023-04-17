class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ret(candies.size());
        int m=*max_element(candies.begin(),candies.end());
        // m+=extraCandies;
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=m)
            ret[i]=1;
            else
            ret[i]=0;
        }
        return ret;
    }
};