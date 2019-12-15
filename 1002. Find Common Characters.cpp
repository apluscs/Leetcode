class Solution {
    public:
        vector < string > commonChars(vector < string > & words) {
            unordered_map < char, int > map;
            for (char c: words[0]) map[c]++;
            for (int i = words.size() - 1; i != 0; i--)
                map = intersect(map, words[i]); //narrow it down
            vector < string > res;
            for (pair < char, int > p: map)
                for (int i = 0; i != p.second; i++) res.push_back(string(1, p.first));
            return res;
        }

    unordered_map < char, int > intersect(unordered_map < char, int > & map, string str) {
        unordered_map < char, int > res;
        for (char c: str)
            if (map[c] > 0) {
                map[c]--;
                res[c]++; //res counts what's common
            }
        return res;
    }
};
