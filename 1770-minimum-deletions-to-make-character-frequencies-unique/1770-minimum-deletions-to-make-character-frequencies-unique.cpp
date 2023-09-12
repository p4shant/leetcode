class Solution {
public:
    int minDeletions(string s) {
        vector<int> sex;
        map<char,int> mp;
        unordered_set<int> st;
        for(auto &it:s)
        mp[it]++;
        for(auto &it:mp)
        sex.push_back(it.second);
        int ans=0;
        sort(sex.begin(),sex.end());
        st.insert(sex[0]);
        for(int i=1;i<sex.size();i++){

            if(sex[i]==sex[i-1]){
                int j=sex[i]-1;
                while(j>=0){
                    if(j==0){
                        ans+=sex[i];
                        cout<<ans;
                        break;
                    }
                    if(st.find(j)==st.end()){
                        st.insert(j);
                        ans+=sex[i]-j;
                        cout<<ans<<" sex ";
                        break;
                    }
                    --j;
                }
            }
            st.insert(sex[i]);
        }
        return ans;
    }
};