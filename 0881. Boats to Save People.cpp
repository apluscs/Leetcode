class Solution {
    public:
        int numRescueBoats(vector < int > & people, int limit) {
            sort(people.begin(), people.end());
            int high = people.size() - 1, low = 0, res = 0;
            while (low < high) {
                if (people[low] + people[high] <= limit) low++; //2 people can fit on this boat
                high--; //always take care of heaviest person, light person is an accessory
                res++;
            }

            // cout<<low<<", "<<high<<endl;
            return res + (low == high); //if there is one guy left, low = high
        }
};
