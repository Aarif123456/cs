class Solution {
public:
    bool isPeak(vector<int>& nums, int i){
        return (i==0 || nums[i-1] < nums[i] ) && ( i==nums.size()-1 || nums[i] > nums[i+1]);
    }

    bool isAscending(vector<int>& nums, int i){
        return (i==0 || nums[i-1] < nums[i] ) && ( i==nums.size()-1 || nums[i] < nums[i+1]);
    }
    int findPeakElement(vector<int>& nums, int l, int r){
        int m = (l+r)/2;
        if(isPeak(nums, m) || l>=r) return m;
        if(isAscending(nums, m)) return findPeakElement(nums, m+1, r);
        return findPeakElement(nums, l, m-1);
    }

    int findPeakElement(vector<int>& nums) {
        int peak = findPeakElement(nums, 0, nums.size()-1);
        return isPeak(nums, peak) ? peak: -1;
    }
};
