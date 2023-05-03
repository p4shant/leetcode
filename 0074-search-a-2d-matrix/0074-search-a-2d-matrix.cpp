#define ll long long int 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ll n = matrix.size(), m = matrix[0].size();
        ll st = 0,ed = m*n-1;
        while(st<=ed)
        {
            ll mid = (st+ed)/2;
            ll row = mid/m;
            ll col = mid - row*m;
            int val = matrix[row][col];
            if(val==target)
            return true;
            if(val<target)
            st = mid+1;
            else
            ed = mid-1;
        }
        return false;
    }
};