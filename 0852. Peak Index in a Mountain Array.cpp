class Solution {
    public:
        int peakIndexInMountainArray(vector < int > & A) {
            for (int i = A.size() - 1; i != 0; i--)
                if (A[i - 1] < A[i]) return i; //we ascend and return when we detect a descent
            return -1; //should never happen
        }
};
