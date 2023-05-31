class Solution {
public:
    bool judgeSquareSum(int c) {
        
        // finding all pairs of squares
        vector<long long int> sq;
        long long int tmp=pow(c,0.5);
        for(int i=0;i<=tmp;i++)
            sq.push_back(i*i);
        
        //searching the pair
        long long int start=0,end=sq.size()-1;
        while(start<=end){
            long long int t=sq[start]+sq[end];
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