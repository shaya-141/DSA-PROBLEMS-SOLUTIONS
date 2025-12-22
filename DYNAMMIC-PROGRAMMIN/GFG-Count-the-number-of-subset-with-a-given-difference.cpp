class Solution {
  public:
    int countofSubsetSum(vector<int> &arr,int value){
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(value+1));
        // initilization
        for(int i = 0; i<=n; i++){
            for(int j  = 0; j <= value; j++){
                if(i == 0) dp[i][j] = 0;
                if(j == 0) dp[i][j] = 1;
            }
        }
        
        for(int i = 1; i<= n; i++){
            for(int j = 0; j <= value; j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                }else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][value];
        
    }
  
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        // find a value form formula means derived a value
        int totalSum = 0;
        for(auto x : arr) totalSum += x;
        
        if(diff > totalSum) return 0;
        if((diff + totalSum ) % 2 != 0) return 0;
        
        int value = (diff + totalSum) / 2;
        
        int res = countofSubsetSum(arr,value);
        
        
        return res;
        
    }
};
