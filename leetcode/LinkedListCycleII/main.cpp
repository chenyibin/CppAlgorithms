#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
    : val(x)
    , next(nullptr)
    { }
};

class Solution {
public:

    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        do {
            if (fast->next == nullptr
             || fast->next->next == nullptr)
            {
                return nullptr;
            }
            fast = fast->next->next;
            slow = slow->next;
        } while (slow != fast);

        fast = head;
        while (slow != fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};


int main() {
    cout << "Hello, World!" << endl;
    return 0;
}