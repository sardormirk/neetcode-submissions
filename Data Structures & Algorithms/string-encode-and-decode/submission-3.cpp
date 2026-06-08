class Solution {
public:

    // 5#abcde13#abc
    string encode(vector<string>& strs) {

        string encoded_string;
        for (const auto& str : strs)
        {
            int str_len = str.length();
            encoded_string += to_string(str_len) + '#' + str;
        }

        return encoded_string;
    }

    vector<string> decode(string s) {

        vector<string> decoded_strs;
        int start = 0;
        while (start < s.length())
        {
            int hash_pos = s.find('#', start);
            int curr_length = stoi(s.substr(start, hash_pos - start));
            start = hash_pos + 1;
            
            if (curr_length == 0)
            {
                decoded_strs.push_back(""); 
            }
            else
                decoded_strs.push_back(s.substr(start, curr_length));
            
            start += curr_length;
        }
        return decoded_strs;
    }
};