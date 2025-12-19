class Solution {
public:
    unordered_map<string,bool> mp;
    bool isConcatenated(set<string> &concat, string &curr){
        
        if(mp.find(curr) != mp.end()) return mp[curr];

        for(int i = 0; i < curr.size(); i++){
            string prefix = curr.substr(0,i+1);
            string suffix = curr.substr(i+1);

            if(concat.find(prefix) != concat.end() && concat.find(suffix) != concat.end()){
                 return mp[curr] =true;
            }
            if(concat.find(prefix) != concat.end() && isConcatenated(concat,suffix)){
                 return mp[curr] =true;
            }

        }
        return mp[curr] =false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        set<string> concat(words.begin(),words.end());

        int n = words.size();
        vector<string> result;
        for(int i = 0; i < n; i++){
            string curr = words[i];
            if(isConcatenated(concat,curr)){
                result.push_back(curr);
            }
        }

        return result;

    }
};
