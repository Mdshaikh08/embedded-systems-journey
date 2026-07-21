#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node *link; 
};

void add_node(struct node *start,int *total_nodes ,int no_of_node_to_add){
     int total = 1;
     while (start->link != NULL)
    {
        start = start->link;
        total++;
    }
    int original_add_amount = no_of_node_to_add;

    
   while (no_of_node_to_add != 0)
   {
    start->link = (struct node*)calloc(1, sizeof(struct node));
    start = start->link;
    no_of_node_to_add--;
   }



*total_nodes = total + original_add_amount;
}


int main(){
    struct node *start = (struct node*)calloc(1, sizeof(struct node));
    int no_of_nodes = 1;
    add_node(start,&no_of_nodes,3);
   
    
}