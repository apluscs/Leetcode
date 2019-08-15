class Solution {
    public:
        const int res[2][2] = { {-1, 2 }, { 0, 1 } };
    //vert odd = right side; horz odd=bottom, 0 0=left top, 0 1=left bot, 1 0=right top
    int mirrorReflection(int p, int q) {
        int g = gcd(q, p); //smaller num first
        p = (p / g) % 2;
        q = (q / g) % 2; //reduce p and q to their ratio in simplest form = proportion of distance traveled (measured in layed out squares)
        // cout<<"p: "<<p<<", q: "<<q<<endl<<g;
        return res[p][q]; //
    }

    int gcd(int a, int b) {
        // cout<<a<<", "<<b<<endl;
        if (a == 0) return b;
        return gcd(b % a, a);
    }
};
