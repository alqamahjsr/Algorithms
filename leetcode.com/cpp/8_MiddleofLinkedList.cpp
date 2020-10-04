/*
Approach: We will take two pointers one is slow and other is fast. 
We will traverse the list with a pointer 'slow',the other pointer fast will
traverse twice as fast.
 When 'fast' reaches the end of the list, 'slow' must be in the middle.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
   ListNode* middleNode(ListNode* head) {
    if(head==NULL)return head;
         ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
}
};