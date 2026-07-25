/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy head to simplify the creation of the result list
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        
        // Loop until both lists are exhausted and there is no carry left
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get the values from the current nodes, or 0 if we reached the end of a list
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            
            // Calculate sum and update carry
            int sum = carry + x + y;
            carry = sum / 10;
            
            // Create a new node with the current digit and attach it to our result list
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            
            // Move to the next nodes in l1 and l2 if they exist
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        
        // Save the actual result and clean up the dummy head
        ListNode* result = dummyHead->next;
        delete dummyHead; 
        
        return result;
    }
};