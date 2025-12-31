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

struct Node* create(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int data;

    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return NULL;
    }

    for (int i = 1; i <= n; i++) {
        printf("Enter info of node%d: ", i);
        scanf("%d", &data);
        newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    temp->next = head;

    return head;
}

void cll(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Circular linkedlist: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n;

    printf("Enter no. of nodes: ");
    scanf("%d", &n);

    head = create(n);

    cll(head);

    return 0;
}

