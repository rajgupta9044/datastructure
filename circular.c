#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode;
    return newNode;
}

struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* temp = createNode(value);
    if (head == NULL) {
        return temp;
    }
    struct Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    temp->next = head;
    tail->next = temp;
    return temp;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* temp = createNode(value);
    if (head == NULL) {
        return temp;
    }
    struct Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    tail->next = temp;
    temp->next = head;
    return head;
}

struct Node* insertAtPos(struct Node* head, int value, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return head;
    }
    if (pos == 1) {
        return insertAtBeginning(head, value);
    }
    struct Node* temp = createNode(value);
    struct Node* current = head;
    int count = 1;
    while (count < pos - 1 && current->next != head) {
        current = current->next;
        count++;
    }
    temp->next = current->next;
    current->next = temp;
    return head;
}

struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL || head->next == head) {
        free(head);
        return NULL;
    }
    struct Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    struct Node* temp = head;
    head = head->next;
    tail->next = head;
    free(temp);
    return head;
}

struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL || head->next == head) {
        free(head);
        return NULL;
    }
    struct Node* prev = NULL;
    struct Node* tail = head;
    while (tail->next != head) {
        prev = tail;
        tail = tail->next;
    }
    prev->next = head;
    free(tail);
    return head;
}

struct Node* deleteAtPos(struct Node* head, int pos) {
    if (head == NULL || pos < 1) {
        printf("Invalid position!\n");
        return head;
    }
    if (pos == 1) {
        return deleteAtBeginning(head);
    }
    struct Node* current = head;
    struct Node* prev = NULL;
    int count = 1;
    while (count < pos && current->next != head) {
        prev = current;
        current = current->next;
        count++;
    }
    if (current == head) {
        printf("Position out of bounds!\n");
        return head;
    }
    prev->next = current->next;
    free(current);
    return head;
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

struct Node* createList(int arr[], int size) {
    struct Node* head = NULL;
    for (int i = 0; i < size; i++) {
        head = insertAtEnd(head, arr[i]);
    }
    return head;
}

int main() {
    int arr[5] = {11, 21, 31, 41, 51};
    struct Node* head = createList(arr, 5);
    printf("The circular linked list is: ");
    printList(head);

    head = insertAtBeginning(head, 5);
    printf("Insert at beginning: ");
    printList(head);

    head = insertAtEnd(head, 99);
    printf("Insertion at end: ");
    printList(head);
    
    int pos = 3;
    head = insertAtPos(head, 42, pos);
    printf("Insert at position %d: ", pos);
    printList(head);

    head = deleteAtBeginning(head);
    printf("Delete at beginning: ");
    printList(head);

    head = deleteAtEnd(head);
    printf("Deletion at end: ");
    printList(head);
    
    pos = 2;
    head = deleteAtPos(head, pos);
    printf("Deletion at position %d: ", pos);
    printList(head);
    
    return 0;
}
