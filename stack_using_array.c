#include<stdio.h>

/*Global Declerations*/
int count, arr[10], top;
count = 0;
top = -1;
/*funtion prototyping */
void push(int );
int pop();
int count();
void display();

/*Main */
void main()
{
int ch, x;
printf("\n\t\t~~~STACK USING ARRAY~~~");
while(1)
{
system("clear");
printf("\npress 1 to push an element.");
printf("\npress 2 to pop an element.");
printf("\npress 3 to count the element in stack");
printf("\npress 4 to display stack");
printf("\npress 5 to exit program");
printf("\n\t Enter your choice: ");
scanf("%d", &ch);
    switch(ch)
    {
    case 1: printf("\nEnter the element to be pushed");
            scanf("%d", &x);
            push(x);
            break;
    case 2: pop();
            break;
    case 3: count();
            break;
    case 4: display();        
    case 5: printf("\nThank You :) for using my program\n\n");
            exit(0);
    default: printf("\nYou have netered a wrong option");
            break;
    }
}
}

/*FUNCTION DECLERATION1*/

void push(int x)
{
if(
}
