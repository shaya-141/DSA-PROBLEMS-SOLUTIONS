class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int times = 1;
        string newStr = a;

        // Repeat a until newStr is at least as long as b
        while (newStr.length() < b.length()) {
            newStr += a;
            times++;
        }

        // Check if b is substring
        if (newStr.find(b) != string::npos) return times;

        // Check one more repeat for boundary-cross case
        newStr += a;
        times++;
        if (newStr.find(b) != string::npos) return times;

        // Not found
        return -1;
    }
};
