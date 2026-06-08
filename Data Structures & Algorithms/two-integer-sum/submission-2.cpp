class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
   
        vector<int> ans;
        unordered_map<int, int> p;

        for(int i = 0; i < nums.size(); i++){

          
                int op = target - nums[i];
                if(p.find(op) != p.end()){
                    ans.push_back(p[op]);
                    ans.push_back(i);
                    break;
                }
            
            p[nums[i]] = i;

        }
        
        return ans;
    }
};
