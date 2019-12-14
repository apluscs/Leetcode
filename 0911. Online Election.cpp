class TopVotedCandidate {
    public:
        unordered_map < int, int > winning;
    vector < int > times;

    TopVotedCandidate(vector < int > & persons, vector < int > & times) {
        unordered_map < int, int > total_votes;
        int best = persons[0]; //tracks winning cand at each time
        for (int x = 0; x < persons.size(); x++) {
            total_votes[persons[x]]++;
            if (total_votes[persons[x]] >= total_votes[best]) {
                best = persons[x]; //update best
            }
            winning[times[x]] = best;
        }
        this - > times = times;
    }

    int q(int t) { //binary search        
        int low = 0;
        int high = times.size() - 1;
        while (low <= high) {
            int mid = (high + low) / 2;
            if (t == times[mid])
                return winning[times[mid]];
            if (t < times[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return winning[times[high]]; //guaranteed to be less than t
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
