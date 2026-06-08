class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> c;
        vector<vector<int>> freq(nums.size()+1);
        vector<int> ans;

        for(int x : nums){
            c[x]++;
        }

        for(auto kv : c){
            freq[kv.second].push_back(kv.first);
        }
        
        for(int i = freq.size()-1; i>=0; i--){
            for(int x : freq[i]){
                ans.push_back(x);
                if(ans.size() == k){
                    return ans;
                }
            }
        }

        return ans;
    }
};
