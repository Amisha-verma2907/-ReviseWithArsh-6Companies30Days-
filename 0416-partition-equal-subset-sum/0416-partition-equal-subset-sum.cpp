class Solution {
public:
    bool Partition(vector<int>& nums, int target, int ind, vector<vector<int>>& dp) {
        // Base cases
        if (target == 0) return true; // Found a subset
        if (ind == 0) return nums[0] == target; // Only one element left to check

        // Memoization check
        if (dp[ind][target] != -1) return dp[ind][target];

        // Option 1: Not take the current element
        bool notTake = Partition(nums, target, ind - 1, dp);

        // Option 2: Take the current element (if it's smaller than or equal to the target)
        bool take = false;
        if (target >= nums[ind]) {
            take = Partition(nums, target - nums[ind], ind - 1, dp);
        }

        // Store the result in the memoization table
        return dp[ind][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        // If the total sum is odd, we cannot split it into two equal subsets
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        int n = nums.size();

        // Memoization table initialized with -1
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        // Check if we can find a subset with sum equal to target
        return Partition(nums, target, n - 1, dp);
    }
};
