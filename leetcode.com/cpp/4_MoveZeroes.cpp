/*
  Approach 1:
           In this first we take a nxt as a pointer which points to a location in the array.
           It is first initialized to ZERO.
           Then moving from LEFT to RGHT in the array, we check for the non-zero element
           if we find the non-zero element then we will swap the values in the array for the pointer 
           'nxt' with the iterator 'x' and then we increment the pointer 'nxt' by 1.
           After the end of the first for loop, another for loop is taken, which will mark ZEROES at the
           end of the array. 


*/


class Solution {
public:
 void moveZeroes(vector<int>& nums) {
     int n = nums.size();
     int nxt =0;
    for (int x = 0; x < n; x++) {
        if(nums[x]!= 0){
            nums[nxt] = nums[x];
            nxt++;
        }
    }
     for(int i = nxt; i < n;i++){
         nums[i] = 0;
     }
}
};

/*APPROACH 2:
       USING SINGLE for Loop
       In this we will take i,j as two pointers which are initialized as 0.
       We will use the pointers to point at the index and iterate over the array from left to right
       and check for non-zero element and if found then
       we will swap the values in the array the pointers are pointing at that instance.


*/       

class Solution {
public:
 void moveZeroes(vector<int>& nums) {
    for (int i = 0, j = 0; j < nums.size(); j++) {
        if (nums[j] != 0) {
            swap(nums[i++], nums[j]);
        }
    }
}
};

