class Solution {
    public:
        int maxDistToClosest(vector < int > & seats) {
            int N = seats.size();
            int dist[N];
            fill_n(dist, N, 20001); //20001 > max distance possible
            if (seats[0]) dist[0] = 0;
            for (int i = 1; i != N; i++) {
                if (seats[i]) dist[i] = 0; //person here :P
                else dist[i] = dist[i - 1] + 1; //one more seat away from nearest person to my left
            }
            // for(int d:dist)cout<<d<<'\t'; cout<<endl;
            if (seats[N - 1]) dist[N - 1] = 0;
            int res = dist[N - 1]; //starting point
            for (int i = N - 2; i != -1; i--) {
                if (!seats[i]) dist[i] = min(dist[i], dist[i + 1] + 1); //min dist from nearest person to left and right
                res = max(res, dist[i]); //want to find the loneliest spot
            }
            // for(int d:dist)cout<<d<<'\t'; cout<<endl;
            return res;
        }
};
