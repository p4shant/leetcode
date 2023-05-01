class Solution {
public:
    double average(vector<int>& salary) {
        int n=salary.size()-2;
        double sum = std::accumulate(salary.begin(), salary.end(), 0);
        return (sum-*max_element(salary.begin(),salary.end())-*min_element(salary.begin(),salary.end()))/n;
        
    }
};