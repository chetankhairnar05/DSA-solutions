int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<int> dp(n, 1);      // Length of LIS ending at i
    vector<int> count(n, 1);   // Number of LIS ending at i

    int maxLen = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];  // reset count
                } else if (dp[j] + 1 == dp[i]) {
                    count[i] += count[j];  // add more ways
                }
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    int totalWays = 0;
    for (int i = 0; i < n; ++i) {
        if (dp[i] == maxLen) {
            totalWays += count[i];
        }
    }
    return totalWays;
}
