class Solution {
public:

    int count(int i, vector<int> &sex){

        int cnt=0,n=i;

        while(i>0){

            ++cnt;
            
            int x=(log2(i));
            int lodu=pow(2,x);

            if(lodu==i){
                sex[n]=cnt;
                return cnt;
            }
            else{
                i=i-lodu;
            }

            if(sex[i]!=-1){
                sex[n]=cnt+sex[i];
                return cnt+sex[i];
            }

        }
        sex[n]=cnt;
        return cnt;
    }

    vector<int> countBits(int n) {

        vector<int> bit;
        vector<int> sex(n+1,-1);

        for(int i=0;i<=n;i++){
            int b=count(i,sex);
            bit.push_back(b);
        }
        return bit;

    }
};