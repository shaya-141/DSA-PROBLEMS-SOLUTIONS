class Solution {
public:
    string orderlyQueue(string s, int k) {
        // main logic if we have to swap between two or more character in the end of all possibilities we will able to sort the entire string 
        if(k > 1){
            sort(begin(s),end(s));
            return s;
        }
        string ans = s;
        string temp = s;
        for(int i = 0 ; i < s.size()-1; i++){
            temp = temp.substr(1,s.size()-1) + temp[0];
            if(temp < ans) ans = temp;
        }

        return ans;
        
    }
};
