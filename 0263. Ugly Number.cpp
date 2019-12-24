class Solution {
    public:
        bool isUgly(int i) {
            return i != 0 && helper(helper(helper(i, 2), 3), 5) == 1; //remove all factors of 2,  then 3, then 5
        }

    int helper(int num, int b) {
        while (num % b == 0) num /= b;
        return num;
    }
};
