#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

int main(){
    struct node *head;
    struct node *prev;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    one = (struct node*)malloc(sizeof(struct node));
    two = (struct node*)malloc(sizeof(struct node));
    three = (struct node*)malloc(sizeof(struct node));
    printf("%zu\n", sizeof(struct node));

    if( one == NULL || two == NULL || three == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }

    one->data = 1;
    two->data = 2;
    three->data = 3;

    head = one;

    one->next = two;
    one->prev = NULL;
    two->next = three;
    two->prev = one;
    three->next = NULL;
    three->prev = two;

    struct node* start = head;
    while(start != NULL){
        printf("%d -> ", start->data);
        start = start->next;
    }
    printf("NULL\n");

    free(one);
    free(two);
    free(three);

    return 0;
}