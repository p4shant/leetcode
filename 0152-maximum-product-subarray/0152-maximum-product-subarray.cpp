class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN,tmp=1,tmp2=1,t=0;
        for(auto &it:nums){
            //for storing product from start
            tmp=tmp*it;
            maxi=max(maxi,tmp);
            //for storing product after first negative number
            if(t==1){
                tmp2=tmp2*it;
                maxi=max({maxi,tmp,tmp2});
            }
            if(it==0){
                tmp=1;
                tmp2=1;
                t=0;
            }
            //checking when first negative number come
            if(it<0)
            t=1;
        }
        return maxi;
    }
};