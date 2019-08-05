class Solution {
    public:
        bool isNStraightHand(vector < int > & hand, int W) {
            int N = hand.size();
            if (N % W != 0) return false;
            map < int, int > map;
            for (int num: hand) map[num]++;

            // for(auto it = map.cbegin(); it != map.cend(); ++it){
            //     cout << it->first << " " << it->second << "\n";
            // }
            for (int i = N / W; i != 0; i--) { //minimum # always starts the group
                int start = map.cbegin() - > first; //you never know if a "middle" # lies in the middle of a 
                for (int j = start; j != start + W; j++) { //group, but the smallest # always will lie at the
                    // cout<<j<<", ";   beginning of one
                    if (map[j] == 0) return false; //don't have a card we NEED
                    map[j]--;
                    if (map[j] == 0) map.erase(j); //
                }
            }
            return true;
        }
};
