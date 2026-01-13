#include <iostream>
#include <unordered_set>
#include <cstdint>

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
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    std::unordered_set<std::uintptr_t> seen_addr;
    if (!head) return false;
    while(head)
    {
        //This value has not yet been seen
        if (!seen_addr.empty() && seen_addr.find(reinterpret_cast<std::uintptr_t>(head)) == seen_addr.end())
        {
            seen_addr.insert(reinterpret_cast<std::uintptr_t>(head));
        }
        //This value has already been seen => must have a loop
        else if(seen_addr.empty())
        {
            seen_addr.insert(reinterpret_cast<std::uintptr_t>(head));
        }
        else
        {
            return true;
        }
        head = head->next;
    }
    return false;
}

void main()
{
    ListNode head(1);
    head.next = &head;
    std::cout << "LALLALALLLA\n";
    std::cout << hasCycle(&head);
    return;
}