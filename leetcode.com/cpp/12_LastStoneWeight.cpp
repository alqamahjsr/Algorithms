/*
Approach->
Fist we will Make a priority queue which automatically arrange the element in sorted order.And
then pick the first element (which is maximum) and 2nd element(2nd max), if both are equal we dont have to push anything,
if not equal push difference of both in queue.
Do the above steps till queue size is equal to 1,then return last element. 
If queue becomes empty before reaching size==1 then return 0.
*/class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++)
        {
            pq.push(stones[i]);
        }
        int a,b;
        while(!pq.empty())
        {
            if(pq.size()==1)
                return pq.top();
            a=pq.top();
            pq.pop();
            b=pq.top();
            pq.pop();
            
            if(a!=b)
                pq.push(a-b);
        }
            return 0;
        
    }
};