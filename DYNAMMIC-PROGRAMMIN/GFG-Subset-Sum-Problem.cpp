class Solution {
  public:
    bool solve(vector<int> &arr,int sum){
        int n = arr.size();
        // create table 
        vector<vector<bool>> dp(n+1,vector<bool>(sum + 1, false));
        // initilization of first row and column
        for(int i = 0; i <= n ; i++){
            for(int j = 0; j <= sum; j++){
                if(i == 0) dp[i][j] = false;
                if(j == 0) dp[i][j] = true;
            }
        }
        // bottom up dp 
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum ; j++){
                if(arr[i-1] <= j) {
                    dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
                }else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][sum];
        
    }
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        bool ans = solve(arr,sum);
        
        return ans;
    }
};
