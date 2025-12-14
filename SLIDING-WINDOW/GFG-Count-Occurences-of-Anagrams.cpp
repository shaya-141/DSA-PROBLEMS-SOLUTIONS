// User function template for C++
class Solution {
  public:
    int search(string &pat, string &txt) {
        // count frequency of pat character
        unordered_map<char,int> freq;
        for(auto x : pat) freq[x]++;
        
        // create mp and store freq becz first we check if txt[j] exist in freq then we decrease frequency 
        unordered_map<char,int> mp = freq;
        
        
        int n = txt.size() , letter = mp.size(), count =0;
        int i = 0 ,j =0, k = pat.size();
        
        while(j < n){
            // check and decrease frequency from mp
            if(freq.find(txt[j]) != freq.end()){
                mp[txt[j]]--;
                if(mp[txt[j]] == 0) letter--;
            }
            // check if window size is greater than pat size then we shrink
            if(j - i + 1 > k){
                if(freq.find(txt[i]) != freq.end()){
                    if(mp[txt[i]] == 0) letter++;
                    mp[txt[i]]++;
                }
                i++;
            }
            // if window size is  == patsize than we increase count if letter == 0;
            if(j - i + 1 == k) {
                if(letter == 0) count++;
            }
            
            j++;
        }
        
        
        
        return count;
        
        
    }
};
