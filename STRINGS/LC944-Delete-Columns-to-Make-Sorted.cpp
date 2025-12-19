class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size() , k = strs[0].size();
        int count = 0;
        // i treverse into each letter of word
        for(int i = 0; i < k; i++){
            // j traverse each word in array 
            for(int j = 1; j < n; j++){
                if(strs[j][i] < strs[j-1][i]){
                    count++;
                    break;
                }
            }
        }

        return count;
    }
};
