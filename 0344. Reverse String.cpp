class Solution {
    public:
        void reverseString(vector < char > & s) {
            int N = s.size();
            for (int i = 0; i != N / 2; i++) {
                int temp = s[i]; // reflected partner
                s[i] = s[N - 1 - i];
                s[N - 1 - i] = temp; // swap the two
            }
        }
};
