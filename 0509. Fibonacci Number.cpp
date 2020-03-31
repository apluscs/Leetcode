class Solution {
public:
    int fib(int N) {
        int count = 0, p2 = 0, p1 = 1;
        while(count != N){
            int curr = p1 + p2;
            p2 = p1;
            p1 = curr;
            count++;
        }
        return p2;
    }
};
