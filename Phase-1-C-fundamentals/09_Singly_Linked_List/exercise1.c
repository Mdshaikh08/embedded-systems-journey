#include<stdio.h>
#include<stdlib.h>



struct node {
    int data;
    struct node *link;
};




int insert_at_head(struct node **head , int value);
void print_list(struct node *head);
int insert_at_tail(struct node **head , int value);
void free_list(struct node *head);
int delete_node(struct node **head , int value);

int main(){
    struct node *head = NULL;
    insert_at_tail(&head, 10);
    insert_at_tail(&head, 20);
    insert_at_tail(&head, 30);
    insert_at_tail(&head, 40);
    
    print_list(head);

    delete_node(&head, 10);
    print_list(head);

    delete_node(&head, 99);
    print_list(head);

    free_list(head);
    
    return 0;

}



int insert_at_head(struct node **head , int value){
   
    struct node * p = (struct node*)malloc(sizeof(struct node));
    if (p == NULL)
    {
       printf("The memory allocation failed!");
       return 0;
       
    }
    
    p->data = value;
    p->link = *head;
    *head   = p;

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


void free_list(struct node *head){
    struct node *temp;
    while (head  != NULL)
    {
     temp = head;
     head = head ->link;
     free(temp);
    }
     
}


int delete_node(struct node **head , int value){
    if(*head == NULL){
        printf("Pointer does not points to any list");
        return 0;
    }
 
    struct node *temp = *head;

    if(temp->data == value){ //checking the head node
        *head = temp->link;
        free(temp);
        printf("The node matching the value is at the head\n");
        return 1;
    }

    temp = temp->link;
    struct node *prev = *head;
   
        while (temp->data != value && temp->link != NULL)   
        {
            temp = temp->link;
            prev = prev->link;
        }

        if(temp->data == value){
            prev->link = temp->link;
            free(temp);
            return 1;
        }
        else{
            printf("Given Value Not Found In The List\n");
            return 0;
        }
        
    
    


}