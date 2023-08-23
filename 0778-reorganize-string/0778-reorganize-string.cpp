class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> mp;
        for(auto &it:s){
            mp[it]++;
        }

        priority_queue<pair<int,char>> pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }

        string ans="";

        while(pq.size()>1){

            int x=pq.top().first;
            char c=pq.top().second;
            pq.pop();

            int y=pq.top().first;
            char d=pq.top().second;
            pq.pop();


            ans+=c;
            ans+=d;
            --x;--y;

            if(x>0)
            pq.push({x,c});
            if(y>0)
            pq.push({y,d});

        }
        if(pq.size()==0){
            return ans;
        }
        else if(pq.size()==1){
            if(pq.top().first==1){
                ans+=pq.top().second;
                return ans;
            }
            else
            return "";
        }
        else
        return "";
    }
};