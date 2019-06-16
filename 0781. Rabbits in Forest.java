class Solution {
    public int numRabbits(int[] answers) {
        int[] map = new int[1000];
        int res = 0;
        for (int a: answers) map[a]++; //frequency 
        // System.out.println(Arrays.toString(map));
        for (int a = 0; a != 1000; a++) {
            if (map[a] == 0) continue; //a+1=group size
            int gr = map[a] / (a + 1) + (map[a] % (a + 1) == 0 ? 0 : 1); //if leftovers, add another group
            // System.out.println(a+", "+gr);
            res += gr * (a + 1); //group * number of rabbits/group
        }
        return res;
    }
}
