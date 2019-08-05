class Solution {
    public List < Integer > splitIntoFibonacci(String S) {
        int N = S.length();
        for (int i = 1; i != 10 && i != N; i++) { //max is halfway
            for (int j = i + 1; j != i + 10 && j <= N; j++) { //if only 3 nums, third (N-j)'s digits should be at least as much as the first(i) and the second(j-i)
                // System.out.println(i+", "+j);
                if (S.charAt(0) == '0' && i != 1) continue; //if first num violates '0-rule'
                List < Integer > temp = judge(i, j, S);
                if (!temp.isEmpty()) return temp;

            }
        }
        return new ArrayList < Integer > ();
    }

    List < Integer > judge(int a, int b, String str) {
        int N = str.length();
        List < Integer > res = new ArrayList < > ();
        int st = 0;
        long anum = 0, bnum = 0;
        while (b <= N) {
            // System.out.println(res);
            if (str.charAt(a) == '0' && b > a + 1) return new ArrayList < Integer > (); //a=first ind of bnum, also checks if the number isn't just 0 (length > 1)
            anum = Long.parseLong(str.substring(st, a));
            bnum = Long.parseLong(str.substring(a, b));
            if (anum > Integer.MAX_VALUE || bnum > Integer.MAX_VALUE) return new ArrayList < Integer > (); //all must be integers
            // System.out.println("*****"+anum+", "+bnum);
            res.add((int) anum); //only need to add one num
            String exp = anum + bnum + "";
            int len = exp.length();
            if (b == N) break;
            if (!str.substring(b, Math.min(b + len, N)).equals(exp)) return new ArrayList < Integer > (); //sometimes b+len > N, indexing-bounds errors
            st = a;
            a = b;
            b = b + len; //shift boundaries over one num

        }
        res.add((int) bnum);
        // System.out.println(res);
        if (b != N || res.size() < 3) return new ArrayList < Integer > ();
        return res;
    }
}
