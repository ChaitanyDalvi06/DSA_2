//Sort a linked list using merge sort.

#include <iostream>
using namespace std;

// Node structure for Linked List
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to split the list into two halves
Node* getMiddle(Node* head) {
    if (!head || !head->next) return head;
    Node* slow = head, *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to merge two sorted lists
Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;
    
    Node* result = NULL;
    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

// Merge Sort function for Linked List
Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;

    // Get the middle of the list
    Node* mid = getMiddle(head);
    Node* rightHead = mid->next;
    mid->next = NULL; // Split the list into two

    // Recursively sort both halves
    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHead);

    // Merge the sorted halves
    return merge(left, right);
}

// Function to print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Function to insert a new node at the end
void insert(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(val);
}

// Main function
int main() {
    Node* head = NULL;
    
    // Creating a linked list
    insert(head, 4);
    insert(head, 2);
    insert(head, 1);
    insert(head, 3);
    
    cout << "Original List: ";
    printList(head);
    
    head = mergeSort(head);
    
    cout << "Sorted List: ";
    printList(head);
    
    return 0;
}

