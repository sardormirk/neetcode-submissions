class Solution {
public:


    string encode(vector<string>& strs) {
        string enc = "";

        for(string x : strs){
            enc += to_string(x.size()) + '#';
            enc += x;
        }

        return enc;
    }

    vector<string> decode(string s) {

        vector<string> res;
        
        int i = 0;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }

            int size = stoi(s.substr(i, j-i));
            string w = s.substr(j+1, size);
            res.push_back(w);

            i = size + j + 1;

        }

        return res;
    }
};
