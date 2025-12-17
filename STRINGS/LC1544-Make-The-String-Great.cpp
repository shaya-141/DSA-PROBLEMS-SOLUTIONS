class Solution {
public:
    string makeGood(string s) {
        
        int n = s.size();
        string ans = "";
        
        for(int i = 0 ; i < n; i++){
            if(ans != "" && (ans.back() == s[i] + 32 || ans.back() == s[i] - 32)){
                ans.pop_back();
            }else{
                ans += s[i];
            }
        }

        return ans;

    }
};
