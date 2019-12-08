class Solution {
    public:
        double findMedianSortedArrays(vector < int > & A, vector < int > & B) {
            int M = A.size(), N = B.size();
            if (M > N) { //ensure m <= n
                vector < int > temp = A;
                A = B;
                B = temp;
                int tmp = M;
                M = N;
                N = tmp;
            }
            int imin = 0, imax = M, half = (M + N + 1) / 2;
            while (imin <= imax) {
                int i = (imin + imax) / 2, j = half - i;
                if (i < imax && B[j - 1] > A[i]) {
                    imin = i + 1; //i is too small
                } else if (i > imin && A[i - 1] > B[j]) {
                    imax = i - 1; //i is too big
                } else { //i is perfect
                    int maxLeft = 0;
                    if (i == 0) maxLeft = B[j - 1]; //nothing in A_left
                    else if (j == 0) maxLeft = A[i - 1]; //nothing in B_left
                    else maxLeft = max(A[i - 1], B[j - 1]);
                    if ((M + N) % 2 == 1) return maxLeft; //odd number = return mid elem, which is maxLeft

                    int minRight = 0;
                    if (i == M) minRight = B[j]; //nothing in A_right
                    else if (j == N) minRight = A[i]; //nothing in B_right
                    else minRight = min(B[j], A[i]);
                    return (maxLeft + minRight) / 2.0;
                }
            }

            return 0;
        }
};
