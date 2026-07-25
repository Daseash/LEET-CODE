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
        ListNode* head = l1; // Keep track of the head of l1 to return later
        ListNode* prev = nullptr; // To track the last node visited in l1
        int carry = 0;
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            
            if (l1 != nullptr) {
                sum += l1->val;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next; // Advance l2
            }
            
            carry = sum / 10;
            int current_digit = sum % 10;
            
            if (l1 != nullptr) {
                // Modify l1 in place
                l1->val = current_digit;
                prev = l1;
                l1 = l1->next; // Advance l1
            } else {
                // If l1 is shorter, we need to add new nodes to the end
                prev->next = new ListNode(current_digit);
                prev = prev->next;
            }
        }
        
        return head;
    }
};