class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        
        vector<int> tmp(100,0);
        for(auto &it:clips){
            tmp[it[0]]=max(it[1],tmp[it[0]]);
        }

        int cnt=0,sex=0,mx=0;
        for(int i=0;i<time;i++){
            mx=max(tmp[i],mx);
            if(sex==i){

                if(sex==mx)
                return -1;

                sex=mx;
                ++cnt;

                if(sex>=time)
                return cnt;
            }
        }
        return cnt;
    }
};