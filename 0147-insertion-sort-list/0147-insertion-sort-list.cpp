
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        // If the list is empty or has only one node, it's already sorted.
        if (!head || !head->next) {
            return head;
        }

        // Dummy node acts as the head of our new sorted list.
        ListNode* dummy = new ListNode(0); 
        ListNode* curr = head; 

        while (curr != nullptr) {
            // Start from the dummy node for each insertion to find the right spot
            ListNode* prev = dummy;
            
            // Move prev forward as long as the next node's value is smaller than curr's value
            while (prev->next != nullptr && prev->next->val < curr->val) {
                prev = prev->next;
            }

            // We found the insertion point. 
            // First, save the next node we need to process from the original list.
            ListNode* next_node = curr->next;

            // Insert 'curr' between 'prev' and 'prev->next'
            curr->next = prev->next;
            prev->next = curr;

            // Move on to the next node in the unsorted list
            curr = next_node;
        }

        // The sorted list is everything after the dummy node
        ListNode* sorted_head = dummy->next;
        delete dummy; // Clean up our allocated memory
        
        return sorted_head;
    }
};   
    