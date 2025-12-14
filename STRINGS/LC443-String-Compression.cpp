class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0 , i = 0;

        while(i < n){
            char currChar = chars[i];
            int count = 0;
            // count duplicate
            while(i < n && currChar == chars[i]){
                count++;
                i++;
            }
            chars[index] = currChar;
            index++;
            if(count > 1){
                string temp = to_string(count);
                for(auto ch:temp){
                    chars[index] = ch;
                    index++;
                }
            }
        }

        return index;

    }
};
