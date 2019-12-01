class Solution {
    public:
        vector < string > generateParenthesis(int n) {
            vector < string > res;
            helper("", 0, 0, n, res);
            return res;
        }

    void helper(string str, int open, int closed, int n, vector < string > & res) {
        if (open < closed || open > n) return; //never have a surplus of closed, nor should you have more ( than n
        if (open == closed && open == n) { //perfection found
            res.push_back(str);
            return;
        }
        helper(str + '(', open + 1, closed, n, res); //tack on (
        helper(str + ')', open, ++closed, n, res); //tack on )
    }
};
