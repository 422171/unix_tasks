#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int length=0;
//function 1
bool insertByPosition(int item,int pos){
	if (length==MAX_SIZE) {
		//array is full
		return false;
	}
/*	if (pos<0 || pos>length){
		//invalid position
		return false;
	}
*/	for (int i=length-1; i>=pos; i--){
		//shifting all elements after the pos to the next index
		arr[i+1]=arr[i];
		//in this way, every element of the array is preserved
	}
	//inserting item at pos
	arr[pos]=item;
	length++; //due to the addition(i.e., insertion) of item
	return true;
}
//function 2
bool display(){
	if (length==0){
		//array is empty
		return false;
	}

	for (int i=0; i<length; i++){
		//displaying each element of the array
		printf("%d ",arr[i]);
	}
	printf("\n");
	return true;
}
//function 3
bool deleteByPosition(int pos,int *item){
	if (length==0){
		//array is empty
		*item=-1;
		return false;
	}
	if (pos<0 || pos>=length){
		//invalid position
		*item=-1;
		return false;
	}
	*item=arr[pos];//returning deleted element through pointer named item
	for (int i=pos; i<length-1; i++){
		//in order to form a continuous array
		arr[i]=arr[i+1];
	}
	length--;//due to deletion of element at "pos"
	return true;
}
//function 4
bool search(int item,int *pos){
	if (length==0){
	//array is empty
		*pos=-1;
		return false;
	}
	int i=0;
	while (i<length && arr[i]!=item){
		i++;
	}
	if (i==length){
		//item is not present
		*pos=-1;
		return false;
	}
	else {
		*pos=i;
		return true;
	}
}
//function 5
bool deleteByItem(int item, int *pos){
	if (length==0){
		//array is empty
		*pos=-1;
		return false;
	}
	if (!search(item, pos)){
		return false;
	}
	return deleteByPosition(*pos,&item);
}
//function 6
bool oddEvenSort(){
	for (int i=0; i<length; i+=2){
		for (int j=i+2; j<length; j+=2){
			if (arr[j]>arr[i]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			} 
		} 
	
	}
	for (int i=1; i<length; i+=2){
		for (int j=i+2; j<length; j+=2){
			if (arr[j]<arr[i]){
					int temp=arr[i];
					arr[i]=arr[j];
					arr[j]=temp;	
			} 
		} 
	}
	return true;
}

//main function (implementation)
int main(){
	int item;// = 62;
	int pos ;//= 2;

	insertByPosition(89,0);
	insertByPosition(78,1);
	insertByPosition(94,2);
	insertByPosition(87,1);
	insertByPosition(62,4);

	insertByPosition(95,4);
	insertByPosition(51,3);
	printf("The original array: ");
	display();
	if(insertByPosition(item, pos))
		printf("item %d inserted at pos %d\n",item, pos);
	
	int deleteditem;
	if (deleteByPosition(0,&deleteditem)){
		printf("Deleted item: %d\n",deleteditem);
	}
	else{
		printf("Deletion has failed\n");
	}

	int searcheditem;
	if (search(94,&searcheditem)){
		printf("Item is found at position: %d\n",searcheditem);
	}
	else{
		printf("Item could not be found\n");
	}

	int deletedpos;

	if (deleteByItem(94,&deletedpos)){
		printf("Deleted item at position: %d\n",deletedpos);
	}
	else{
		printf("Deletion has failed\n");
	}

	oddEvenSort();
	printf("Array after oddEvenSort: ");
	display();
	return 0;
}
