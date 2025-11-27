#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* root = NULL;

struct node* create(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return create(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

struct node* findMin(struct node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node* delete(struct node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = delete(root->left, data);
    else if (data > root->data)
        root->right = delete(root->right, data);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
          else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

int main() {
    int opt, data;

    while (1) {
        printf("\n----- BST MENU -----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Inorder Traversal\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Inserted %d\n", data);
                break;

            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                printf("Deleted %d\n", data);
                break;

            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (search(root, data))
                    printf("Found %d\n", data);
                else
                    printf("Not found\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}

