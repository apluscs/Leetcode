class Solution {
    public boolean validTicTacToe(String[] board) {
        int xwin = 0, owin = 0;
        for (int i = 0; i != 3; i++) {
            if (board[i].equals("XXX")) xwin++; //horz
            else if (board[i].equals("OOO")) owin--;
            if (board[0].charAt(i) == 'X' && board[1].charAt(i) == 'X' && board[2].charAt(i) == 'X') xwin++; //vert win
            else if (board[0].charAt(i) == 'O' && board[1].charAt(i) == 'O' && board[2].charAt(i) == 'O') owin--;
        }

        if (board[0].charAt(0) == 'X' && board[1].charAt(1) == 'X' && board[2].charAt(2) == 'X') xwin++; //diag \
        else if (board[0].charAt(0) == 'O' && board[1].charAt(1) == 'O' && board[2].charAt(2) == 'O') owin--;
        if (board[0].charAt(2) == 'X' && board[1].charAt(1) == 'X' && board[2].charAt(0) == 'X') xwin++; //diag /
        else if (board[0].charAt(2) == 'O' && board[1].charAt(1) == 'O' && board[2].charAt(0) == 'O') owin--;

        int x = 0, o = 0;
        for (int i = 0; i != 3; i++) //count number of x and o
            for (int j = 0; j != 3; j++) {
                if (board[i].charAt(j) == 'X') x++;
                else if (board[i].charAt(j) == 'O') o++;
            }
        //no way for X to win 3 way and have a "balance" between x and o
        if (xwin != 0 && owin != 0 || owin < -1 || owin == -1 && x != o || xwin != 0 && x != o + 1) return false;
        //only x can win twice; if o wins, x must = o; if x wins, x must = o+1
        return o > x || x > o + 1 ? false : true;
    }
}
