class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> results; 

        unordered_map<string, vector<string>> anagram_groups;

        for (const auto& str : strs)
        {
            vector<int> freq(26);
            string key = "";
            for (const auto& c : str)
            {
                freq[c- 'a']++;
            }

            for (const auto& freqs : freq)
            {
                key += to_string(freqs) + ',';
            }

            anagram_groups[key].push_back(str);
        }

        for (const auto& groups : anagram_groups)
        {
            results.push_back(groups.second);
        }

        return results;
    }
};
