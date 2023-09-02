class Solution {
public:

    int count(int i){

        int cnt=0;
        while(i>0){

            ++cnt;
            
            int x=(log2(i));
            int lodu=pow(2,x);

            if(lodu==i){
                return cnt;
            }
            else{
                i=i-lodu;
            }

        }
        return cnt;
    }

    vector<int> countBits(int n) {

        vector<int> bit;
        for(int i=0;i<=n;i++){
            int b=count(i);
            bit.push_back(b);
        }
        return bit;

    }
};