class Solution {
    public:

        bool canVisitAllRooms(vector < vector < int >> & rooms) {
            int N = rooms.size();
            bool vis[N] = {
                false
            };
            dfs(0, rooms, vis);
            bool skipped = false;
            for (bool bo: vis)
                if (!bo) { //didn't visit this one
                    skipped = true;
                    break;
                }
            return !skipped; //if we didn't skip any, we were able to visit all rooms
        }

    void dfs(int curr, vector < vector < int >> & rooms, bool vis[]) {
        if (vis[curr]) return;
        vis[curr] = true;
        for (int nei: rooms[curr]) dfs(nei, rooms, vis);
    }
};
