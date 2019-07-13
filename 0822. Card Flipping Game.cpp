class Solution {
    public:
        int flipgame(vector < int > & fronts, vector < int > & backs) {
            unordered_set < int > safe;
            bool bad[2001] = {
                false
            }; //must initialize to false
            // for(bool b:bad)cout<<b;
            for (int i = fronts.size() - 1; i != -1; i--) { //vectors have size, not length
                if (fronts[i] == backs[i]) { //cards that cannot work have the same value front back
                    //unlimited flips = ensures that any non-bad card can be flipped so that all of its kind are on one side. 
                    safe.erase(fronts[i]); //insert and erase for sets in c++
                    bad[fronts[i]] = true;
                    continue;
                }
                if (!bad[fronts[i]]) safe.insert(fronts[i]); //only call it safe if it hasn't been marked as bad before
                if (!bad[backs[i]]) safe.insert(backs[i]);
            }
            int res = INT_MAX;
            for (unordered_set < int > ::iterator it = safe.begin(); it != safe.end(); ++it)
                res = min(res, * it); //O(N) iteration + O(1) addition and removal is better than O(1) retrieval for first elem + O(logN) addition and removal (for an ordered set)
            return safe.empty() ? 0 : res; //if safe is empty, no good number exists
        }
};
