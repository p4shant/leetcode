//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       stack<pair<int,int>> stk;
       vector<int> ans;

       for(int i=0;i<n;i++){
           if(stk.empty())
           ans.push_back(-1);
           else{
               if(stk.top().second>price[i]){
                   ans.push_back(stk.top().first);
               }
               else{
                   while(stk.size()>0 && stk.top().second<=price[i]){
                       stk.pop();
                   }
                   if(stk.size()!=0)
                   ans.push_back(stk.top().first);
                   else
                    ans.push_back(-1);

                   
               }
           }
           stk.push({i,price[i]});
       }
       for(int i=0;i<n;i++){
           ans[i]=i-ans[i];
       }
       return ans;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends