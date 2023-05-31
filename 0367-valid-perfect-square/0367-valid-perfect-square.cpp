class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int start=1,end=num;
        while(start<=end){
            long long int md=start+(end-start)/2;
            if(md==(num*1.0)/md)
                return true;
            else if(md>num/md)
                end=md-1;
            else
                start=md+1;
        }
        return false;
    }
};