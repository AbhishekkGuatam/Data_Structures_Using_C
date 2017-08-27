/*Sinle Link List Program*/
#include<stdio.h>
#include<stdlib.h>

/*Structure defination*/
struct node{
int data;
struct node *next;
}*new, *cur, *next1, *prev, *sen=NULL, *head=NULL, *temp=NULL;

/*Function Prototypes*/
void insert();
void insertBeg();
void insertEnd();
void insertMed();
void create();
void traverse();
void search(int );
void delete();
void deleteBeg();
void deleteMed();
void deleteEnd();
void count();
void toCLL();
void toSLL();
struct node * revList(struct node *);
void revrse(struct node *, struct node *);
/*Main*/
void main(){
int ch, x;
printf("\n\t\t~~~Single Link List~~~");
while(1)
{
system("clear");
printf("\npress 1 to insert a node.");
printf("\npress 2 to travese linked list.");
printf("\npress 3 to search an element");
printf("\npress 4 to delete an element");
printf("\npress 5 to count total elements");
printf("\npress 6 to reverse list");
printf("\npress 7 to reverse list recursively");
printf("\npress 8 to covert single link list to circular link list");
printf("\npress 9 to convert circular link list to single link list");
printf("\npress 11 to exit program");
printf("\n\t Enter your choice: ");
scanf("%d", &ch);
    switch(ch)
    {
    case 1: insert();
            break;
    case 2: traverse(head);
            break;
    case 3: printf("\nEnter the element to be searched: ");
            scanf("%d", &x);
            search(x);
            break;
    case 4: delete();
            break;
    case 5: count();        
            break;
    case 6: head = revList(head);
            break;
    case 7: revrse(NULL,head);
            break;
    case 8: toCLL();
            break;
    case 9: toSLL();
            break;
    case 11: printf("\nThank You :) for using my program\n\n");
            exit(0);
    default: printf("\nYou have netered a wrong option");
            break;
    }
}
}

/*function definations*/
void traverse()
{
system("clear");
if(head == NULL)   
   { printf("\nError: No Node exist, Please create a linked list first!"); }
else
    {
    temp = head;
    while(temp)
        {
        printf("%d -> ", temp->data);
        temp=temp->next;
        }
    }
}

void create()
{
int x;
new = (struct node *)malloc(sizeof(struct node));
printf("\nEnter the data: ");
scanf("%d", &x);
new->data = x;
new->next = NULL;
}

void insert()
{ int ch;
while(1)
    {
    system("clear");
    printf("\n\t~~~Insert Node in a linked list~~~");
    printf("\nPress 1 to insert a node in Begining");
    printf("\nPress 2 to insert a node after a specific node");
    printf("\nPress 3 to insert a node in the end");
    printf("\nPress 4 to return to main menu");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch)
        {
        case 1: insertBeg();
                break;
        case 4: return;
        case 2: insertMed();
                break;
        case 3: insertEnd();
                break;
        }
    }
}

void insertBeg()
{
create();
if(head==NULL)
{   head = new;
    temp = head;
   }
else
    {
    new->next = head;
    head = new;
    temp = head;
    }
}
/*INSERT A NODE AT THE END*/
void insertEnd()
{
create();
if(head==NULL)
{   head = new;
    temp = head;
   }
else 
    {
    temp = head;
    while(temp->next){
            temp = temp->next; }
    temp->next = new;
    }
}

/*INSERT A NODE AT A SPECIFIC POSTION*/
void insertMed()
{int y;
printf("\nEnter the element after which you want to insert: ");
scanf("%d", &y);
search(y);
if(temp==NULL)
{
printf("\n Cannot insert as the postion doesnot exist!");
return;
}
else
{
create();
(new->next)=(temp->next);
temp->next=new;
}
}
/*SEARCH A PARTICULAR NODE!*/
void search(int x)
{
temp = head;
while(temp)
{
if(temp->data == x)
{printf("\nElement found");
return;
}
else
temp= temp->next;
}
if(temp==NULL)
{
printf("\nThe element doesnot exist in the linked list");
return;
}
}

/*DELETION*/

void delete()
{ int ch;
while(1)
    {
    system("clear");
    printf("\n\t~~~Delete Node in a linked list~~~");
    printf("\nPress 1 to delete a node in Begining");
    printf("\nPress 2 to delete a specifc node");
    printf("\nPress 3 to delete a node in the end");
    printf("\nPress 4 to return to main menu");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch)
        {
        case 1: deleteBeg();
                break;
        case 4: return;
        case 2: deleteMed();
                break;
        case 3: deleteEnd();
                break;
        }
    }
}

void deleteBeg()
{
temp = head;
head = head ->next;
free(temp);
}
void deleteMed()
{	int key;
temp = head;
printf("\nEnter the element to be deleted");
scanf("%d",&key);
search(key);
if(temp->next ==NULL)
{free(temp);}
else if(temp->next->next==NULL)
{
next1=temp->next;
free(next1);
temp->next=NULL;
}
else
{
while(temp->next->data != key)
{
temp=temp->next;
next1=temp->next;
temp=next1->next;
free(next1);
}
}
}
void deleteEnd()
{
temp = head;
if(temp->next==NULL)
{
free(temp);
head=NULL;
}
else
{
while(temp->next->next!=NULL)
{temp=temp->next;}
free(temp->next);
temp->next=NULL;
}
}

void count()
{ int count = 0;
temp=head;
while(temp!=NULL)
{count = count +1;
temp=temp->next;
}
sen->data = count;
printf("\n\t Count = %d", count);
}

/*REVERSE LINK LIST*/
struct node * revList(struct node *cur)
{
prev =NULL;
next1=NULL;
while(cur)
{
next1=cur->next;
cur->next=prev;
prev=cur;
cur=next1;
}
return prev;
}

/*recursively reverse list*/
void revrse(struct node *prev, struct node *cur)
{if(cur)
{
revrse(cur,cur->next);
cur->next=prev;
} else {
head = prev;
}
}

void toCLL()
{
/*
count();
system("clear");
temp=head;
while(temp!=NULL)
{temp=temp->next;}
temp=sen;
sen->next = head;

*/}

void toSLL()
{if(sen==head){
temp=head;
while(temp->next!=head)
{temp=temp->next;}
sen->next=NULL;
temp->next=NULL;
}
}
