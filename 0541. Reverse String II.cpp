class Solution {
    public:
        string reverseStr(string str, int k) {
            int N = str.length();
            for (int i = 0; i < N; i += k) { // start of segment
                if (i % (2 * k) == k) continue; // on a non-reversing segment
                reverse(str, i, min(N - 1, i + k - 1)); // less than k left (at the end)
            }
            return str;
        }

    void reverse(string & str, int start, int end) {
        int N = end - start + 1;
        for (int i = 0; i != N / 2; i++) {
            int temp = str[start + i]; // swap, offset by start
            str[start + i] = str[N - 1 - i + start];
            str[N - 1 - i + start] = temp;
        }
    }
};
