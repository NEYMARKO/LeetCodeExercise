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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* currentNode = head;
        if (!head) return head;
        while (currentNode && currentNode->next)
        {
            //detach current node - reassign "next"
            if (currentNode->next->val == currentNode->val)
            {
                currentNode->next = currentNode->next->next;
            }
            //if value is not same as current node's, move to another node
            //this condition must exist because of [1,1,1] case
            //if it didn't exist, and we moved to another node after
            //reasigning "next", 3rd "1" wouldn't get removed
            else
            {
                currentNode = currentNode->next;
            }
        }
        return head;
    }
};