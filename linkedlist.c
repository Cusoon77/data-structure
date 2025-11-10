#include <stdio.h>
#include <stdlib.h>


struct Node 
{
    int data;
    struct Node* next;
};


struct Node* head = NULL;
void insertAtBeginning(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the beginning.\n", data);
}

void insertAtEnd(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
     {
        head = newNode;
        printf("Inserted %d (as the first node).\n", data);
        return;
    }

    struct Node* current = head;
    while (current->next != NULL) 
    {
        current = current->next;
    }
    current->next = newNode;
    printf("Inserted %d at the end.\n", data);
}

void deleteNode(int key)
 {
    struct Node *current = head;
    struct Node *prev = NULL;

 
    if (current != NULL && current->data == key) 
    {
        head = current->next;
        free(current);
        printf("Deleted %d (head node).\n", key);
        return;
    }
    while (current != NULL && current->data != key)
     {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with data %d not found.\n", key);
        return;
    }

   
    prev->next = current->next;
    free(current);
    printf("Deleted %d.\n", key);
}


void searchList(int key) 
{
    struct Node* current = head;
    int position = 1;

    while (current != NULL)
     {
        if (current->data == key) 
        {
            printf("Found %d at position %d.\n", key, position);
            return;
        }
        current = current->next;
        position++;
    }
    printf("%d not found in the list.\n", key);
}

void displayList() 
{
    struct Node* current = head;

    if (current == NULL) 
    {
        printf("List is empty.\n");
        return;
}

    printf("Current List: ");
    while (current != NULL) 
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data, key;

    do {
        printf("\n\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete Node (by value)\n");
        printf("4. Search Node\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                deleteNode(key);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &key);
                searchList(key);
                break;
            case 5:
                displayList();
                break;
            case 6:
                printf("Exiting program. Clearing memory...\n");
                while (head != NULL) 
                {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
