class Solution {
    public:
        int subarrayBitwiseORs(vector < int > & A) {
            unordered_set < int > res, curr;
            for (int num: A) { //iterates through each answer up to i only ONCE, as opposed to what you'd do if you had a N*N matrix
                unordered_set < int > temp;
                for (int c: curr) temp.insert(c | num); //OR'ing with all subarrays reaching i-1, where i is the index of num
                temp.insert(num); //subarrays with size=1 count too
                curr = temp; //update range for curr
                for (int c: temp) res.insert(c);
            }
            return res.size();
        }
};
