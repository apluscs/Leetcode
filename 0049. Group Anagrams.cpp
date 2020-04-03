class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        int N = strs.size();
        unordered_map<string, int> mp;
        int count = 0;
        for(string str : strs){
            string temp = get_id(str);  // hash the string
            if(mp.count(temp) == 0){
                mp[temp] = count++;
                res.push_back({});
            }
            res[mp[temp]].push_back(str);
        }
        return res;
    }
    
    string get_id(string& str){
        string res = "";
        vector<int> frq(26);
        for(char c: str){
            frq[c - 'a']++;
        }
        for(int f : frq)
            res += to_string(f) + ",";  // turn frq into a string
        return res;
    }
};
