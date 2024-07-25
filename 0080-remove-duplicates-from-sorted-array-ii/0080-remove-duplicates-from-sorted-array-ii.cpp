class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1; // put K-1 here
        int curr = INT_MAX;
        if (nums.size() == 1) return 1;
        for (int i  = 0; i < nums.size(); i++)
        {
            if (nums[i] == curr and count > 0)
            {
                count--;
            }
            else if (nums[i] == curr and count <= 0)
            {
                nums[i] = INT_MAX;
                count--;
            }
            else if (nums[i] != curr)
            {
                curr = nums[i];
                count = 1; // Put k-1 here
            }
        }
        sort(nums.begin(), nums.end());
        int i = 0, l = 0;
        while (i < nums.size())
        {
            if (nums[i++] < INT_MAX)
            l++;
        }
        return l;
    }
};