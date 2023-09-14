class Solution {
public:

    int fn(int n, vector<int>& dp, int sum){
        if(sum==n)
        return 1;
        if(sum>n)
        return 0;

        if(dp[sum]!=-1)
        return dp[sum];

        return dp[sum]=fn(n,dp,sum+1)+fn(n,dp,sum+2);
        
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        fn(n,dp,0);
        return dp[0];
    }
};