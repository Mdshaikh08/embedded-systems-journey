#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
    int data;
    struct Node *node;
}list;

static list *head_node = NULL;
static list *tail_node = NULL;

int insert_at_head(int);
int insert_at_tail(int);
int delete_node(int);
int reverse_list(void);
int free_list(void);

int main(){

    
    insert_at_head(12);
    insert_at_head(11);
    insert_at_head(10);

    for (int i = 2; i < 7; i++)
    {
        insert_at_tail(i*10);
    
    }

    delete_node(60);
    delete_node(12);

    
    
    
    
  
    
    reverse_list();
    
   list* p1 = head_node;

    while(p1 != NULL){
        printf("%d \n" , p1->data);
        p1 = p1->node;
    }

    free_list();
    
}

int insert_at_tail(int data){

    list *temp = (list*)malloc(sizeof(list));

    if(temp == NULL){
        return 0;
    }


    if(tail_node == NULL){
        tail_node = temp;
        head_node = temp;
    }
    else{

    tail_node->node = temp;
    tail_node = tail_node->node;
}
    tail_node->data = data;
    tail_node->node = NULL;

    return 1;

}


int insert_at_head(int data){

    list *temp = (list*)malloc(sizeof(list));
    if(temp == NULL){
        return 0;
    }

    if(head_node == NULL){
        tail_node = temp;
    }

    temp->node = head_node;
    head_node = temp;
    head_node->data = data;

    return 1;
}



int delete_node(int data){

    list *moving = head_node;
    list *temp = head_node;

    while ((moving != NULL) && (moving->data != data) )
    {
        if(moving != head_node){
            temp = (list*)temp->node;
        }
        moving = moving->node;
    }
    if(moving == NULL){
        return 0;
    }

    if(moving == head_node){
        head_node = (list*)moving ->node;
        if(head_node == NULL) tail_node = NULL;
    }
    else{

    temp->node = moving->node;
    if(moving->node == NULL){
        tail_node = temp;
    }
    }
    free(moving);

    return 1;
    
}


int reverse_list(void){
    if(head_node->node == NULL) return 1;
    list *p = head_node;
    list *m = p->node;
    list *c = m->node;

  
    
        p->node = NULL;
        while(c != NULL){
            m->node = p;
            p = m;
            m = c;
            c = c->node;
        }

        m->node = p;
        head_node = m;


        return 1;
    }


int free_list(void){
    
    
    list *p1 ;

    while(head_node != NULL){
        p1 = head_node;
        head_node = head_node->node;
        free(p1);
    }


    tail_node = NULL;
    return 1;

}
