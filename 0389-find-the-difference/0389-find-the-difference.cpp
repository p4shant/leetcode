class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp,mp2;
        for(auto &it:s)mp[it]++;
        for(auto &it:t){
            if(mp.find(it)==mp.end()){
                return it;
            }
            mp2[it]++;
        }
        for(auto &it:mp){
            if(mp2[it.first]!=it.second)
            return it.first;
        }
        char ch='a';
        return ch;
    }
};