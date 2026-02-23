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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        unordered_map<int, ListNode*> mpp;
        int currSum = 0;

        ListNode* temp = dummy;

        while (temp != NULL) {
            currSum += temp->val;

            if (mpp.find(currSum) != mpp.end()) {
                ListNode* prev = mpp[currSum];
                ListNode* node = prev->next;

                int sum = currSum;

                while (node != temp) {
                    sum += node->val;
                    mpp.erase(sum);
                    node = node->next;
                }

                prev->next = temp->next;
            } else {
                mpp[currSum] = temp;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};