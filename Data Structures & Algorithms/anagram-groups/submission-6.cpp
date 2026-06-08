class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram_groups;
        vector<vector<string>> ret;

        for (const auto& str : strs)
        {
            array<int, 26> freq {};
            string key = "";
            for(int i = 0; i < str.length(); i++)
            {
                
                freq[str[i] - 'a']++;
            }

            for (int i = 0; i < 26; i++)
            {
                key += to_string(freq[i]);
                key += ',';
            }
            anagram_groups[key].push_back(str);
        }

        for (auto& [key, group] : anagram_groups) {
            ret.push_back(group);
        }

        return ret;

    }
};
