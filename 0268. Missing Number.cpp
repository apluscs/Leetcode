class Solution {
    public:
        int missingNumber(vector < int > & nums) {
            int N = nums.size();
            bool * toVis = new bool[N + 1]; //idk hopefully this gets cleaned up
            for (int i = 0; i != N + 1; i++) toVis[i] = false;
            for (int num: nums) toVis[num] = true;
            for (int i = 0; i != N + 1; i++)
                if (!toVis[i]) return i;
            return -1;
        }
};

class Solution2 {
    public:
        int missingNumber(vector < int > & nums) {
            unordered_set < int > toVis;  //costly in time and space for a problem this trivial
            int N = nums.size(), res = 0;
            for (int i = 0; i <= N; i++) toVis.insert(i); //everything we should be in nums
            for (int num: nums) toVis.erase(num);
            for (int num: toVis) res = num; //should only be one left
            return res;
        }
};
