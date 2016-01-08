#include "linked_lists.h"
#include "node.h"

/**
 * Reverse a linked list and return pointer to the head
 */
Node* reverse(Node* head)
{
    if (head == nullptr) {
        return nullptr;
    }

    Node* current = head;
    Node* reverse = nullptr;
    while (current != nullptr) {
        Node* next = current->next;
        current->next = reverse;
        reverse = current;
        current = next;
    }
    return reverse;
}