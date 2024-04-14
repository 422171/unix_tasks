#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
int main(){
	struct stack sObj;
	init(&sObj);
	int n;
	printf("Enter the length of stack: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the data of stack: ");
	for (int x=0;x<n;x++){
		scanf("%d",&a[x]);
		push(&sObj,a[x]);
	}
	int item;
	if(!isEmpty(&sObj)){

		peek(&sObj,&item);
		printf("%d is the current element in the top\n",item);
	}
	printf("The elements of the stack are being popped\n");
	while(!isEmpty(&sObj)){
		pop(&sObj,&item);
		printf("%d\t",item);
	}
	printf("\n");
	destroy(&sObj);
	return 0;
}
