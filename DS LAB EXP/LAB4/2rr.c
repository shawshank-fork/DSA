#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void displaylist(struct node* head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    struct node* temp = head;
    printf("List is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displaylistreverse(struct node* head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("List in reverse: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

struct node* inserthead(struct node* head, int data) {
    struct node* newnode = createnode(data);
    if (head != NULL) {
        head->prev = newnode;
    }
    newnode->next = head;
    return newnode;
}

struct node* insertatend(struct node* head, int data) {
    struct node* newnode = createnode(data);
    if (head == NULL) {
        return newnode;
    }

    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}

struct node* insertatposition(struct node* head, int data, int position) {
    struct node* newnode = createnode(data);

    if (position == 1) {
        if (head != NULL) {
            head->prev = newnode;
        }
        newnode->next = head;
        return newnode;
    }

    struct node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return head;
    }

    newnode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}

struct node* deletefromstart(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    struct node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

struct node* deletefromend(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
    return head;
}

struct node* deletefromposition(struct node* head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    if (position == 1) {
        struct node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }

    struct node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return head;
    }

    struct node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = temp;
    }
    free(nodeToDelete);
    return head;
}

int countnodes(struct node* head) {
    int count = 0;
    struct node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int search(struct node* head, int key) {
    struct node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == key)
            return position;
        temp = temp->next;
        position++;
    }
    return -1;
}

void freelist(struct node* head) {
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct node* head = NULL;    
    int data, choice, position;
    char cont;

    printf("Enter the elements: ");
    while (scanf("%d", &data)) {
        head = insertatend(head, data);
        if (getchar() == '\n') break; 
    }

    do {
        printf("1. Create a node\n");
        printf("2. Display the list\n");
        printf("3. Display the list in reverse order\n");
        printf("4. Insert the element at beginning\n");
        printf("5. Insert the element at the end\n");
        printf("6. Insert the element at a specific position\n");
        printf("7. Delete the element from the beginning\n");
        printf("8. Delete the element from the end\n");
        printf("9. Delete the element from a specific position\n");
        printf("10. Count the total number of nodes\n");
        printf("11. Search an element in the linked list\n");
        printf("12. Exit\n"); 
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                while (scanf("%d", &data)) {
                    head = insertatend(head, data);
                    if (getchar() == '\n') break;
                }
                break;

            case 2:
                displaylist(head);
                break;

            case 3:
                displaylistreverse(head);
                break;

            case 4:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                head = inserthead(head, data);
                break;

            case 5:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                head = insertatend(head, data);
                break;

            case 6:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert the value at: ");
                scanf("%d", &position);
                head = insertatposition(head, data, position);
                break;

            case 7:
                head = deletefromstart(head);
                break;

            case 8:
                head = deletefromend(head);
                break;

            case 9:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                head = deletefromposition(head, position);
                break;

            case 10:
                printf("Total number of nodes: %d\n", countnodes(head));
                break;

            case 11:
                printf("Enter element to search: ");
                scanf("%d", &data);
                position = search(head, data);
                if (position != -1)
                    printf("Element found at position %d\n", position);
                else
                    printf("Element not found\n");
                break;

            case 12:
                printf("Exiting\n");
                freelist(head);  
                break;

            default:
                printf("Invalid choice.\n");
        }

        if (choice != 12) {
            printf("Do you want to continue (Y/N): ");
            scanf(" %c", &cont);
            if (cont == 'N' || cont == 'n') {
                break;
            }
        }
    } while (choice != 12);

    return 0;
} 
