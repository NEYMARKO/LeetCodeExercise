struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* current_node = head;
        ListNode* prev_node = head;
        while (current_node)
        {
            if (current_node->val == val)
            {
                if (current_node == head)
                {
                    head = current_node->next;
                }
                prev_node->next = current_node->next;
            }
            else
            {
                prev_node = current_node;
            }
            current_node = prev_node->next;
        }
        return head;
    }
};