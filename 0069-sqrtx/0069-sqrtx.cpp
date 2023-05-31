class Solution {
public:
    int mySqrt(int x) {
        
        long long int start=1,end=x;
        if(x==0)
            return 0;
        while(start<=end){
            long long int md=start+(end-start)/2;
            if(md==x/md)
                return md;
            else if(md>x/md)
                end=md-1;
            else
                start=md+1;
        }
        return end;
    }
};