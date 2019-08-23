class Solution {
    public:
        const int MAX = 1000000001;
        bool reorderedPowerOf2(int N) {
            int pow = 1;
            vector < int > Nfrq = getFrq(N);
            while (pow < MAX) { //try each power of 2
                vector < int > frq = getFrq(pow);
                bool flag = false;
                // cout<<pow<<endl;
                for (int i = 0; i != 10; i++) {
                    // cout<<frq[i]<<", ";
                    if (frq[i] != Nfrq[i]) {
                        flag = true;
                        break; //mismatch in frq of digit i found
                    }
                }
                if (!flag) return true;
                pow <<= 1;
                // cout<<endl;
            }
            return false;
        }

        vector < int > getFrq(int num) {
            vector < int > res(10); //"C++ does not advocate to return the address of a local variable to outside of the function 
            //so you would have to define the local variable as static variable."
            while (num != 0) { //create a frq[] of digits of this num
                int d = num % 10;
                res[d]++;
                num /= 10;
            }
            return res;
        }
};
