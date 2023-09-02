class Solution {
public:

    vector<int> countBits(int n) {

        vector<int> bit;
        vector<int> sex(n+1,-1);
        bit.push_back(0);


        for(int i=1;i<=n;i++){

            int cnt=0;

            int x=(log2(i));
            int lodu=pow(2,x);

            if(lodu==i)
            cnt=1;
            else
            cnt+=1+sex[i-lodu];

            sex[i]=cnt;

            bit.push_back(cnt);
        }
        return bit;

    }
};