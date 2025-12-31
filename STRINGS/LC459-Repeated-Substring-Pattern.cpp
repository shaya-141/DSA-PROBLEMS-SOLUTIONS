class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        // if we start loop from n / 2 and make move reverse so code will optimize
        for(int l = n/2 ; l >= 1; l--){
            
            // 2 * root n 
            if(n % l == 0){ // check becz we only want n length string if l not
                            //  divided n so check another length
                string pattern = s.substr(0, l); // O(n)
                string newStr = "";

                // how many times we append 
                int times = n / l;
                
                while(times--){                 // O(n)
                    newStr += pattern;
                }
                if(newStr == s) return true;

            }
        }
        // time complexity  (2*root(n)) * (2 * n) = O(root(n) * n))

        return false;

    }
};
