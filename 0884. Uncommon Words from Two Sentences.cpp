class Solution {
    public:
        vector < string > uncommonFromSentences(string A, string B) {
            unordered_map < string, int > map;
            istringstream iss(A + " " + B); //combine both strings
            vector < string > wrds(istream_iterator < string > { iss }, istream_iterator < string > ());
            for (string w: wrds) map[w]++; //count frq of each word
            vector < string > res;
            for (pair < string, int > p: map)
                if (p.second == 1) res.push_back(p.first); //only place into res if it occurs exaclty once
            return res;
        }
};
