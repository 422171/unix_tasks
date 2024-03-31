#ifndef STACK_H
#define STACK_H

#define SIZE 100

#include <stdio.h>
#include <stdlib.h>

struct stack {
	int arr[SIZE];
	int top;
};

int init(struct stack *);
int destroy(struct stack *);
int push(struct stack *,int item);
int pop(struct stack *,int *item);
int peek(struct stack *,int *);
int isEmpty(struct stack *);
int isFull(struct stack *);

#endif
