class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(n, k, target, dp);
    }
    
    long M = 1e9 + 7;
    
    int solve(int n, int k, int target, vector<vector<int>> &dp) {
        if (target < 0 || n == 0) {
            return target == 0 ? 1 : 0;
        }
        if (dp[n][target] != -1) {
            return dp[n][target];
        }
        
        long sum = 0;
        for (int i = 1; i <= k; i++) {
            sum = (sum + solve(n - 1, k, target - i, dp)) % M;
        }
        
        return dp[n][target] = sum;
    }
};
