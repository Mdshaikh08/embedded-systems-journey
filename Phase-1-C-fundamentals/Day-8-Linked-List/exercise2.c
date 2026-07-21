#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};



int insert_at_tail(struct node**head , int value);
void free_list(struct node *head);
void print_list(struct node *head);
int reverse_list(struct node **head);


int main(){

    struct node *head = NULL;
    insert_at_tail(&head, 10);
    insert_at_tail(&head, 20);
    insert_at_tail(&head, 30);
    insert_at_tail(&head, 40);

    print_list(head);
    reverse_list(&head);
    print_list(head);


    free_list(head);
    return 0;
}








int insert_at_tail(struct node **head , int value){
    struct node *p = malloc(sizeof(struct node));
    if(p == NULL){
        printf("The memory allocation failed!");
        return 0;
    }
   
        p ->data = value;
        p->link = NULL;
        if(!*head){
            *head = p;
        }
        else{
           struct node *temp = *head;
           while (temp -> link != NULL)
           {
            temp = temp ->link;
           }
           temp -> link = p;
           
           
        }
        return 1;
    
}


void print_list(struct node *head){
    printf("The values in Linked List are : " );

    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head ->link;
    }
    printf("\n");
    
}   


void free_list(struct node *head){
    struct node *temp;
    while (head  != NULL)
    {
     temp = head;
     head = head ->link;
     free(temp);
    }
     
}


int reverse_list(struct node **head){
 struct node *p , *c , *n ;
 p = NULL;
 if (*head == NULL) return 0;
 c = *head;
 n = (*head)->link;

 while(n){
    c->link = p;
    p = c ;
    c = n;
    n = n->link;
 }
 c->link = p;
 p = c;
 *head = c;

 return 1;

}