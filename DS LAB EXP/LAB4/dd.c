#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
struct Node* insertAtBeginning(struct Node* head, int data);
struct Node* insertAtEnd(struct Node* head, int data);
struct Node* insertAtPosition(struct Node* head, int data, int position);
struct Node* deleteFromBeginning(struct Node* head);
struct Node* deleteFromEnd(struct Node* head);
struct Node* deleteFromPosition(struct Node* head, int position);
int countNodes(struct Node* head);
int searchElement(struct Node* head, int data);
void displayList(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    // Initial input before displaying menu
    printf("Enter the initial element for the linked list: ");
    scanf("%d", &data);
    head = createNode(data);

    do {
        printf("\nMenu:\n");
        printf("1. Create a Node\n");
        printf("2. Display the list\n");
        printf("3. Insert the element at beginning\n");
        printf("4. Insert the element at the end\n");
        printf("5. Insert the element at a specific position\n");
        printf("6. Delete the element from the beginning\n");
        printf("7. Delete the element from the end\n");
        printf("8. Delete the element from a specific position\n");
        printf("9. Count the total number of nodes\n");
        printf("10. Search an element in the linked list\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = createNode(data);
                break;

            case 2:
                displayList(head);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;

            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;

            case 5:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;

            case 6:
                head = deleteFromBeginning(head);
                break;

            case 7:
                head = deleteFromEnd(head);
                break;

            case 8:
                printf("Enter position: ");
                scanf("%d", &position);
                head = deleteFromPosition(head, position);
                break;

            case 9:
                printf("Total number of nodes: %d\n", countNodes(head));
                break;

            case 10:
                printf("Enter the element to search: ");
                scanf("%d", &data);
                position = searchElement(head, data);
                if (position != -1) {
                    printf("Element found at position: %d\n", position);
                } else {
                    printf("Element not found.\n");
                }
                break;

            case 11:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while(choice != 11);

    return 0;
}

// Function to create a node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to display the list
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert at the beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to insert at a specific position
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return head;
    }
    if (position == 1) {
        return insertAtBeginning(head, data);
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Function to delete from the beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete from the end
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Function to delete from a specific position
struct Node* deleteFromPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    if (position < 1) {
        printf("Invalid position!\n");
        return head;
    }
    if (position == 1) {
        return deleteFromBeginning(head);
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

// Function to count the total number of nodes
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to search an element in the linked list
int searchElement(struct Node* head, int data) {
    int position = 1;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;  // Element not found
}
