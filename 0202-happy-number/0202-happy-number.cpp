class Solution {
public:
    bool isHappy(int n) {
        if(n==1)
        return true;
        int cnt=2511;
        while(n!=1&&cnt!=0){
            long long int sm=0;
            while(n!=0){
                sm+=(n%10)*(n%10);
                n=n/10;
            }
            if(sm==1)//happy number
            return true;
            else if(sm==n)//loop
            return false;
            
            n=sm;
            cnt--;
        }
        return false;
    }
};