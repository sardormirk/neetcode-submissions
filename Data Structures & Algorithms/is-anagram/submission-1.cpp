class Solution {
public:
    bool isAnagram(string s, string t) {
        int c[26] = {};

        if(s.size() != t.size()) return false;
        
        for(int i = 0; i < s.size(); i++){
            c[s[i] - 97]++;
            c[t[i]- 97]--;
        }

        for(int i = 0; i < 26; i++){
            if(c[i] != 0) return false;
        }

        return true;
    }
};
