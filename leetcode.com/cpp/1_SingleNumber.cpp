/* Approach:-  XOR TABLE
               a   b   r
               0   0   0
               1   0   1
               0   1   1
               1   1   1 
If we do XOR of a number num with itself the resultant will always be 0,Ex:- 5^5=0,
Bit representation:- 
                        4  2  1
                        1  0  1      <----5
                           ^             XOR
                        1  0  1      <----5
                        0  0  0
Thus if we perform XOR:
               5^6^9^5^6^9:- THe result ill be 0;
 
 and if we have a unique number 'n' which is only present once in a group of duplicate 
 numbers then after performing XOR on all the number we will be left with only number 'n'
 Ex:- we have 8^6^8, then result will be 6
 
 Bit representation:-
                8 4 2 1
                1 0 0 0  <----8
                    ^        XOR
                0 1 1 0  <----6
                --------
                1 1 1 0 <-----14
                   ^         XOR
                1 0 0 0 <------8
                --------
                0 1 1 0 <------6 RESULT
 
Thus, in program we have the elments present 
in the array, and if we perform XOR with all the elements we will get our single unique number
*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a=0;
        for(int i=0;i < nums.size();++i)
            a ^= nums[i];
        
        return a;
    }
};