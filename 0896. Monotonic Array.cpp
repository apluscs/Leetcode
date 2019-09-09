class Solution {
    public:
        bool isMonotonic(vector < int > & A) {
            int N = A.size();
            if (N == 1) return true;
            int dir = A[0] - A[1] > 0 ? -1 : A[0] - A[1] < 0 ? 1 : 0; //-1 if dec, 1 if inc, 0 if stagnant
            // cout<<dir<<endl;
            for (int i = 1; i != N - 1; i++) {
                int nd = (A[i + 1] - A[i]) * dir; //if nd positive OR nd==0 && dir==0
                // cout<<nd<<endl;
                if (dir == 0 && A[i + 1] - A[i] != 0)
                    dir = A[i] - A[i + 1] > 0 ? -1 : A[i] - A[i + 1] < 0 ? 1 : 0; //ex. [2,2,2,1,4,5], need to find first instance of inc/dec
                if (nd < 0) return false;
            }
            return true;
        }
};
