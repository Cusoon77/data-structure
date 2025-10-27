#include <stdio.h>

int main() {
    int arr[100]; 
    int size;      
    int position;  
    int i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter the position of the element to delete: ");
    scanf("%d", &position);

    if (position < 0 || position >= size) {
        printf("Invalid position for deletion.\n");
    } else {
        
        for (i = position; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;

        printf("Array after deletion:\n");
        for (i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
