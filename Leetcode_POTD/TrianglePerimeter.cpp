class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = nums.size(); i >= 3; --i) {
            int a = nums[i - 3], b = nums[i - 2], c = nums[i - 1];
            if (a + b > c)
                return a + b + c;
        }
        return 0;
    }
};
