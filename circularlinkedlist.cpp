#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert_beg(struct Node** head, int value);
void insert_end(struct Node** head, int value);
void delete_beg(struct Node** head);
void delete_end(struct Node** head);
void display(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\nCircular Singly Linked List Operations:\n");
        printf("1) Insert_beg: Insert a value in the beginning\n");
        printf("2) Insert_end: Insert a value at the end\n");
        printf("3) Delete_beg: Delete a value from the front\n");
        printf("4) Delete_end: Delete a value from the end\n");
        printf("5) Display: Display the list\n");
        printf("6) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at the beginning: ");
                scanf("%d", &value);
                insert_beg(&head, value);
                break;
            case 2:
                printf("Enter value to insert at the end: ");
                scanf("%d", &value);
                insert_end(&head, value);
                break;
            case 3:
                delete_beg(&head);
                break;
            case 4:
                delete_end(&head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void insert_beg(struct Node** head, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    new_node->data = value;

    if (*head == NULL) {
        *head = new_node;
        new_node->next = new_node;
    } else {
        while (temp->next != *head)
            temp = temp->next;

        new_node->next = *head;
        temp->next = new_node;
        *head = new_node;
    }

    printf("Node inserted at the beginning.\n");
}

void insert_end(struct Node** head, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    new_node->data = value;

    if (*head == NULL) {
        *head = new_node;
        new_node->next = new_node;
    } else {
        while (temp->next != *head)
            temp = temp->next;

        temp->next = new_node;
        new_node->next = *head;
    }

    printf("Node inserted at the end.\n");
}

void delete_beg(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* last = *head;

    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    } else {
        while (last->next != *head)
            last = last->next;

        *head = (*head)->next;
        last->next = *head;
        free(temp);
    }

    printf("Node deleted from the beginning.\n");
}

void delete_end(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    } else {
        while (temp->next != *head) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = *head;
        free(temp);
    }

    printf("Node deleted from the end.\n");
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Singly Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Head)\n");
}

