#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

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

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

struct Node* insertAtPosition(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
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

struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return head;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
    return head;
}

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int searchElement(struct Node* head, int key) {
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == key)
            return position;
        temp = temp->next;
        position++;
    }
    return -1;
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("The elements of the list are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int data, choice, position;
    char cont;

    printf("Enter the elements: ");
    while (scanf("%d", &data)) {
        head = insertAtEnd(head, data);
        if (getchar() == '\n') break; // stop reading input on new line
    }

    do {
        printf("\n1. Add more elements to the list\n");
        printf("2. Display the list\n");
        printf("3. Insert the element at beginning\n");
        printf("4. Insert the element at the end\n");
        printf("5. Insert the element at specific position\n");
        printf("6. Delete the element from the beginning\n");
        printf("7. Delete the element from the end\n");
        printf("8. Delete the element from specific position\n");
        printf("9. Count the total number of nodes\n");
        printf("10. Search an element in the linked list\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element: ");
                while (scanf("%d", &data)) {
                    head = insertAtEnd(head, data);
                    if (getchar() == '\n') break;
                }
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Enter the data item: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 4:
                printf("Enter the data item: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 5:
                printf("Enter the data item: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 6:
                head = deleteAtBeginning(head);
                break;
            case 7:
                head = deleteAtEnd(head);
                break;
            case 8:
                printf("Enter the position: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 9:
                printf("Total number of nodes: %d\n", countNodes(head));
                break;
            case 10:
                printf("Enter the element to search: ");
                scanf("%d", &data);
                position = searchElement(head, data);
                if (position != -1)
                    printf("Element found at position %d\n", position);
                else
                    printf("Element not found\n");
                break;
            case 11:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

        if (choice != 11) {
            printf("Do you want to Continue (Y/N): ");
            scanf(" %c", &cont);
            if (cont == 'N' || cont == 'n') {
                break;
            }
        }
    } while (choice != 11);

    return 0;
}

