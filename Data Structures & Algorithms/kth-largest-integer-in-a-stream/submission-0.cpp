class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> min;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (const auto& num : nums)
        {
            min.emplace(num);
            if (min.size() > k)
            {
                min.pop();
            }
        }
    }
    
    int add(int val) {
        min.push(val);
        if(min.size() > k)
        {
            min.pop();
        }

        return min.top();
    }
};
