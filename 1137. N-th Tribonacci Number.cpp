class Solution {
public:
    int tribonacci(int n) {
        int count = 2, p3 = 0, p2 = 1, p1 = 1;
        if(n < 2) return n;
        while(count != n){
            int curr = p3 + p2 + p1;
            p3 = p2;
            p2 = p1;
            p1 = curr;
            count++;
        }
        return p1;
    }
};
