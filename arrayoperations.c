#include <stdio.h>
#include <stdlib.h>

int a[100], n = 0;

void create() {
    printf("\nTotal number of elements in the array: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void insert() {
    if(n >= 100) {
        printf("Array is full!\n");
        return;
    }

    int pos, data;
    printf("\nPosition of insertion: ");
    scanf("%d", &pos);
    if(pos < 1 || pos > n + 1) {
        printf("Invalid position!\n");
        return;
    }

    for(int i = n - 1; i >= pos - 1; i--) {
        a[i + 1] = a[i];
    }

    printf("Which value you want to add: ");
    scanf("%d", &data);
    a[pos - 1] = data;
    n++;

    printf("New array is:\n");
    for(int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}

void delete_element() {
    if(n == 0) {
        printf("Array is empty!\n");
        return;
    }

    int pos;
    printf("\nEnter the position of element to delete: ");
    scanf("%d", &pos);

    if(pos < 1 || pos > n) {
        printf("Invalid position!\n");
        return;
    }

    for(int i = pos - 1; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;

    printf("New array is:\n");
    for(int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}

void view() {
    if(n == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Elements are:\n");
    for(int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}

int main() {
    int opt = 0;
    while(1) {
        printf("\n1) CREATE\n");
        printf("2) INSERT\n");
        printf("3) DELETE\n");
        printf("4) VIEW\n");
        printf("5) QUIT\n");
        printf("Choose your option: ");
        scanf("%d", &opt);

        switch(opt) {
            case 1: create(); break;
            case 2: insert(); break;
            case 3: delete_element(); break;
            case 4: view(); break;
            case 5: exit(0);
            default: printf("Invalid option! Try Again.\n");
        }
    }
    return 0;
}

