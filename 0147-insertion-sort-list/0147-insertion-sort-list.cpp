/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        // Dummy node to handle edge cases where the head changes
        ListNode* dummy = new ListNode(0, head);
        
        // last_sorted points to the last node in the sorted part of the list
        ListNode* last_sorted = head;
        // curr points to the next node we need to evaluate
        ListNode* curr = head->next; 

        while (curr != nullptr) {
            // FAST PATH: The current node is already in the right order!
            if (last_sorted->val <= curr->val) {
                last_sorted = last_sorted->next;
            } 
            // SLOW PATH: We need to find where this node belongs in the sorted portion
            else {
                ListNode* prev = dummy;
                
                // Find the insertion point
                while (prev->next->val <= curr->val) {
                    prev = prev->next;
                }
                
                // Rewire to insert 'curr' between 'prev' and 'prev->next'
                last_sorted->next = curr->next; // Bypass curr
                curr->next = prev->next;        // Point curr to the right node
                prev->next = curr;              // Point prev to curr
            }
            
            // Move to the next node in the unsorted list
            curr = last_sorted->next;
        }

        ListNode* sorted_head = dummy->next;
        delete dummy; 
        
        return sorted_head;
    }
};