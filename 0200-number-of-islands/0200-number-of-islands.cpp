class Solution {
public:

    void bfs(int i, int j, vector<vector<int>>& visited, vector<vector<char>>& grid){

        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> q;
        visited[i][j]=1;
        q.push({i,j});

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int drow=-1;drow<=1;drow++){
                for(int dcol=-1;dcol<=1;dcol++){

                    int nrow=row+drow;
                    int ncol=col+dcol;

                    if(abs(drow)!=abs(dcol)&&nrow<n&&nrow>=0&&ncol<m&&ncol>=0&&grid[nrow][ncol]=='1'&&visited[nrow][ncol]==0){
                        visited[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }

                }
            }


        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n=grid.size(),m=grid[0].size(),cnt=0;

        vector<vector<int>> visited( n , vector<int> (m,0) );

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((!visited[i][j])&&(grid[i][j]=='1')){
                    ++cnt;
                    bfs(i,j,visited,grid);
                }
            }
        }
        return cnt;
    }
};