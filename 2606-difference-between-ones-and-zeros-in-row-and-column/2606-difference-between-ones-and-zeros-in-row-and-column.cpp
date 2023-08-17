class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<int> onesRow,zerosRow,onesCol,zerosCol;

        for(auto &it: grid){
            int cnt=count(it.begin(),it.end(),1);
            onesRow.push_back(cnt);
            cnt=count(it.begin(),it.end(),0);
            zerosRow.push_back(cnt);
        }

        for(int i=0;i<m;i++){
            int cntzero=0,cntone=0;
            for(int j=0;j<n;j++){
                if(grid[j][i]==0)
                ++cntzero;
                else
                ++cntone;
            }
            zerosCol.push_back(cntzero);
            onesCol.push_back(cntone);
        }

        vector<vector<int>> diff(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                diff[i][j]=onesRow[i]+onesCol[j]-zerosRow[i]-zerosCol[j];
            }
        }

        return diff;

    }
};