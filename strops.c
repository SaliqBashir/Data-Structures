#include<stdio.h>
#include<stdlib.h>

struct node{
    int number;
    struct node *next;
}node;

void traverse(struct node *head);
int insertion(struct node **head, int *number);
void freeList(struct node *head);
int deletion(struct node **head, int *number);

int main(){
    int *number = malloc(sizeof(int));

    if (number == NULL){
        printf("Failed to allot memory.\n");
        return 1;
    }
    printf("Enter how many nodes do you want: ");
    scanf("%i", number);

    struct node *head = NULL;

    for(int i =0; i< *number;i++){
        struct node *newNode = malloc(sizeof(struct node));
        if (newNode == NULL){
            printf("Failed to allot memory.\n");
            freeList(head);
            free(number);
            return 1;
        }
        printf("Enter number field for node no.%i: ", i+1);
        scanf("%i", &newNode->number);
        newNode->next = head;

        head = newNode;
    }
    
    int *listFreed = malloc(sizeof(int));
    if (listFreed == NULL) {
        printf("Failed to allocate memory for listFreed.\n");
        freeList(head);
        free(number);
        return 1;
    }
    *listFreed = 0;
    
    if (insertion(&head, number) == 1) {
        *listFreed = 1;
        printf("List was freed due to insertion error.\n");
    }
    
    if (!(*listFreed)) {
        if (deletion(&head, number) == 1) {
            *listFreed = 1;
            printf("List was freed due to deletion error.\n");
        }
    }
    
    if (!(*listFreed)) {
        traverse(head);
        freeList(head);
    }
    
    free(listFreed);
    free(number);
    return 0;
}

void traverse(struct node *head){
    struct node *pointer = head;
    int *i = malloc(sizeof(int));
    if (i == NULL) {
        printf("Failed to allocate memory for counter.\n");
        return;
    }
    *i = 1;
    while(pointer != NULL){
        printf("Number at Linked List at position %i is %i\n",*i, pointer->number);
        pointer = pointer->next;
        (*i)++;
    }
    free(i);
}

void freeList(struct node *head) {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return;
}

int insertion(struct node **head, int *number){
    int *index = malloc(sizeof(int));
    if (index == NULL) {
        printf("Failed to allocate memory for index.\n");
        freeList(*head);
        return 1;
    }
    
    int *value = malloc(sizeof(int));
    if (value == NULL) {
        printf("Failed to allocate memory for value.\n");
        free(index);
        freeList(*head);
        return 1;
    }

    printf("Enter index where you want to insert new node: ");
    scanf("%i", index);
    printf("Enter value of new node: ");
    scanf("%i", value);

    int *count = malloc(sizeof(int));
    if (count == NULL) {
        printf("Failed to allocate memory for count.\n");
        free(index);
        free(value);
        freeList(*head);
        return 1;
    }
    *count = 0;

    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Failed to allocate memory for new node.\n");
        free(index);
        free(value);
        free(count);
        freeList(*head);
        return 1;
    }
    newNode->number = *value;
    
    if (*index == 1) {
        newNode->next = *head;
        *head = newNode;
        free(index);
        free(value);
        free(count);
        return 0;
    }

    struct node *pointer = *head;
    *index = *number - *index;

    while(*count != *index - 1){
        pointer = pointer->next;

        if (pointer == NULL){
            printf("Index out of bounds.\n");
            free(index);
            free(value);
            free(count);
            free(newNode);
            freeList(*head);
            return 1;
        }
        (*count)++;
    }

    newNode->next = pointer->next;
    pointer->next = newNode;

    free(index);
    free(value);
    free(count);
    return 0;
}

int deletion(struct node **head, int *number){
    int *index = malloc(sizeof(int));
    if (index == NULL) {
        printf("Failed to allocate memory for index.\n");
        freeList(*head);
        return 1;
    }
    
    printf("Enter index of node you want to delete: ");
    scanf("%i", index);

    int *count = malloc(sizeof(int));
    if (count == NULL) {
        printf("Failed to allocate memory for count.\n");
        free(index);
        freeList(*head);
        return 1;
    }
    *count = 0;
    
    if (*index == 1) {
        if (*head == NULL) {
            printf("List is empty.\n");
            free(index);
            free(count);
            return 0;
        }
        struct node *nodeToDelete = *head;
        *head = (*head)->next;
        free(nodeToDelete);
        free(index);
        free(count);
        return 0;
    }

    struct node *pointer = *head;
    *index = *number - *index;

    while(*count != *index - 1){
        pointer = pointer->next;

        if (pointer == NULL){
            printf("Index out of bounds.\n");
            free(index);
            free(count);
            freeList(*head);
            return 1;
        }
        (*count)++;
    }

    if (pointer->next == NULL) {
        printf("Index out of bounds - cannot delete.\n");
        free(index);
        free(count);
        freeList(*head);
        return 1;
    }

    struct node *nodeToDelete = pointer->next;
    pointer->next = pointer->next->next;
    free(nodeToDelete);
    free(index);
    free(count);
    return 0;
}