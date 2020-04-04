class Solution {
public:
    int maxSatisfaction(vector<int>& sats) {
        sort(sats.begin(), sats.end()); // want the tastiest dishes served last
        int N = sats.size();
        for(int i = N - 2; i != -1; --i){ // suffix sum
            sats[i] += sats[i + 1];
        }
        for(int i = N - 2; i != -1; --i){ // calculating 1 * sats[i] + 2 * sats[i+1] + 3 * sats[i+2] ...
            sats[i] += sats[i + 1];
        }
        int res = 0;
        for(int num : sats)
            res = max(res, num);
        return res;
    }
};


