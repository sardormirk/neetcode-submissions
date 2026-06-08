class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> a;
        vector<vector<string>> ans; 

        for(auto s : strs){
            vector<int> c(26, 0);
            for(int i = 0; i < s.size(); i++){
                c[s[i] - 'a']++;
            }

            string key = to_string(c[0]);
            for(int i = 1; i < 26; i++){
                key += ',' + to_string(c[i]);
            }

            a[key].push_back(s);
            
        }

        for(auto kv : a){
            ans.push_back(kv.second);
        }

        return ans;
    }
};
