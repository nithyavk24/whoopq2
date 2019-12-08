#include <stdio.h>
#include "fifo.h"

int main(void) {
  fifo_init();
  int val;
  while(true){
    printf("\n SELECT AN OPTION FOR OPERATION TO BE PERFORMED\n 1.push\n 2.pop\n 3.clear\n 4.delete list\n 5.find number\n");
    scanf("%d", &val);
    printf("OPTION SELECTED: %d \n", val);

    switch(val){
      case(1):{
        int pushElement;  
        printf("Enter the value to be inserted\n");
        scanf("%d", &pushElement);
        fifo_push(pushElement);
        printfifo();
        printf("\n");
        break;
      }
      case(2):{
        fifo_pop();
        printfifo();
        printf("\n");
        break;
      }
      case(3):{
        fifo_clear();
        printfifo();
        printf("\n");
        break;
      }
      case(4):{
        fifo_delete();
        printfifo();
        printf("\n");
        break;
      }
      case(5):{
        int find;
        printf("Enter the number you want to find in the list \n");
        scanf("%d", &find);
        if(fifo_find(find))
          printf("Found\n");
        else
          printf("not found\n");
        printf("\n");
        break;
      }
        

    }
    
  }
  return 0;
  // fifo_push(25); printfifo();
  // fifo_push(100);printfifo();
  // fifo_push(3); printfifo();
  // fifo_delete();

  // fifo_push(7); printfifo(); 
  // fifo_push(9); printfifo();
  // fifo_clear(); printfifo();
  // fifo_push(6); printfifo();
  // fifo_push(5); printfifo();
  // if(fifo_find(1))
  //   printf("found \n");
  // else 
  //   printf("not found \n");
  
  // printfifo();
  // if(fifo_find(5))
  //   printf("found \n");
  // else 
  //   printf("not found \n");
}