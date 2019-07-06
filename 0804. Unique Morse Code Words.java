class Solution {
    final String[] code = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
    public int uniqueMorseRepresentations(String[] words) {
        HashSet < String > res = new HashSet < > ();
        for (String w: words)
            res.add(toMorse(w));
        return res.size();
    }
    String toMorse(String str) {
        StringBuilder sb = new StringBuilder();
        for (char c: str.toCharArray())
            sb.append(code[c - 'a']);
        return sb.toString();
    }
}
