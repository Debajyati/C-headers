#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node* link;
}node;

node * root = NULL;
int len;

void addatbegin();
void addatafter();
void append();
int length();
void display();
void deleteNode();

void append(){
  /*appends a node to the end of the linkedlist*/
  node *temp;
  temp = (node*)malloc(sizeof(node));

  printf("Enter node data\n");
  scanf("%d",&temp->data);
  temp->link = NULL;

  if (root==NULL) { //list is empty
    root = temp;
  }   
  else {
    node*p;
    p=root;
    while (p->link !=NULL) {
      p=p->link;
    }
    p->link=temp;
  }
}

void addatBegin()
{
    /*adds a node to the beginning of the Linkedlist*/
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("enter Node data\n");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        temp->link = root; //[right]
        root = temp;       //[left]
    }
}

void addatAfter()
{
  /*adds a node after to the user specified location*/
    struct Node* temp,*p;
    int loc,i=1;
    printf("Enter location :\n");
    scanf("%d",&loc);

    len = length();
    if (loc>len)
    {
        printf("Invalid location\n");
        printf("Currently list is having %d Nodes\n",len);
    }
    else
    {
        p=root;
        while (i<loc)
        {
            p=p->link;
            i++;
        }
        temp = (struct Node*)malloc(sizeof(struct Node));
        printf("enter Node data\n");
        scanf("%d", &temp->data);
        temp->link = NULL;
        temp->link=p->link;//right
        p->link = temp;//left
    }

}

int length()
{
  /*calculates the length of the linkedlist*/
    int count = 0;
    struct Node *temp;
    temp = root;

    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;
}

void display()
{
  /*displays the linkedlist*/
    struct Node *temp;
    temp = root;

    if (temp == NULL)
    {
        printf("List is empty, means list has currently no nodes. \n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->link;
        }
        printf("\n\n");
    }
}

void deleteNode()
{
  /*deletes a node at the user specified location*/
    struct Node* temp;
    int loc;
    printf("Enter location to delete :\n");
    scanf("%d",&loc);
    if (loc>length())
    {
        printf("Invalid location\n");
    }
    else if (loc == 1)
    {
        temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }
    else
    {
        struct Node *p = root,*q;
        int i =1;
        while(i<loc-1){
            p = p->link;
            i++;
        }
        q=p->link;
        p->link = q->link;
        q->link = NULL;
        free(q);
    }


}

#endif
