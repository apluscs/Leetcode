class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.length())  // cannot partition that small
            return false;
        unordered_map<char, int> frq;
        for(char c : s)
            frq[c]++;
        int count = 0;
        for(auto p : frq)
            if(p.second % 2 == 1)
                count++;    // count how many chars with odd frequencies
        return count <= k;  // at most 1 odd-frequency char per palindrome
    }
};
