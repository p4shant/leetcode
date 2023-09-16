class Solution {
public:
    int fn(vector<int>& dp,vector<int>& cost,int i){

        int n=cost.size();
        if(i==n-1)
        return cost[i];
        if(i>=n)
        return 0;

        if(dp[i]!=-1)
        return dp[i];

        return dp[i]=cost[i]+min(fn(dp,cost,i+1),fn(dp,cost,i+2));

    }

    int minCostClimbingStairs(vector<int>& cost) {

        int n=cost.size();
        vector<int> dp(n+1,-1);
        return min(fn(dp,cost,0),fn(dp,cost,1));
    }

};