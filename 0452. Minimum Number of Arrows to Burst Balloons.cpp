class Solution {
    public:
        int findMinArrowShots(vector < vector < int >> & points) {
            int arrow = INT_MIN, res = 0, N = points.size();
            sort(points.begin(), points.end(), compar);
            for (int i = 0; i != N; i++) {
                // cout<<points[i][0]<<" "<<points[i][1]<<endl;
                if (arrow != INT_MIN && arrow >= points[i][0]) continue;
                //make sure arrow is valid (shot at least once); then check if last shot arrow also sliced this one
                arrow = points[i][1]; //this one needs to get shot; slice at rightmost point greedily
                res++;
            }
            return res;
        }

    static bool compar(vector < int > & p1, vector < int > & p2) {
        return p1[1] != p2[1] ? p1[1] < p2[1] : p1[0] < p2[0];
    } //sort by end, if equal then start
};
