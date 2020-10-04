/*
Approach:- we are given an array of numbers in range 0<=a[i]<=1000, so we have to create an array to
store the count of occurence of each element, then we have to traverse the array and store the count
of each element's occurences ex:- [1
,1,2,2] , {1:2, 2:2} etc,
*/


class Solution {
public:
 int countElements(vector<int>& arr) {
     sort(arr.begin(), arr.end());
     int ans = 0;
     int prv = -1,prv_count = 0;
     for(int i : arr){
         if(i == prv){
             prv_count++;
             
         }
         else{
             if(i== prv+1){
                 ans =ans + prv_count;
             }
             prv = i;
             prv_count = 1;
         }
     }
     return ans;
   
}
};