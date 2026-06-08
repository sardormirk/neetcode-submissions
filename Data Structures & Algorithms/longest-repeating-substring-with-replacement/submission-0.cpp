class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int char_freq[26] = {0};

        int l = 0, max_freq = 0, result = 0;
        
        /*
            AAABABB k=1

            [BB]
        */
        for(int r = 0; r < s.length(); r++)
        {
            char_freq[s[r] - 'A']++;
            max_freq = max(max_freq, char_freq[s[r] - 'A']);

            while ((r - l + 1) - max_freq > k)
            {
                char_freq[s[l] - 'A']--;
                l++;
            }

            result = max(result, r - l + 1);
        }
        
        return result;
    }
};
