#include <stdio.h>
#include <stdlib.h>
#define MAX 5

char queue[MAX];
int front = -1, rear = -1;

void insert() {
    char item;
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("\nQueue Overflow! (Circular Queue is Full)\n");
        return;
    }
    printf("Enter character to insert: ");
    scanf(" %c", &item);
    if (front == -1)
        front = rear = 0;
    else if (rear == MAX - 1 && front != 0)
        rear = 0;
    else
        rear++;
    queue[rear] = item;
    printf("'%c' inserted successfully!\n", item);
}

void delete() {
    if (front == -1) {
        printf("\nQueue Underflow! (Circular Queue is Empty)\n");
        return;
    }
    char item = queue[front];
    printf("Deleted element: %c\n", item);
    if (front == rear)
        front = rear = -1;
    else if (front == MAX - 1)
        front = 0;
    else
        front++;
}

void display() {
    if (front == -1) {
        printf("\nCircular Queue is Empty.\n");
        return;
    }
    printf("\nCircular Queue elements are: ");
    int i = front;
    if (front <= rear) {
        while (i <= rear)
            printf("%c ", queue[i++]);
    } else {
        while (i <= MAX - 1)
            printf("%c ", queue[i++]);
        i = 0;
        while (i <= rear)
            printf("%c ", queue[i++]);
    }
    printf("\nFront = %d, Rear = %d\n", front, rear);
}

int main() {
    int choice;
    printf("---- Circular Queue Operations ----\n");
    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: insert(); break;
        case 2: delete(); break;
        case 3: display(); break;
        case 4: printf("Exiting program.\n"); break;
        default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);
    return 0;
}
