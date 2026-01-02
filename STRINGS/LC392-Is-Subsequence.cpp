class Solution {
public:
    int findLcs(string s1, string s2){
        int n = s1.size() , m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    bool isSubsequence(string s, string t) {
        // appraoch 1 using dp

        int n =  s.size();
        int lcs = findLcs(s,t);

        if(lcs == n) return true;
        else return false;

        // approach 2 using two pointer

        if(s.size() == 0) return true;
        int curr = 0;
        for(int i = 0; i < t.size(); i++){
            if(t[i] == s[curr]) curr++;
            if(curr == s.size()) return true;
        }
        return false;
    }
};
