class Solution {
    public String toLowerCase(String str) {
        int N = str.length();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i != N; i++) {
            char c = str.charAt(i);
            if (c <= 'Z' && c >= 'A') c += 32; //difference between lower and uppercase ASCII values
            sb.append(c);
        }
        return sb.toString(); //SB's are faster
    }
}
