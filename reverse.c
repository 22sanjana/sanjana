#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;
   
};
struct node *head, *tail;
void create() 
{   
    struct node *newnode;
    head=0;
    struct node *temp;
    int choice = 1;
    while (choice)
    {
        newnode= (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->prev = 0;
        newnode->next = 0;
        if (head == 0){
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        printf("Do you want to continue (0/1)? ");
    scanf("%d", &choice);
    }

}
void display() {
    struct node *temp;
    temp = head;
    while (temp != 0) {
        printf("%d ", temp->data);
        temp = temp->next; 

    }
}
void reverse() {
    struct node *current, *nextnode;
    if (head == NULL) {
        printf("Empty list\n");
    }
    else{
    current = head;
    }
    while (current != 0){
        nextnode = current->next;
        current->next = current->prev;
        current->prev = nextnode;
        current = nextnode;
    }
    current=head;
    head=tail;
    tail=current;
}
int main() {
    head = 0;
    create();
    display();
    printf("\nOriginal list: ");
    display(head);
    reverse();
    printf("\nReversed list: ");
    display(tail);
    return 0;
}