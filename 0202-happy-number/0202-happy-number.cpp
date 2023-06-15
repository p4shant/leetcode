class Solution {
public:
    bool isHappy(int n) {
        if(n==1)
        return true;
        unordered_map<int,int> mp;
        while(n!=1){
            if(mp.find(n)!=mp.end())
                return false;
            mp[n]++;
            long long int tmp=0;
            while(n!=0){
                tmp+=(n%10)*(n%10);
                n/=10;
            }
            if(tmp==1)
                return true;
            n=tmp;
        }
        return false;
    }
};