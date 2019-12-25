class Solution {
    public:
        vector < string > res;
        unordered_map < string, map < string, int >> adj;
    vector < string > findItinerary(vector < vector < string >> & tickets) {
        res.clear();
        adj.clear(); // only second layer of map is sorted, so we get lowest lexicographic answer
        for (vector < string > vec: tickets)
            adj[vec[0]][vec[1]]++;
        dfs("JFK"); //starting location
        return res;
    }

    bool dfs(string curr) {
        bool found = false;
        res.push_back(curr);
        for (pair < string, int > p: adj[curr]) {
            if (p.second == 0) continue; // this flight is invalid
            adj[curr][p.first]--; // let's use this flight
            if (!dfs(p.first)) return false; // nothing found in this trial, so stop
            adj[curr][p.first]++; // didn't work out, add it back for future DFSing
        }
        for (pair < string, map < string, int >> p: adj) { // iterate through all flights
            for (pair < string, int > pp: p.second)
                if (pp.second != 0) {
                    found = true; // still flights left we haven't used yet
                    break;
                }
            if (found) break;
        }
        if (found) res.erase(res.begin() + res.size() - 1); // didn't work out, erase the answer bit we just put in
        return found; // if no flights were found, we used them all up
    }
};
