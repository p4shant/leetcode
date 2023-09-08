class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> ans;
        vector<int> a={1};
        vector<int> b={1,1};

        ans.push_back(a);
        if(n==1)return ans;
        ans.push_back(b);
        if(n==2)return ans;

        for(int i=1;i<=n-2;i++){
            vector<int> tmp;
            int sz=b.size();
            tmp.push_back(b[0]);
            for(int j=1;j<sz;j++){
                tmp.push_back(b[j]+b[j-1]);
            }
            tmp.push_back(b[sz-1]);
            ans.push_back(tmp);
            b=tmp;
        }

        return ans;
    }
};