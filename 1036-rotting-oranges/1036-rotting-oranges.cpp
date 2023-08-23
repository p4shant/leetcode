class Solution {
public:
    
    queue<pair<int,int>> q;

    void bfs( vector<vector<int>>& grid , vector<int>& drow, vector<int>& dcol ,int &cnt ){

        int sz=q.size(),tmp=0;
        int n=grid.size(),m=grid[0].size();

        for(int i=0;i<sz;i++){

            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            for(int j=0;j<4;j++){

                int nrow=x+drow[j];
                int ncol=y+dcol[j];

                if( (nrow<n&&nrow>=0) && (ncol<m&&ncol>=0) && (grid[nrow][ncol]==1) ){

                    tmp=1;
                    grid[nrow][ncol]=2;
                    q.push({nrow,ncol});

                }
            }
        }

        if(tmp)
        ++cnt;

    }


    int orangesRotting(vector<vector<int>>& grid) {

        int n=grid.size(),m=grid[0].size(),cnt=0;

        vector<int> drow={-1,0,0,1};
        vector<int> dcol={0,1,-1,0};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            bfs(grid,drow,dcol,cnt);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return cnt;
        
    }
};