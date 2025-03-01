#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* temp = createNode(value);
    if (head == NULL) {
        return temp;
    }
    struct Node* tail = head->prev;
    temp->next = head;
    temp->prev = tail;
    head->prev = temp;
    tail->next = temp;
    return temp;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* temp = createNode(value);
    if (head == NULL) {
        return temp;
    }
    struct Node* tail = head->prev;
    tail->next = temp;
    temp->prev = tail;
    temp->next = head;
    head->prev = temp;
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
    if (count < pos - 1) {
        printf("Position out of bounds!\n");
        return head;
    }
    temp->next = current->next;
    temp->prev = current;
    current->next->prev = temp;
    current->next = temp;
    return head;
}

struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    }
    struct Node* tail = head->prev;
    struct Node* temp = head;
    head = head->next;
    head->prev = tail;
    tail->next = head;
    free(temp);
    return head;
}

struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    }
    struct Node* tail = head->prev;
    struct Node* newTail = tail->prev;
    newTail->next = head;
    head->prev = newTail;
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
    int count = 1;
    while (count < pos && current->next != head) {
        current = current->next;
        count++;
    }
    if (count < pos) {
        printf("Position out of bounds!\n");
        return head;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
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
    printf("The circular doubly linked list is: ");
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
