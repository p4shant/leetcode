class Solution {
public:
    long long maximumSumOfHeights(vector<int> maxHeight) {

        vector<long long int> maxHeights;
        for(auto &it:maxHeight)
        maxHeights.push_back(it);
        

        int n=maxHeights.size();
        vector<long long int> front(n,0);
        vector<long long int> back(n,0);

        front[0]=maxHeights[0];
        back[n-1]=maxHeights[n-1];

        for(int i=n-2;i>=0;i--){
            if(maxHeights[i]>=maxHeights[i+1])
            back[i]=(back[i+1]+maxHeights[i]);
            else{
                int k=i+1;
                bool flag=true;
                while(k<n){
                    if(maxHeights[i]>=maxHeights[k]){
                        flag=false;
                        back[i]=back[k]+(k-i)*maxHeights[i];
                        break;
                    }
                    k++;
                }
                if(flag)
                back[i]=(n-i)*maxHeights[i];
            }
        }

        for(int i=1;i<n;i++){
            if(maxHeights[i]>=maxHeights[i-1])
            front[i]=front[i-1]+maxHeights[i];
            else{
                int k=i-1;
                bool flag=true;
                while(k>=0){
                    if(maxHeights[i]>=maxHeights[k]){
                        flag=false;
                        front[i]=front[k]+(i-k)*maxHeights[i];
                        break;
                    }
                    --k;
                }
                if(flag){
                    long long int sex=maxHeights[i];
                    sex=sex*(i+1);
                    front[i]=sex;
                }
            }
        }
        long long int ans=INT_MIN;
        for(int i=0;i<n;i++){
            long long int tmp=front[i]+back[i]-maxHeights[i];
            ans=max(ans,tmp);
        }
        return ans;
    }
};