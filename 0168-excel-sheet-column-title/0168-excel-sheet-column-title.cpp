class Solution {
public:
    string convertToTitle(int columnNumber) {

        long long int x=columnNumber;
        string ans="";

        while(x>0){
            x--;
            ans=char(x%26+65)+ans;
            x=x/26;
        }

        return ans;
    }
};