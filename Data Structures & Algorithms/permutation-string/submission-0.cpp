class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        /*
        bruteforce:

        generate all permutations of s1:

        loop through permutations and see if you can find them in s2:
        n = s1.length()
        O(n * n!/f1! * f2!)

        better:

        create a window of length s1

        iterate the window over s2

        check if substring in window is a permutation of s1

        check permutation by checking if s1 and substring of s2 are anagrams

        count of all chars is equal

        */ 

        int c_f[26] = {0};

        if (s1.length() > s2.length()) return false;

        vector<int> s1_count(26);
        vector<int> s2_count(26);

        int window_length = s1.length();

        for(int i = 0; i < window_length; i++)
        {
            s1_count[s1[i] - 'a']++;
            s2_count[s2[i] - 'a']++;
        }

        if (s1_count == s2_count) return true;

        for (int i = window_length; i < s2.length(); i++)
        {
            s2_count[s2[i] - 'a']++;
            s2_count[s2[i - window_length] - 'a']--;

            if (s1_count == s2_count) return true;
        }

        return false;
    }
};
