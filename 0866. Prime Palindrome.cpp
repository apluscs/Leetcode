class Solution {
    public:

        int primePalindrome(int N) {
            if(N==10||N==11) return 11;
            while(true){
                if(reverse(N)&&isPrime(N)) return N;
                N++;
                if (100000<N&&N<1000000) N=1000000; //skips over all 8-digit palindromes
                else if(10000000 < N && N < 100000000)  //skips over all 8-digit palindromes
                    N = 100000000;  //judging these 2 ^ cases is the fastest medium
            }
        }
        
        int primePalindromeSLOW(int N) {
            if (N == 10 || N == 11) return 11;
            int numDig = 1, base = 10; //track how many digits in N
            while (base <= N) {
                base *= 10;
                numDig++;
            } //now base is next level of 10^n greater than N
            // cout<<numDig<<endl;
            while (true) {
                if (numDig % 2 == 0) { //no even digit palindromes are prime (except 11)
                    N = base;
                    base *= 10;
                    numDig++; //so jump to next 10^n
                }
                if (reverse(N) && isPrime(N)) return N;
                N++;
            }
        }

        bool isPrime(int num) {
            if (num == 1) return false;
            int root = (int) sqrt(num);
            for (int i = 2; i <= root; i++)
                if (num % i == 0) return false;
            return true;
        }

        bool reverse(int num) {
            int mem = num, res = 0;
            while (num != 0) {
                res = 10 * res + (num % 10);
                num /= 10;
            }
            // cout<<"reversed: "<<res<<", "<<mem<<endl;
            return mem == res;
        }
};
