#include "fifo.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 


/* associates the fifo with memory in the system */
/* clears the FIFO and sets the fifo size */

//Linked list node for fifo
struct Node{
  int data;
  struct Node* next;
};


struct Node* front;
struct Node* rear;

struct Fifo { 
    struct Node *front, *rear; 
};

void fifo_init()
{
  struct Fifo* q = (struct Fifo*)malloc(sizeof(struct Fifo)); 
    q->front = q->rear = NULL; 
}

/* remove all elements from the FIFO but maintains memory allocation*/
void fifo_clear()
{
  if(IsEmpty())
    printf("list empty \n");

  struct Node* temp = front;
  while(temp != NULL){
    temp->data = 0;
    temp = temp->next;
  }
}

/* deallocate the FIFO from memory */
void fifo_delete()
{ 
  if(IsEmpty())
    printf("list empty \n");

  struct Node* temp = front;
  while(temp != NULL){
    front = temp->next;
    free(temp);
    temp = front;
  }
  front = rear = NULL;
}

struct Node* createNode(int x){
  struct Node* temp = (struct Node*)malloc (sizeof(struct Node));
  temp->data = x;
  temp->next = NULL;
  return temp;
}

/* push a new value into the FIFO */
void fifo_push(int val)
{
  struct Node* newNode = createNode(val);
  if(IsEmpty()){ 
    front = rear = newNode;
  }
  else{
    rear->next = newNode;
    rear = newNode;
  }

}

/* remove and return the oldest value in the FIFO*/
int fifo_pop()
{
  int num;
  if(IsEmpty())
    return 0;
  else {
    num = front->data;
    struct Node* temp = front;
    temp = temp->next;
    front = temp; 
  }
  return num;

}

// returns true if the value passed is in the FIFO
bool fifo_find(int val)
{
  if(IsEmpty())
    printf("list empty \n");

  struct Node* temp = front;
  while(temp != NULL){
    if(temp->data == val)
      return true;
    temp = temp->next;
  }
  return false;
}

bool IsEmpty(){
  if ((front == NULL) && (rear == NULL))
    return true;
  else
    return false;
}

void printfifo(){
  struct Node* temp = front;
  if(IsEmpty())
    printf("list empty \n");
  else
  {
    printf("FIFO List: ");
    while(temp != NULL){
      printf("%d,  ",temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}