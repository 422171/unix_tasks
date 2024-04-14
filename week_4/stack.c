#include <stdlib.h>
#include "stack.h"
int init(struct stack *s) {
	s->top = -1;
	return 1;
};
int destroy(struct stack *s) {
	s->top = -1;
	return 1;
};
int isEmpty(struct stack *s) {
	if(s->top == -1){
		return -1;
	}else{
		return 0;
	}
};
int isFull(struct stack *s) {
	if(s->top == SIZE-1){
		return 1;
	}else{
		return 0;
	}
};
int push(struct stack *sptr,int item) {
	if (isFull(sptr)){
		return 0;
	}else{
		(sptr->top)++;
		sptr->arr[sptr->top] = item;
		return 1;
	}
};
int pop(struct stack *sptr,int *item) {
//takes stack pointer as input,deletes the item in top and returns the deleted value as item
	if(isEmpty(sptr)){
		return 0;
	}else{
		*item = sptr->arr[sptr->top];
		(sptr->top)--;
		return 1;
	}
};
int peek(struct stack *sptr,int *item) {
//takes stack pointer as input and returns the value at top as item
	if(isEmpty(sptr)){
		return 0;
	}else{
		*item = sptr->arr[sptr->top];
		return 1;
	}
};
