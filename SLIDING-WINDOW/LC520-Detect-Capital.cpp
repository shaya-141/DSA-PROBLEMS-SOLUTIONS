class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag = false;
        
        char check ;
        if(isupper(word[0])){
            if(isupper(word[1])){
                check = 'U';
            }else check = 'L';
        }else check = 'L';

        for(int i = 1; i < word.size(); i++){
            if(check == 'U' && !isupper(word[i])){
                return false;
            }  
            if(check == 'L' && !islower(word[i])){
                return false;
            }
        }

        return true;
    }
};
