#include <stdio.h>

#define MAX 100

void traverse(int arr[], int n) {
    if(n == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int insertEnd(int arr[], int n, int val) {
    if(n >= MAX) {
        printf("Array full!\n");
        return n;
    }
    arr[n] = val;
    return n+1;
}

int insertBeginning(int arr[], int n, int val) {
    if(n >= MAX) {
        printf("Array full!\n");
        return n;
    }
    for(int i=n; i>0; i--) arr[i] = arr[i-1];
    arr[0] = val;
    return n+1;
}

int insertAt(int arr[], int n, int pos, int val) {
    if(n >= MAX || pos<0 || pos>n) {
        printf("Invalid position!\n");
        return n;
    }
    for(int i=n; i>pos; i--) arr[i] = arr[i-1];
    arr[pos] = val;
    return n+1;
}

int deleteBeginning(int arr[], int n) {
    if(n == 0) {
        printf("Array empty!\n");
        return 0;
    }
    for(int i=0; i<n-1; i++) arr[i] = arr[i+1];
    return n-1;
}

int deleteEnd(int arr[], int n) {
    if(n == 0) {
        printf("Array empty!\n");
        return 0;
    }
    return n-1;
}

int deleteAt(int arr[], int n, int pos) {
    if(pos<0 || pos>=n) {
        printf("Invalid position!\n");
        return n;
    }
    for(int i=pos; i<n-1; i++) arr[i] = arr[i+1];
    return n-1;
}

int deleteNumber(int arr[], int n, int val) {
    int pos = -1;
    for(int i=0; i<n; i++) {
        if(arr[i] == val) { pos = i; break; }
    }
    if(pos == -1) {
        printf("Number not found!\n");
        return n;
    }
    return deleteAt(arr, n, pos);
}

void linearSearch(int arr[], int n, int val) {
    int found = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] == val) {
            printf("Found at position %d\n", i);
            found = 1;
        }
    }
    if(!found) printf("Not found!\n");
}

int main() {
    int arr[MAX], n=0, op, val, pos;

    do {
        printf("\nEnter Command to Use :\n");
        printf("1. Traverse\n");
        printf("2. Insert At end\n");
        printf("3. Insert At Beginning\n");
        printf("4. Insert At Any place\n");
        printf("5. Delete At Any place\n");
        printf("6. Delete At Beginning\n");
        printf("7. Delete a Number\n");
        printf("8. Delete At End\n");
        printf("9. Linear Search\n");
        printf("10. Exit Program\n");
        printf("------->>> ");
        scanf("%d",&op);

        switch(op) {
            case 1: traverse(arr,n); break;
            case 2: 
                printf("Enter value: "); scanf("%d",&val);
                n = insertEnd(arr,n,val); break;
            case 3:
                printf("Enter value: "); scanf("%d",&val);
                n = insertBeginning(arr,n,val); break;
            case 4:
                printf("Enter position and value: ");
                scanf("%d %d",&pos,&val);
                n = insertAt(arr,n,pos,val); break;
            case 5:
                printf("Enter position: "); scanf("%d",&pos);
                n = deleteAt(arr,n,pos); break;
            case 6:
                n = deleteBeginning(arr,n); break;
            case 7:
                printf("Enter number to delete: "); scanf("%d",&val);
                n = deleteNumber(arr,n,val); break;
            case 8:
                n = deleteEnd(arr,n); break;
            case 9:
                printf("Enter number to search: "); scanf("%d",&val);
                linearSearch(arr,n,val); break;
            case 10:
                printf("Exiting...\n"); break;
            default:
                printf("Invalid choice!\n");
        }
    } while(op != 10);

    return 0;
}
