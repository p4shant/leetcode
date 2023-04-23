class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> nsl,nsr,width;
        stack<pair<int,int>> s;
        int maxi=0;
        int n=heights.size();
        
        // finding next smallest element index to right of ith element
        for(int i=n-1;i>=0;i--){
            if(s.empty())
                nsr.push_back(n);
            else{
                if(s.top().first<heights[i])
                    nsr.push_back(s.top().second);
                else{
                    while(s.size()>0&&s.top().first>=heights[i])
                        s.pop();
                    if(s.empty())
                        nsr.push_back(n);
                    else
                        nsr.push_back(s.top().second);
                }
            }
            s.push({heights[i],i});
        }
        reverse(nsr.begin(),nsr.end());
        
        while(!s.empty())
            s.pop();
        
        //finding next smallest element index to left of ith element
        for(int i=0;i<n;i++){
            if(s.empty())
                nsl.push_back(-1);
            else{
                if(s.top().first<heights[i])
                    nsl.push_back(s.top().second);
                else{
                    while(s.size()>0&&s.top().first>=heights[i])
                        s.pop();
                    if(s.empty())
                        nsl.push_back(-1);
                    else
                        nsl.push_back(s.top().second);
                }
            }
            s.push({heights[i],i});
        }
        
        //finding width and maximum rectsngle
        for(int i=0;i<n;i++){
            maxi=max(maxi,heights[i]*(nsr[i]-nsl[i]-1));
        }
        return maxi;
    }
};