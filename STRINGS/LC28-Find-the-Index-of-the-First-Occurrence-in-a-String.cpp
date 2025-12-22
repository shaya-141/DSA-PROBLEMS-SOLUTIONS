class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0 , j = 0 , k = needle.size();
        int n = haystack.size();
        while(i < n){
           if(haystack[i] == needle[j]){
                j++;
                while(j < needle.size() && haystack[i+j] == needle[j]){
                    j++;
                }
                if(j == needle.size()) return i;
                else j = 0;
           }
           i++;
        }
        return -1 ;

    }
};
