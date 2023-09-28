class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        vector<int> visited(26,0);
        vector<bool> seen(26,false);
        vector<int> tmp(26,0);

        for(int i=0;i<s.size();i++)
        visited[s[i]-'a']=i;

        stack<char> st;

        for(int i=0;i<s.size();i++){
            char it=s[i];
            if(!st.empty()){
                if(!seen[it-'a']){
                    if(it>st.top()){
                        st.push(it);
                        seen[it-'a']=true;
                        cout<<st.top()<<" shiv\n";
                    }
                    else if(it<st.top()){
                        while(!st.empty()&&it<st.top()&&visited[st.top()-'a']!=tmp[st.top()-'a']){
                            seen[st.top()-'a']=false;
                            st.pop();
                        }
                        st.push(it);
                        seen[it-'a']=true;
                        cout<<st.top()<<" shiv gf\n";
                    }
                }
            }
            else{
                st.push(it);
                seen[it-'a']=true;
                cout<<st.top()<<" shiv 2gf\n";
            }

            tmp[it-'a']=i;

        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};