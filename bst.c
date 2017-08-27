#include<stdio.h>
#include<stdlib.h>

/*Structure Decleration*/
struct btnode
{
int data;
struct node *left, *right;
}*root=NULL,*temp=NULL, t2, t1;

/*Function decleration*/

void insert();
void create();
void delete();
void delete1();
void inorder(struct btnode *t);
void preorder(struct btnode *t);
void postorder(struct btnode *t);
void search(struct btnode *t);
void search1(struct btnode *t, int data);
int smallest(struct btnode *t);
int largest(struct btnode *t);

/*Main Starts Here*/

void main()
{ int ch;
printf("\n\t\t~~~Binary Search Tree~~~");
printf("\n\t~~~Operations~~~");
printf("\nPress 1 to insert an element in the tree.");
printf("\nPress 2 to delete an element in the tree");
printf("\nPress 3 to perform inorder tree traversal ");
printf("\nPress 4 to perform preorder tree traversal");
printf("\npress 5 to perform postorder tree traversal");
printf("\nPress 6 to exit");
while(1)
{
printf("\nEnter Your choice: ");
scanf("%d", &ch);
    switch(ch)
    {
    case 1: insert();
            break;
    case 2: delete();
            break;
    case 3: inorder(root);
            break;
    case 4: preorder(root);
            break;
    case 5: postorder(root);
            break;
    case 6: exit(0);
    
    default: printf("\nPlease enter a correct choice!");
            break;
    }
}
}

/*Function Defination*/

/*To insert a node in tree*/
void insert()
{
create();
if(root==NULL)
    root=temp;
else
    search(root);
}

/*To create a node in tree*/
void create();
{
int data;
printf("\nEnter the data to be inserted: ");
scanf("%d",&data);
temp = (struct btnode *)malloc(sizeof(struct btnode));
temp->value = data;
temp->left = temp->right = NULL;
}

/*To search appropriate postion of node in a tree*/
void search(struct  btnode *t)
{
if((temp->data > t->data) && (t->right != NULL)) //value is more than the root value insert at right
    search(t->right);
if((temp->data > t->data) && (t->right == NUll))
    t->right = temp;    
if((temp->data < t->data) && (t->left != NULL)) //value is less than root value insert at left
    search(t->right);
if((temp->data < t->data) && (t->left == NUll))
    t->left = temp;
}

/*Reccursive function to perform inorder traversal*/
void inorder(struct btnode *t)
{
if(root == NULL)
    {    
    printf("\nError: No element to display !");
    return;   
    }
else
    {
    if(t->left != NULL)
    inorder(t->left);
    printf("%d->", t->value);
    if(t->right != NULL)
    inorder(t-right);
    }
}    

/*Reccursive function to perform preorder traversal*/
void preorder(struct btnode *t)
{
if(root == NULL)
    {    
    printf("\nError: No element to display !");
    return;   
    }
else
    {
    printf("%d->", t->value);
    if(t->left != NULL)
    inorder(t->left);
    if(t->right != NULL)
    inorder(t-right);
    }
}    

/*Reccursive function to perform postorder traversal*/
void postorder(struct btnode *t)
{
if(root == NULL)
    {    
    printf("\nError: No element to display !");
    return;   
    }
else
    {
    if(t->left != NULL)
    inorder(t->left);
    if(t->right != NULL)
    inorder(t-right);
    printf("%d->", t->value);    
    }
}    

/* To check for the deleted node */

void delete()
{
    int data;
    if (root == NULL)
    {
        printf("\nNo elements in a tree to delete");
        return;
    }
    printf("\nEnter the data to be deleted : ");
    scanf("%d", &data);
    t1 = root;
    t2 = root;
    search1(root, data);
}

/* Search for the appropriate position to insert the new node */
void search1(struct btnode *t, int data)
{
if((data>t->value))
    {
    t1 = t;
    search1(t->right, data);    
    }
else if((data < t->value))
    {
    t1 = t;
    search(t->left, data);
    }
else if((data == t->value))
    {
     delete1(t);
    }
}

/* To delete a node */
void delete1(struct btnode *t)
{
    int k;
    /* To delete leaf node */
    if ((t->left == NULL) && (t->right == NULL))
    {
        if (t1->left == t)
        {
            t1->left = NULL;
        }
        else
        {
            t1->right = NULL;
        }
        t = NULL;
        free(t);
        return;
    }
    /* To delete node having one left hand child */
    else if ((t->right == NULL))
    {
        if (t1 == t)
        {
            root = t->left;
            t1 = root;
        }
        else if (t1->left == t)
        {
            t1->left = t->left;
        }
        else
        {
            t1->right = t->left;
        }
        t = NULL;
        free(t);
        return;
    }
 
    /* To delete node having right hand child */
    else if (t->left == NULL)
    {
        if (t1 == t)
        {
            root = t->right;
            t1 = root;
        }
        else if (t1->right == t)
            t1->right = t->right;
        else
            t1->left = t->right;
        t == NULL;
        free(t);
        return;
    }

    /* To delete node having two child */
    else if ((t->left != NULL) && (t->right != NULL))  
    {
        t2 = root;
        if (t->right != NULL)
        {
            k = smallest(t->right);
            flag = 1;
        }
        else
        {
            k =largest(t->l);
            flag = 2;
        }
        search1(root, k);
        t->value = k;
    }
}
}

/* To find the smallest element in the right sub tree */
int smallest(struct btnode *t)
{
    t2 = t;
    if (t->left != NULL)
    {
        t2 = t;
        return(smallest(t->left));
    }
    else    
        return (t->value);
}
 
/* To find the largest element in the left sub tree */
int largest(struct btnode *t)
{
    if (t->right != NULL)
    {
        t2 = t;
        return(largest(t->right));
    }
    else    
        return(t->value);
}
