class Solution {

    vector<bool> subset(vector<int> arr,int range,int n){
        // use 1D array to optimize space complexity
        // initialization 
        vector<bool> dp(range+1, false); dp[0] = true;
        
        for(int  i = 0; i<n; i++){
            for(int j = range; j>= arr[i]; j--){
                // dp[j] = dp[j - arr[i]];
                if(dp[j - arr[i]]) dp[j] = true;
            }
        }
        return dp;
    }
    
  public:
    int minimumDifference(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        int range = 0; for(auto x:arr) range += x;
        
        // filter the value from the  range 
        vector<bool> res; res = subset(arr,range/2,n);
        vector<int> vals; for(int i = 0 ; i<= range/2; i++){
            if(res[i]) vals.push_back(i);
        }
        
        //  calculate the minimum difference
        int ans = INT_MAX;
        for(auto x : vals) ans = min(ans,range - (2*x));
        
        return ans;
        
    }
};
