class Solution {
    public String maskPII(String S) {
        int anc = S.indexOf('@');
        if (anc != -1) { //email, not phone number
            char c1 = S.charAt(0), c2 = S.charAt(anc - 1);
            if (c1 < 'a') c1 += 'a' - 'A';
            if (c2 < 'a') c2 += 'a' - 'A';
            return c1 + "*****" + c2 + S.substring(anc).toLowerCase();
        }
        int len = 0, N = S.length();
        String nums = "";
        for (int i = 0; i != N; i++) {
            char c = S.charAt(i);
            if (c >= '0' && c <= '9') { //store all numeric chars
                len++;
                nums += c;
            }
        }
        // System.out.println(nums);
        String res = len > 10 ? "+" : "";
        for (int i = len; i != 10; i--) //country code (>10) chars
            res += '*';
        if (len > 10) res += '-'; //extra dash only for country code phone #s
        res += "***-***-" + nums.substring(len - 4);
        return res;
    }
}
