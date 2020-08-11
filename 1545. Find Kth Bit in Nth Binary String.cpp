class Solution {
public:
  char findKthBit(int n, int k) {
    bool flips=0; // default number
    while(n!=1){
      int len=(1<<n)-1;
      if(k==len/2+1){
        flips^=1; // changes the default to a '1' since that's where this was "born"
        break;
      }
      if(k>len/2){
        flips^=1; // if it flipped an odd #times, result is '1'
        k=len-k+1;  // point to corresponding index on LHS
      } 
      n--;
    }
    return flips?'1':'0';
  }
};
