class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;

        int i = 0 , j = 0 , n = s.size(), maxLength = 0;

        while(j < n){
            if(freq.find(s[j]) == freq.end()) maxLength = max(maxLength , j - i + 1);
            else{
                while(i < j && freq.find(s[j]) != freq.end()){
                    freq[s[i]]--;
                    if(freq[s[i]] == 0) freq.erase(s[i]);
                    i++;
                }
            }

            freq[s[j]]++;
            j++;
        }

        return maxLength;

    }
};
