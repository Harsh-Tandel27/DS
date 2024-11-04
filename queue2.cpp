#include <stdio.h>
#include <string.h>

#define MAX 3

struct item {
    int item_id;
    char item_name[100];
    float price;
    int quantity;
} queue[MAX];

int front = -1, rear = -1;

void insert(void);
void remove_item(void);
void display(void);
float calculate_total_bill(void);

int main() {
    int option;
    do {
        printf("\n*** MAIN MENU ***");
        printf("\n1. Insert an item");
        printf("\n2. Remove an item");
        printf("\n3. Display the queue");
        printf("\n4. Exit");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                insert();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nTotal bill amount: %.2f\n", calculate_total_bill());
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    } while (option != 4);

    return 0;
}

void insert() {
    if (rear == MAX - 1) {
        printf("\nQueue is full (Overflow)\n");
        return;
    }

    int id, quantity;
    char name[100];
    float price;

    printf("\nEnter item ID: ");
    scanf("%d", &id);
    printf("Enter item name: ");
    scanf(" %[^\n]%*c", name);  // Using " %[^\n]%*c" to take multi-word input
    printf("Enter price: ");
    scanf("%f", &price);
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }

    queue[rear].item_id = id;
    strcpy(queue[rear].item_name, name);
    queue[rear].price = price;
    queue[rear].quantity = quantity;
    printf("Item inserted successfully.\n");
}

void remove_item() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty (Underflow)\n");
        return;
    }

    printf("\nRemoved item - ID: %d, Name: %s, Price: %.2f, Quantity: %d\n",
           queue[front].item_id, queue[front].item_name, queue[front].price, queue[front].quantity);

    front++;
    if (front > rear) {
        front = rear = -1; // Reset queue when empty
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nCurrent items in the queue:\n");
    for (int i = front; i <= rear; i++) {
        printf("\nItem ID: %d\tItem Name: %s\tPrice: %.2f\tQuantity: %d",
               queue[i].item_id, queue[i].item_name, queue[i].price, queue[i].quantity);
    }
    printf("\n");
}

float calculate_total_bill() {
    float total = 0.0;
    if (front == -1 || front > rear) return total;

    for (int i = front; i <= rear; i++) {
        total += queue[i].price * queue[i].quantity;
    }

    return total;
}
