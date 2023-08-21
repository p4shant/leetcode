class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        int n=s.size();

        for(int i=0;i<n/2;i++){
            string tmp=s.substr(0,i+1);
            string lodu="";
            int x=tmp.size();
            int p=n/x;
            while(p--){
                lodu+=tmp;
            }
            
            if(lodu==s)
            return true;
        }

        return false;

    }
};