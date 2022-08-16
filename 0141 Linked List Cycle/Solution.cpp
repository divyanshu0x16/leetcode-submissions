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
    bool hasCycle(ListNode *head) {
        
        //We use two pointer. If these pointres ever meet, thene there is a cycle. If ever reach null then no cycle
        ListNode* slow = head;
        ListNode* fast = head;

        while (true)
        {
            if( fast == NULL or slow == NULL or slow->next == NULL or fast->next == NULL) break;

            fast = fast -> next -> next;
            slow = slow -> next;

            if( fast == slow ) return true;
        }

        return false;
    }
};


