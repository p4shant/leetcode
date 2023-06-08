class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        int a[n][2];
        for(int i=0;i<n;i++){
            a[i][0]=1;
            a[i][1]=1;
        }
        long long int ans=0;
        int tmp=0,tmp2=0;
        for(int i=queries.size()-1;i>=0;i--){
            int x=queries[i][0];
            if(a[queries[i][1]][queries[i][0]]){
                if(x==0){
                    ++tmp2;
                    ans+=(n-tmp)*queries[i][2];
                }
                else{
                    ++tmp;
                    ans+=(n-tmp2)*queries[i][2];
                }
                a[queries[i][1]][queries[i][0]]=0;
            }
        }
        return ans;
    }
};