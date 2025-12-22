class Solution {
public:
    int countSubsetSum(vector<int> nums,int target){
       int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        // initilization
        for(int i = 0; i <= n; i++) dp[i][0] = 1;

        // bottom up
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][target];

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        //  derived the value
        int totalSum = 0; for(auto x : nums) totalSum += x;

        if(target > totalSum || totalSum + target < 0) return 0;
        if((totalSum + target) % 2 != 0) return 0;

        int val = (totalSum + target)/2;
        int res = countSubsetSum(nums,val);
        
        return res;
    }
};
