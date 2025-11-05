#include <stdio.h>
#include <stdlib.h>

int a[100], n = 0, i;

void create()
{
    printf("\nEnter total number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void insert()
{
    int pos, data;

    printf("\nEnter the position to insert: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n + 1) {
        printf("Invalid position!\n");
        return;
    }

    for (i = n - 1; i >= pos - 1; i--) {
        a[i + 1] = a[i];
    }

    printf("Enter the value to insert: ");
    scanf("%d", &data);

    a[pos - 1] = data;
    n++;

    printf("\nNew array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}

void deleteElement()
{
    int pos;

    printf("\nEnter the position of element to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position!\n");
        return;
    }

    for (i = pos - 1; i < n - 1; i++) {
        a[i] = a[i + 1];
    }

    n--;

    printf("\nNew array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}

void view()
{
    int i;
    printf("\nArray elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}

int main()
{
    int opt = 0;

    while (1)
    {
        printf("\n--- Menu ---\n");
        printf("1) Create\n");
        printf("2) Delete\n");
        printf("3) Insert\n");
        printf("4) View\n");
        printf("5) Quit\n");
        printf("Choose your option: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            create();
            break;
        case 2:
            deleteElement();
            break;
        case 3:
            insert();
            break;
        case 4:
            view();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid option! Try again.\n");
        }
    }

    return 0;
}

