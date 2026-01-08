#include <stdio.h>
#include <stdlib.h>
#define N 5

int queue[N];
int rear = -1, front = -1;

void enqueue() {
    int val;
    printf("Enter the data: ");
    scanf("%d", &val);

    if (rear == -1 && front == -1) 
    { 
        rear = front = 0;
        queue[rear] = val;
    }
    else if ((rear + 1) % N == front) 
    {
        printf("Queue is overflow\n");
        return;
    } else {
        rear = (rear + 1) % N;
        queue[rear] = val;
    }
}

void dequeue() {
    if (rear == -1 && front == -1) 
    { 
        printf("Queue is underflow\n");
        return;
    }
    else if (rear == front) 
    { 
        printf("Deleted item is %d\n", queue[front]);
        rear = front = -1;
    } else {
        printf("Deleted item is %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

void search() {
    int data, flag = 0, pos = 0;
    if (rear == -1 && front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Enter the data to search: ");
    scanf("%d", &data);

    int i = front;
    while (1) {
        if (queue[i] == data) {
            flag = 1;
            break;
        }
        if (i == rear) break;
        i = (i + 1) % N;
        pos++;
    }

    if (flag)
        printf("The element is found at position %d\n", pos + 1);
    else
        printf("Element not found\n");
}

void display() {
    if (rear == -1 && front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % N;
    }
    printf("\n");
}

int main() {
    int opt;
    do {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: search(); break;
            case 5: exit(0);
            default: printf("Invalid option\n");
        }
    } while (1);

    return 0;
}

