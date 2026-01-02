class Solution {
public:
    string findLine(int i , int j , int eachSlotsSpace,int extraSpace ,vector<string>& words, int maxWidth){
        string line = "";
        for(int k = i; k < j; k++){
            line += words[k];

            if(k == j - 1) continue;

            for(int z = 1; z <= eachSlotsSpace; z++) line += " ";
            
            if(extraSpace > 0){
                line += " "; extraSpace -= 1;
            }
        }
        while(line.length() < maxWidth) line += " ";

        return line;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0 , n = words.size();

        while(i < n){
            
            int letterCount = words[i].size();
            int slots = 0;
            int j = i + 1;

            while(j < n && words[j].size() + letterCount + slots + 1 <= maxWidth){
                letterCount += words[j].length();
                slots += 1;
                j++;
            }

            int totalSpace = maxWidth - letterCount;
            int eachSlotsSpace = slots == 0 ? 0 : totalSpace / slots;
            int extraSpace = slots == 0 ? 0 : totalSpace % slots;

            if(j == n){
                eachSlotsSpace = 1;
                extraSpace = 0;
            }

            string line = findLine(i , j ,eachSlotsSpace,extraSpace,words,maxWidth);

            result.push_back(line);

            i = j;

        }

        return result;

    }
};
