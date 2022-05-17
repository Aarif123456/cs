bool solve(vector<int>& nums) {
    if (nums.size() == 1)
        return nums[0] == 24;
    for (int i=0; i+1<nums.size(); ++i) {
        vector<int> cand{
            nums[i]+nums[i+1],
            nums[i]-nums[i+1],
            nums[i]*nums[i+1]
        };
        if (nums[i+1] != 0)
            cand.push_back(nums[i]/nums[i+1]);
        for (int v : cand) {
            vector<int> next=nums;
            next.erase(next.begin()+i);
            next.erase(next.begin()+i);
            next.insert(next.begin()+i, v);
            if (solve(next))
                return true;
        }
    }
    return false;
}