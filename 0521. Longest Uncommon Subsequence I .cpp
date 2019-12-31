class Solution {
    public:
        int findLUSlength(string a, string b) {
            return a == b ? -1 : max(a.length(), b.length());
        }
    // if they differ in the slightest, they are each subsequences of themselves the other doesn't have
};
