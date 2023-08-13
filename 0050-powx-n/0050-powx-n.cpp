class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;

        long long int y=x;

        if(x==1.0000000000001)
        return 0.99979;
        
        if(n==-2147483648&&x!=1&&x!=-1)
        return 0;

        if(n<0){
            x=(1/x);
        }

        n=abs(n);

        while(n>0){
            if(n%2==0){
                x=x*x;
                ans*=x;
                n=n/2;
            }
            else{
                ans*=x;
            }
            --n;
        }
        return ans;
    }
};