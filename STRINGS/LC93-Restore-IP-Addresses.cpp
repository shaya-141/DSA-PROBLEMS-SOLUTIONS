class Solution {
public:
    vector<string> res;
    bool isValid(string s){
        if(s[0] == '0') return false;
        int num = stoi(s);

        return num <= 255;

    }
    void solve(string s,int idx , int parts,string curr){
        // base case 
        int n = s.size();
        if(idx == n && parts == 4){
            // remove last decimal we add
            curr.pop_back();
            res.push_back(curr);
            return;
        }
        if(idx + 1 <= n){
            solve(s, idx + 1 , parts + 1 , curr + s[idx] + ".");

        }
        if(idx + 2 <= n && isValid(s.substr(idx , 2))){
             solve(s,idx + 2,parts + 1 , curr + s.substr(idx,2) + ".");
        }
        if(idx + 3 <= n && isValid(s.substr(idx , 3))){
            solve(s,idx + 3 , parts + 1, curr + s.substr(idx , 3) + ".");
        }
        return;

    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size() > 12) return {};

        solve(s,0,0,"");

        return res;
    }
};
