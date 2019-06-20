class Solution { //if manhattan distance from ghosts to target < from you to target you ded son
    public:
        bool escapeGhosts(vector < vector < int >> & ghosts, vector < int > & target) {
            int dist = abs(target[0]) + abs(target[1]);
            for (vector < int > g: ghosts) {
                int d = abs(target[0] - g[0]) + abs(target[1] - g[1]);
                if (d <= dist) return false;
            }
            return true;
        }
};
