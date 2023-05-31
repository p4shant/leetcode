class Solution {
public:
    bool judgeSquareSum(int c) {
        //searching the pair
        long long int start=0,end=pow(c,0.5);
        while(start<=end){
            long long int t=start*start+end*end;
            if(t==c)
                return true;
            else if(t>c)
                end--;
            else
                start++;
        }
        return false;
    }
};