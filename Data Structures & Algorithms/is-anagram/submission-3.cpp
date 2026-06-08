class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> s_freq_arr(26), t_freq_arr(26);

        if (s.size() != t.size()) return false;

        for (int i = 0; i < s.size(); i++)
        {
            s_freq_arr[s[i] - 'a']++;
            t_freq_arr[t[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if(s_freq_arr[i] != t_freq_arr[i]) return false;
        }

        return true;
    }
};
