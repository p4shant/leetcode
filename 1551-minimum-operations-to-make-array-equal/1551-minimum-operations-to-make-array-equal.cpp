class Solution {
public:
    int minOperations(int n) {
        long long int cnt=0;
        for(int i=1;i<=n;i=i+2){
            cnt+=n-i;
        }
        return cnt;
    }
};