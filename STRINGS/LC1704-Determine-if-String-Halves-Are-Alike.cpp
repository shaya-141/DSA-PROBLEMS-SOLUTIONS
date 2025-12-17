class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size() , m = n /2;
        int i = 0 , j = m;

        set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        int firstHalves = 0 , secHalves = 0;
        while(i < m && j  < n){
            if(vowels.count(s[i])) firstHalves++;
            if(vowels.count(s[j])) secHalves++;
            i++;
            j++;
        } 

        return firstHalves == secHalves;

    }
};
