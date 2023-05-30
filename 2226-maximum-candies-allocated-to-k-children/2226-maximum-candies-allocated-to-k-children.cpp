class Solution {
public:
    
    bool ispossible(long long int md,vector<int>& candies,long long k){
        long long int cnt=0;
        for(auto &it:candies){
            cnt+=it/md;
        }
        return cnt>=k;
    }
    
    
    int maximumCandies(vector<int>& candies, long long k) {
        //sum of all candies
        long long int sum = std::accumulate(candies.begin(), candies.end(), 0ll);
        if(sum<k)
            return 0;
        else{
            long long int start=1,end=1e9+1,ans=0;
            while(start<=end){
                long long int md=start+(end-start)/2;
                if(md==0)
                    return 0;
                if(ispossible(md,candies,k)){
                    ans=md;
                    start=md+1;
                }
                else
                    end=md-1;
            } 
            return ans;
        }
    }
};