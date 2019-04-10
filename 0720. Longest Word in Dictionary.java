class Solution {
    public static Node root;
    public static String res;
    public String longestWord(String[] words) {
        res = "";
        root = new Node();
        for (String w: words) {
            int len = w.length();
            Node curr = root;
            for (int i = 0; i != len; i++) {
                int c = w.charAt(i) - 'a';
                if (curr.children[c] == null) curr.children[c] = new Node();
                curr = curr.children[c];
                if (i == len - 1) curr.end = true;
            }
        }
        dfs(root, new StringBuilder());
        return res;
    }
    public static void dfs(Node curr, StringBuilder sb) {
        // System.out.println(sb.toString()+", current");
        for (int i = 0; i != 26; i++) {
            if (curr.children[i] != null && curr.children[i].end) { //only continues if this kid represents a complete word
                sb.append((char)(i + 'a'));
                if (sb.length() > res.length()) res = sb.toString();
                dfs(curr.children[i], sb);
                sb.deleteCharAt(sb.length() - 1); //remove last char
            }
        }
    }
    public static class Node {
        Node[] children;
        boolean end;
        public Node() {
            children = new Node[26];
        }
    }
}
