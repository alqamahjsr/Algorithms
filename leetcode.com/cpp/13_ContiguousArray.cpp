/*Approach->
Let us assume that all zeroes are replaced by -1. Then the subarray with equal number of 1 
and -1 would have had net sum equal to zero. To find subaarays with 0 sum, we add 1 in sum 
if current number of vector is 1 else we add -1. If we get the net sum of a certain subarray 
equal to zero,then it means it has equal occurances of the two numbers. We simply return 
the largest subarray with sum equals zero achieved.
*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int,int> mymap;
        int sum = 0;
        int longest_subarray = 0;
        
        for(int i=0;i<nums.size();++i)
        {
            sum += nums[i]==0?-1:1;
            
            if(sum==0)
            {
                if(longest_subarray < i+1)
                    longest_subarray = i+1;
            }
            else if(mymap.find(sum)!=mymap.end())
            {
                if(longest_subarray < i-mymap[sum])
                    longest_subarray = i-mymap[sum];
            }
            else
                mymap[sum] = i;
        }
        
        return longest_subarray;
    }
};





class Solution {
public:
  int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> up;
        int sum=0;
        up[0]=-1;
        int maxi=0;
        
        for(int  i=0;i<nums.size();i++){
            if(nums[i]==1){
                sum++;
                if(up.find(sum)!=up.end()){  
                    int temp=i-up[sum];
                    maxi=max(maxi,temp);
                }
                
                else{
                    up[sum]=i;
                }
            }
            else{
                sum--;
                if(up.find(sum)!=up.end()){
                    int temp=i-up[sum];
                    maxi=max(maxi,temp);
                }
                
                else{
                    up[sum]=i;
                }
            }
        }
        return maxi;
    }

};