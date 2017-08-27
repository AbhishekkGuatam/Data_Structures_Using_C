/*Stack Program*/
#include<stdio.h>
#include<stdlib.h>

/*Structure defination*/
struct node{
            int data;
            struct node *next;            
            }*top=NULL, *temp, *new;
            
/*function prototype*/
void push();
void pop();
void display();
void count();
