class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {

        vector<int> vec(n+1,0);

        for( int i=0; i<=n; i++ ){

            int left=max(0,i-ranges[i]);
            int right=i+ranges[i];

            if(left!=right){
                vec[left]=max(vec[left],right);
            }

        }

        int cnt=0,mx=0,tmp=0;

        for(int i=0;i<n;i++){

            mx=max(mx,vec[i]);

            if( i==tmp){
                
                if(tmp>=mx)
                return -1;

                tmp=mx;
                ++cnt;

            }

            if(tmp>=n)
            return cnt;

        }
        
        return cnt;

    }
};