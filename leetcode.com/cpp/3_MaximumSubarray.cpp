/* For this problem, there are three approaches:
- Approach 1 O(n^3) Time Solution
   - We take the subarray of the input array and further calculates the sum of the subarraysand
     calculate maximum of the sum and the new subarray element. 
     While not changing the left bound,means we go all the way back to the first element 
     to calculate the sum of the new subarray. 
- Approach 2 O(n^2) Time Solution
    - It is quite similar than approach 1, except we don't go all the way back to the left bound,
     else we take the sum calculated of the previous subarray we took and further adds it with the
     new subarray element and calculates maximum of it.
- Approach 3 O(n) Solution (Kadane's Algorithm)
  - This approach works linearly based on time and space complexity.
- - - maxSum[i] = max( A[i], A[i] + maxSum[i - 1] )
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(); //Size Of the Array
        int local_max= 0;
        int max_sum = INT_MIN;  //-INFINITY or integer cannot store below this limit
        for(int i=0; i<n; i++){
            local_max = max(nums[i], nums[i] + local_max);
            if( local_max > max_sum){
                max_sum = local_max;
            }
        }
       return max_sum; 
    }     
};