class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        while(end-start>1){
            int middle=(start+end)/2;
            if(nums[middle]==target)
                return middle;
            else if(nums[middle]>target)
                end=middle;
            else
                start=middle;
        }
        if(nums[(start+end)/2]==target)
            return (start+end)/2;
        if(nums[end]<target)
            return end+1;
        if(nums[start]>target)
            return start;
        else 
            return start+1;
    }
};