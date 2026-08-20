/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
public:

    bool intersected(ListNode* comparisonEl, ListNode* chainStart)
    {
        if (!comparisonEl)
        {
            return false;
        }

        while (chainStart)
        {
            if (comparisonEl == chainStart)
            {
                return true;
            }
            chainStart = chainStart->next;
        }
        return false;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* headBCopy = headB;
        while (headA)
        {
            if (intersected(headA, headBCopy))
            {
                return headA;
            }
            headA = headA->next;
        }

        return nullptr;
    }
};