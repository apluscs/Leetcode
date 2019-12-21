//Do better next time: https://leetcode.com/problems/multiply-strings/discuss/17769/One-Easy-solution-with-C%2B%2B
//This tracks the sum in each digit place

class Solution {
    public:
        string multiply(string num1, string num2) {
            if (num1 == "0" || num2 == "0") return "0";
            string res = "";
            int base = 0, N = num1.length();
            for (int i = N - 1; i != -1; i--) {
                res = add(res, helper(num1[i] - '0', num2, base));
                base++;
            }
            return res;
        }

    string add(string a, string b) {
        int N = a.length(), M = b.length(), i = N - 1, j = M - 1, carry = 0;
        string res = "";
        while (i != -1 && j != -1) { //digits both strings have in common
            int sum = a[i] - '0' + b[j] - '0' + carry;
            res = to_string(sum % 10) + res;
            carry = sum / 10;
            i--;
            j--;
        }
        while (i != -1) { //if a is longer
            int sum = a[i] - '0' + carry;
            res = to_string(sum % 10) + res;
            carry = sum / 10;
            i--;
        }
        while (j != -1) { //if b is longer
            int sum = b[j] - '0' + carry;
            res = to_string(sum % 10) + res;
            carry = sum / 10;
            j--;
        }
        if (carry != 0) res = to_string(carry) + res;
        // cout<<"added "<<a<<" and "<<b<<" = "<<res<<endl;
        return res;
    }

    string helper(int m, string num, int base) { //multiplies a digit by num
        int carry = 0, N = num.length();
        string res = "";
        for (int i = 0; i != base; i++) res += "0"; //number of trailing 0's
        for (int i = N - 1; i != -1; i--) {
            int c = num[i] - '0', prod = c * m + carry;
            res = to_string(prod % 10) + res;
            carry = prod / 10;
        }
        if (carry != 0) res = to_string(carry) + res;
        // cout<<res<<endl;
        return res;
    }
};
