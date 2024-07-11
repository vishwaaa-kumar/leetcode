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
    ListNode* reverse(ListNode* head) {
        ListNode *cur = head, *prev = NULL, *nex = NULL;
        while(cur) {
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode * slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *rev = reverse(slow);
        while (head && rev) {
            if (head->val != rev->val)
                return false;
            head = head->next;
            rev = rev->next;
        }
        return true;
    }
};