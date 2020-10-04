/*Approach->
  We wiil iterate through the given string and calulate effectivev rotations by assuming
  '-x' and '+x' where we add -x for left rotations and +x for right rotations.
  And further we will do Modulus of the values to calclute effective rotations
  EF=(-x+x) % length of string 
  Then we take a substfunction and slice tghe given 
  string by EF value.

  Time Complexity-O(N+Length of String)
*/



class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        
        int val = 0;   //stores value of effective rotation
        
        for(int i=0;i<shift.size();++i)
            val += shift[i][0]==0?-shift[i][1]:shift[i][1];
        
        int len = s.length();
        val %= len;  //calculating effective rotation value
        
        string result = "";
        if(val>0)   //Right rotation
            result = s.substr(len-val,val) + s.substr(0,len-val);
        else        //Left rotation
            result = s.substr(-val,len+val) + s.substr(0,-val);
        
        return result;
    }
};