class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //  store frequenct of string p
        unordered_map<char,int> freq;
        for(auto x : p) freq[x]++;

        int i = 0, j = 0 , k = p.size() , n = s.size(),  letter = freq.size();
        vector<int> ans;
        while(j < n){
            if(freq.find(s[j]) != freq.end()){
                freq[s[j]]--;
                if(freq[s[j]] == 0) letter--;
            }
            // shrink the window
            if(j - i + 1 > k){
                if(freq.find(s[i]) != freq.end()){
                    if(freq[s[i]] == 0) letter++;
                    freq[s[i]]++;
                }
                i++;
            }
            // if window size == k 
            if(j - i + 1 == k ){
                if(letter == 0) ans.push_back(i);
            }
            j++;
        }


        return ans; 
    }
};