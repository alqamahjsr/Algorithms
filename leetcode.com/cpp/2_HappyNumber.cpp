/* Approach:- We will keep splitting the digits and perform a^2+b^2....+m^2, and then perform the same operation with
the resultant,we will find a pattern that the sum of the digits of the number will either going to be equal to n or 1.
The idea is to loop until we either find 1 as sum or a number which is already present in the set
*/

class Solution {
public:
     bool isHappy(int n) {
        return checkIfHappy(n,n);      
    }
     bool checkIfHappy(int num,int n ){
        
         int sum=0;
         while(n>0){
         sum+=pow(n%10,2);
          n/=10;
         }
         if(sum==1){
          return true;
         }
        else if(sum==num||sum==145){
            return false ;  
           }
           else
               return checkIfHappy(num,sum);

}
};
