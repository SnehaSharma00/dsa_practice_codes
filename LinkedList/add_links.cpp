/*Add the Link
Difficulty: MEDIUM | Max Score: 50
You are given Head nodes of two linked lists. The two linked lists contain series of digits where the series of digits is denoting an integer number.

Your task is to add both the numbers and return the Head node of the linked list containing the series of the resultant number.

CHALLENGE: Try to solve it using O(1) extra auxiliary space(space other than resultant output space).

 

Example:

Input: 5->3->6->2
       2->9->8
Output: 5->6->6->0
Explanation: 5362 + 298 = 5660
 

Constraints:

1 <= Size of lists <= 105
The lengths of the two lists can be different.
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // reverse l1
        ListNode* prev = nullptr;
        while(l1 != nullptr) {
            ListNode* nxt = l1->next;
            l1->next = prev;
            prev = l1;
            l1 = nxt;
        }
        l1 = prev;

        // reverse l2
        prev = nullptr;
        while(l2 != nullptr) {
            ListNode* nxt = l2->next;
            l2->next = prev;
            prev = l2;
            l2 = nxt;
        }
        l2 = prev;

        // add
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        int carry = 0;

        while(l1 != nullptr || l2 != nullptr || carry) {

            int sum = carry;

            if(l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            temp->next = new ListNode(sum % 10);
            temp = temp->next;

            carry = sum / 10;
        }

        // reverse result
        ListNode* head = dummy->next;
        prev = nullptr;

        while(head != nullptr) {
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }

        return prev;
    }
};