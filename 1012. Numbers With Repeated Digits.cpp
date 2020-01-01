class Solution {
    public:
        int numDupDigitsAtMostN(int N) {
            int k = 0, res = 0;
            if (N < 11) return 0;
            for (int i = N; i != 0; i /= 10) k++; // count # digits
            vector < int > nums(k, 0), dp(k - 1, 0), count(10, 0), dp2(k, 0); // get digits of N
            for (int i = k - 1, j = N; i != -1; i--, j /= 10)
                nums[i] = j % 10;

            for (int i = 0; i != k - 1; i++) {
                dp[i] = i == 0 ? 9 : dp[i - 1] * (10 - i); // # nonrepeated from 
                res += dp[i];
            }
            for (int num: dp) cout << num << " ";
            bool duplicate = false;
            for (int i = 0; i != k; i++) {
                dp2[i] = i == 0 ? 9 : dp2[i - 1] * (10 - i);
                if (duplicate) continue;
                int diff = 0;
                for (int j = nums[i] + 1; j < 10; j++)
                    diff += count[j] == 0; //
                dp2[i] -= diff; // so confused about this part
                count[nums[i]]++;
                if (count[nums[i]] > 1) duplicate = true;
            }
            for (int num: dp2) cout << num << " ";
            return N - res - dp2[k - 1];

        }
};
