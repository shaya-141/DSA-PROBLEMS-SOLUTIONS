class Solution {
public:
    string minWindow(string s, string t) {
       unordered_map<char,int> freq;
       for(auto c : t) freq[c]++;

       int i = 0 , j = 0, n = s.size() , minLength = INT_MAX, letter = t.length();
        int start = 0;
       while(j < n){
            if(freq[s[j]] > 0) letter--;
            freq[s[j]]--;
            // shrink the window
            while(i <= j && letter == 0){
                if(j-i+1 < minLength){
                    start = i;
                    minLength = j - i + 1;
                }
                freq[s[i]]++;
                if(freq[s[i]]  > 0 ){
                    letter++;

                }
                i++;
            }

            j++;
       }
      
       return (minLength == INT_MAX ? "" : s.substr(start , minLength));
        
    }
};
