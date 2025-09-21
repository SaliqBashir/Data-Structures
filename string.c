#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display string
void display(char *str) {
    printf("Current string: %s\n", str);
}

// Function to insert a string at a given index
void insert(char *str, char *sub, int index) {
    int lenStr = strlen(str);
    int lenSub = strlen(sub);

    if (index < 0 || index > lenStr) {
        printf("Invalid index!\n");
        return;
    }

    // Move memory to make space
    memmove(str + index + lenSub, str + index, lenStr - index + 1);

    // Copy substring into position
    memcpy(str + index, sub, lenSub);
}

// Function to delete substring from index with given length
void delete(char *str, int index, int length) {
    int lenStr = strlen(str);

    if (index < 0 || index >= lenStr) {
        printf("Invalid index!\n");
        return;
    }

    if (index + length > lenStr)
        length = lenStr - index;

    memmove(str + index, str + index + length, lenStr - index - length + 1);
}

// Function to update substring (delete + insert new one)
void update(char *str, char *sub, int index, int length) {
    delete(str, index, length);
    insert(str, sub, index);
}

int main() {
    char str[200] = "HelloWorld";  // main string
    char sub[100];
    int choice, index, length;

    while (1) {
        printf("\nString Operations using Pointers\n");
        printf("1. Display\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Update\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                display(str);
                break;

            case 2:
                printf("Enter string to insert: ");
                fgets(sub, sizeof(sub), stdin);
                sub[strcspn(sub, "\n")] = '\0'; // remove newline
                printf("Enter index: ");
                scanf("%d", &index);
                insert(str, sub, index);
                break;

            case 3:
                printf("Enter index to delete from: ");
                scanf("%d", &index);
                printf("Enter length to delete: ");
                scanf("%d", &length);
                delete(str, index, length);
                break;

            case 4:
                printf("Enter replacement string: ");
                getchar(); // consume leftover newline
                fgets(sub, sizeof(sub), stdin);
                sub[strcspn(sub, "\n")] = '\0';
                printf("Enter index: ");
                scanf("%d", &index);
                printf("Enter length to replace: ");
                scanf("%d", &length);
                update(str, sub, index, length);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
