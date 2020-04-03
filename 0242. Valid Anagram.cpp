class Solution {
public:
    bool isAnagram(string s1, string s2) {
        int N = s2.length(), M = s1.length();
        vector<int> frq(26);    // total_diff tracks the sum of all absolute values of frq's elems
        vector<int> res;
        if(N != M) return false;
        for(char c: s1)
            frq[c - 'a']++;
        for(char c: s2)
            frq[c - 'a']--;
        for(int f : frq)
            if(f != 0) return false;
        return true;
    }
};
