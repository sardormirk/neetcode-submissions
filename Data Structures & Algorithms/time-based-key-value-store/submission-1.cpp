class TimeMap {
public:

    unordered_map<string, vector<pair<int, string>>> events;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        events[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto value_it = upper_bound(events[key].begin(), events[key].end(), timestamp, 
        [](const auto &ts, const auto &p) 
        {
            return ts < p.first;
        });
        return (value_it == events[key].begin() ? "" : prev(value_it)->second);
    }
};
