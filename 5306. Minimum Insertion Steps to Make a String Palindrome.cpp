class Solution {
public:
    int minInsertions(string str) {
        int n=str.length();
        vector<vector<int>> table(n, vector<int>(n));   // for dp
        int l, h, gap;  
        for ( gap = 1; gap < n; ++gap)  // how far col is from row
            for (l = 0, h = gap; h < n; ++l, ++h)  // same char? then just need inside [l+1, h-1] to be palindrome
                table[l][h] = (str[l] == str[h])?   table[l + 1][h - 1] : (min(table[l][h - 1], table[l + 1][h]) + 1);      
        return table[0][n - 1];  // else need to put str[l] after str[h] or str[h] before str[l]
    }
};
