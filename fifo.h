#ifndef FIFO_H
#define FIFO_H

#include <stdbool.h> 
  /* associates the fifo with memory in the system */
/* clears the FIFO and sets the fifo size */
void fifo_init();


/* remove all elements from the FIFO but maintains memory allocation */
void fifo_clear();


/* deallocate the FIFO from memory */
void fifo_delete();

/* push a new value into the FIFO */
void fifo_push(int val);


/* remove and return the oldest value in the FIFO */
int fifo_pop();


/* returns true if the value passed is in the FIFO */
bool fifo_find(int val);


bool IsEmpty();

void printfifo();
#endif
