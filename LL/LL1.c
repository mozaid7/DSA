#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    struct node *head;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;
    struct node *new_node = NULL;

    one = (struct node*)malloc(sizeof(struct node));
    two = (struct node*)malloc(sizeof(struct node));
    three = (struct node*)malloc(sizeof(struct node));
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("%zu\n", sizeof(struct node));

    if( one == NULL || two == NULL || three == NULL || new_node == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }

    one->data = 1;
    two->data = 2;
    three->data = 3;

    head = one;

    one->next = two;
    two->next = three;
    three->next = one;

    struct node* start = head;

    while(start != NULL && start->next != head){
        printf("%d -> ", start->data);
        start = start->next;
    }
    printf("%d -> %d", start->data, head->data);

    free(one);
    free(two);
    free(three);

    return 0;
}

// Addition of two numbers of three digits each with the help of LL, however your digits should be stored in reverse order.