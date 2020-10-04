/* Approach->
   We will take cummulative multiplication value moving fom
   left to right and we will store it in output array.
   Now we need to store information about right hand side
   multiplication so we will traverse from last element
   and update the output variable.
   And we will keep track of product variable which is 
   intialised as 1.
   product=1
   product = product*nums[i]

   For boundary condition, output[0]=product

NOTE->The Output Array doesn't count as extra array for the purpose 
of Space Complexity Analysis (Mentioned in the Question itself).
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> output;
        if(n<1)
            return output;
        
        int product = 1;
        for(int i=0;i<n;++i)
        {
            product *= nums[i];
            output.push_back(product);            
        }
        
        //Traverse from right and update output array
        product = 1;
        for(int i=n-1;i>0;--i)
        {
            output[i] = output[i-1]*product;
            product *= nums[i];
        }
        output[0] = product; // for boundary condition when there is no element at left side of 0th index
        
        return output;
    }
};