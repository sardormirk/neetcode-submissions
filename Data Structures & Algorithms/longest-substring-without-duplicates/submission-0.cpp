class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.length();

        int count = 0;
        unordered_set<char> subset;

        while (l < n && r < n)
        {  
            while (subset.contains(s[r]))
            {
                subset.erase(s[l]);
                l++;
            }

            subset.insert(s[r]);
            count = max(count, r - l + 1);
            r++;
        }

        return count;
    }
};
