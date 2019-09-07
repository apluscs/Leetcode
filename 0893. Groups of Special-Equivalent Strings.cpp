class Solution {  //not terribly fast, better way is to have a set<pair<string,stirng>> where first is odd-indexes and second is even. 
    public: //both are sorted
        int numSpecialEquivGroups(vector < string > & A) {
            int N = A.size(), count = 0, res = 0;
            while (count != N)
                for (int i = 0; i != N; i++) {
                    if (A[i] == "") continue; //A[i] is the start of a new group
                    res++;
                    count++;
                    for (int j = i + 1; j != N; j++)
                        if (A[j] != "" && same(A[i], A[j])) { //see if A[j] can be added to this group
                            count++;
                            A[j] = ""; //remove
                        }
                    A[i] = ""; //mark as removed, A[i] is the base
                }
            return res;
        }

        bool same(string base, string curr) {
            int M = base.length();
            int frq[26] = { 0 };
            // cout<<base<<", "<<curr<<endl;
            for (int i = 0; i < M; i += 2) frq[base[i] - 'a']++;

            for (int i = 0; i < M; i += 2) { //only similar if the set of even-index chars are all the same, and 
                frq[curr[i] - 'a']--;
                if (frq[curr[i] - 'a'] < 0) return false;
            } //frq should be all 0's now 
            for (int i = 1; i < M; i += 2) frq[base[i] - 'a']++;
            for (int i = 1; i < M; i += 2) { //the set of odd-index chars are the same 
                frq[curr[i] - 'a']--;
                if (frq[curr[i] - 'a'] < 0) return false;
            }
            return true;
        }
};
