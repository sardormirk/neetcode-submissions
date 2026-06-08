class Solution {
public:
    string minWindow(string s, string t) {

        int slen = s.length(), tlen = t.length();
        pair<int, int> res;
        unordered_map<char, int> sCount, tCount;

        
        if (tlen > slen) return "";
        if (tlen == 0) return "";

        for (const auto& c : t)
        {
            tCount[c]++;
        }

        int l = 0, resLength=INT_MAX, have = 0, need = tCount.size(); // need, how many chars need to match count
        for(int r = 0; r < slen; r++)
        {
            char c = s[r];
            sCount[c]++;
            if (tCount.contains(c) && sCount[c] == tCount[c])
            {
                have++;
            }

            while (have == need) // valid substring
            {
                // shrink while result is still valid
                // update result
                if(r - l + 1 < resLength) // better solution found
                {
                    res = {l, r};
                    resLength = r - l + 1;
                }

                sCount[s[l]]--;
                if (tCount.contains(s[l]) && sCount[s[l]] < tCount[s[l]]) // result is no longer valid
                {
                    have--;
                }
                l++;
            }
        }

        return (resLength == INT_MAX) ? "" : s.substr(res.first, resLength);
    }
};
