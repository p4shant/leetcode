class Solution {
public:
    int bestClosingTime(string customers) {
        
        int n=customers.size();

        vector<int> open(n,0);

        int cnt=0;
        for(int i=n-1;i>=0;i--){

            if(customers[i]=='Y'){
                ++cnt;
            }
            open[i]=cnt;

        }

        cnt=0;
        bool t=true;
        int i=0,penalty=INT_MAX,indx=0;

        while(i<n){

            int tmp=cnt+open[i];
            if(tmp<penalty){
                indx=i;
                penalty=tmp;
                cout<<penalty<<" ";
            }

            if(customers[i]=='N'){
                t=false;
                ++cnt;

            }
            ++i;
        }

        if(t)
        return n;
        else{
            if(cnt<penalty)
            return n;
            else
            return indx;
        }


    }
};