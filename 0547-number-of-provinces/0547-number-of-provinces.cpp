class Solution {
public:
    
    void dfs(int x,int n,vector<int> &visited,vector<vector<int>>& isConnected){
        for(int j=0;j<n;j++){
            if(x!=j&&(!visited[j])&&isConnected[x][j]){
                visited[j]=1;
                dfs(j,n,visited,isConnected);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(),cnt=0;
        vector<int> visited(n+1,0);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                ++cnt;
                dfs(i,n,visited,isConnected);
            }
        }

        return cnt;
    }
};