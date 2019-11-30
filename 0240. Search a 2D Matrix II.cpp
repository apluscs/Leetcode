class Solution {
    public:
        bool searchMatrix(vector < vector < int >> & matrix, int target) {
            int N = matrix.size();
            if (N == 0) return false;
            int i = 0, j = matrix[0].size() - 1;
            while (i != N && j != -1) {
                if (matrix[i][j] == target) return true;
                if (matrix[i][j] < target) i++; //elim one row
                else j--; //or col every time
            }
            return false;
        }
};

class Solution2 {
    public:
        bool searchMatrix(vector < vector < int >> & matrix, int target) {
            if (matrix.size() == 0) return false; //annoying edge case... REMEMEMBER
            return helper(matrix, target, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
        }

    bool helper(vector < vector < int >> & matrix, int target, int rlow, int rhigh, int clow, int chigh) {
        if (rlow > rhigh || clow > chigh) return false;
        int i = (rlow + rhigh) / 2, j = (clow + chigh) / 2;
        // cout<<i<<" "<<j<<endl;
        if (matrix[i][j] == target) return true;
        if (matrix[i][j] > target) return helper(matrix, target, rlow, rhigh, clow, j - 1) || helper(matrix, target, rlow, i - 1, clow, chigh); 
        //search vert box to the left, horz box above
        else return helper(matrix, target, rlow, rhigh, j + 1, chigh) || helper(matrix, target, i + 1, rhigh, clow, chigh); 
        //search vert box to the right, horz box below
    }
};
