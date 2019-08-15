class Solution {
    public:
        bool buddyStrings(string A, string B) {
            int N = A.length(), incon = -1;
            int frq[26] = { 0 };
            bool found = false;
            if (B.length() != N) return false;
            for (int i = 0; i != N; i++)
                if (A[i] != B[i])
                    if (incon == -1) incon = i; //first inconsistency, mark the spot
                    else if (incon == -2) return false; //third inconsistency
            else if (A[i] == B[incon] && B[i] == A[incon]) incon = -2; //we know incon is index of first inconsistency, see if second matches that
            else return false; //second inconsistency is not a perfect match
            else if (!found) {
                frq[A[i] - 'a']++;
                if (frq[A[i] - 'a'] == 2) found = true;
            }
            return incon == -2 || incon == -1 && found; //2 matched inconsistencies OR none and at least 2 of at least one letter
        }
};
