class Solution {
    public:
        vector < int > majorityElement(vector < int > & nums) {
            vector < int > res;
            int a = 0, b = 0, ac = 0, bc = 0;
            for (int num: nums) { //find 2 most common nums
                if (a == num) ac++;
                else if (b == num) bc++;
                else if (ac == 0) { a = num;
                    ac = 1; } //last candidate is gone, suggest a new one
                else if (bc == 0) { b = num;
                    bc = 1; } //only if first candidate is already set
                else { ac--;
                    bc--; } //found some num that undermines both candidates
            }
            ac = bc = 0; //now count frequencies of both candidates
            for (int num: nums) {
                if (a == num) ac++;
                else if (b == num) bc++;
            }
            if (ac > nums.size() / 3) res.push_back(a);
            if (bc > nums.size() / 3) res.push_back(b);
            return res;
        }
};
