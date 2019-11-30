class Solution {
    public:
        bool searchMatrix(vector < vector < int >> & matrix, int target) {
            int N = matrix.size(); //basically bin search but array is split
            if (!N) return false;
            int M = matrix[0].size(), low = 0, high = N * M - 1;
            while (low <= high) {
                int mid = (low + high) / 2, i = mid / M, j = mid % M; //strategy is to convert whatever index into coordinates
                // cout<<i<<" "<<j<<endl;
                if (matrix[i][j] == target) return true;
                if (matrix[i][j] < target) low = mid + 1;
                else high = mid - 1; //same rules as normal bin search
            }
            return false;
        }
};
