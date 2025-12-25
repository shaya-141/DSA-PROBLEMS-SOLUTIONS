class Solution {
public:
    bool buddyStrings(string s, string goal) {
        // first case if s1 == s2 and s1 contain some char frequence
        // greter then or equal to 2 so we can swap forcefully
        
        int n = s.size();
        int m = goal.size();
        // if length not same 
        if(n != m) return false;

        if(s == goal){  
            bool isOk = false;
            vector<int> freq(26,0);
            
            for(int i = 0 ; i < n ; i++){
                freq[s[i] - 'a']++;
                if(freq[s[i] - 'a'] >= 2){
                    isOk = true;
                    break;
                }
            }
            return isOk;
        
        }

        // check if we find two mismatch indices and swap then and get 
        // equal string 

        vector<int> oddIndices;
        for(int i = 0 ; i < n; i++){
            if(s[i] != goal[i]) oddIndices.push_back(i);
        }
        
        // if not match indices positon size is greater then 2 return false we
        // can  swap only one time
        if(oddIndices.size() != 2  ) return false;
        swap(s[oddIndices[0]] , s[oddIndices[1]]);
        
        return s == goal;
    }
};
