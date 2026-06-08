class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> c;
        vector<pair<int, int>> p;
        vector<int> ans;

        for(int x : nums){
            c[x]++;
        }

        for(auto kv : c){
            p.push_back(kv);
        }

        sort(p.begin(), p.end(), [](const auto &a, const auto &b) {return a.second < b.second;});
        
        for(int i = k, cnt = p.size()-1; i--; i>=0){
            ans.push_back(p[cnt].first);
            cnt--;
        }

        return ans;
    }
};
