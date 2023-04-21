class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for(auto &it:tokens){
            if(it!="+"&&it!="-"&&it!="*"&&it!="/")
                s.push(it);
            else{
                int a=stoi(s.top());
                s.pop();
                int b=stoi(s.top());
                s.pop();
                if(it=="+"){
                    string tmp=to_string(b+a);
                    s.push(tmp);
                }
                else if(it=="-"){
                    string tmp=to_string(b-a);
                    s.push(tmp);
                }
                else if(it=="/"){
                    string tmp=to_string(b/a);
                    s.push(tmp);
                }
                else{
                    string tmp=to_string(b*a);
                    s.push(tmp);
                }
            }
        }
        int ans=stoi(s.top());
        return ans;
    }
};