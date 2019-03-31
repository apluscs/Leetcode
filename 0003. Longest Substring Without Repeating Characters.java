class Solution {
public static int lengthOfLongestSubstring(String str) {
    boolean[] vis = new boolean[128];   //all possible chars
    int N = str.length();
    int res = 0;
    int start = 0, end = 0;
    while (end != N && start < N) {
      char c = str.charAt(end);
      if (vis[c]) {
        start = refresh(start, c, vis, str);    //shifts to exclude first instance of repeated char
        // System.out.println("char " + c + ", " + start + ", " + end);
      }
      vis[c] = true;
      res = Math.max(res, end - start + 1); //of this valid window
      end++;
    }
    // System.out.println(res);
    return res;
  }

  public static int refresh(int start, char c, boolean[] vis, String str) {
    while (start != str.length() && str.charAt(start) != c) {
      vis[str.charAt(start)] = false;
      start++;
    }   //now start is at first instance of c
    return start + 1;   //exclude that c
  }
}
