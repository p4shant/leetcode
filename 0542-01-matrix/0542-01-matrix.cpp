class Solution {
public:


    vector<vector<int>> bfs(vector<vector<int>>& mat){

        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> visited(n,vector<int> (m,0));
        vector<vector<int>> dist(n,vector<int> (m,0));
        vector<int> p={-1,0,0,1};
        vector<int> r={0,-1,1,0};
        queue<pair<pair<int,int>,int>> q;

        //putting all zero's in queue so that you can reach nearest one
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(mat[i][j]==0){
                    visited[i][j]=1;
                    q.push({{i,j},0});
                }

            }
        }

        while(!q.empty()){

            int sz=q.front().second;
            int sexi=q.front().first.first;
            int sexj=q.front().first.second;
            q.pop();

            for(int i=0;i<4;i++){

                int x=p[i]+sexi;
                int y=r[i]+sexj;

                if(x>=0&&x<n&&y>=0&&y<m){

                    if(mat[x][y]==1 && visited[x][y]==0){

                        mat[x][y]=0;
                        visited[x][y]=1;
                        dist[x][y]=sz+1;
                        q.push({{x,y},sz+1});

                    }
                    

                }
            }

        }

        return dist;

    }


    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        return bfs(mat);
        

    }
};