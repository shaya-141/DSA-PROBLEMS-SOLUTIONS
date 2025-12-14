class Solution {
public:
    string solve(int n){
        if(n == 1) return "1";
        string say = solve(n-1);
        int i = 0, l = say.size();
        string temp;
        while(i < l){
            char c = say[i];
            int count = 0;
            while(i < l && say[i] == c){
                count++;
                i++;
            }
            temp += to_string(count) + c;
           
        }
        return temp;
    }

    string countAndSay(int n) {
        string ans = solve(n);
        return ans ;
    }
};
