#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
struct node *head;
int init(struct node **head){
	*head=NULL;
	return 1;
}
//SEARCH FOR A KEY FUNCTION
int searchKey(struct node **head, int key, struct node **ptrToKey){
	struct node *ptr = *head;
	for(int i=0;ptr && ptr->data!=key;i++){
		ptr=ptr->next;
	}
	*ptrToKey = ptr;
	if(!ptr){
		return 0;
	}
	else{
		return 1;
	}
}
int insertByPosition(struct node **head,int pos,int data){
	struct node *newnode;//=(struct node*)malloc(sizeof(struct node));
    struct node *ptr;// = NULL;
    if(!newnode || pos<1){
    return 0;
	}
	/*struct node **ptr1;
	if(searchKey(head,data,ptr1)==0){
		return 0;
	}*/
    newnode->data=data;
    if(pos==1){
		newnode->next=*head;
		*head=newnode;
		return 1;
    }
    ptr = *head;
    for (int i=1;i<pos-1 && ptr!= NULL;i++){
		ptr = ptr->next;
	}if (ptr == NULL){
		return 0;
	}
	else{
		newnode->next = ptr->next;
		ptr->next = newnode;
		return 1;
	}
}
int insertAfter(struct node **head,int preData,int data){
    struct node * newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode){
        return 0;
    }
    newnode->data=data;
    struct node *curr=*head;
    while (curr != NULL && curr->data != preData){
         curr = curr->next;
    }
    if(!curr){
        return 0;//predata is not found or list is empty
    }
    else{
        newnode->next=curr->next;
        curr->next=newnode;
        return 1;
    }
}
int insertBefore(struct node **head,int postData, int data){
    struct node * newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode){
        return 0;
    }
    newnode->data=data;
    struct node *curr=*head;
    struct node *pre=NULL;
    while (curr != NULL && curr->data != postData){
        pre=curr;
        curr=curr->next;
    }
    if(!curr){
        return 0;
    }
    else{
        newnode->next=pre->next;
        pre->next=newnode;
        return 1;
    }
}
//TRAVERSE THROUGH THE LIST FUNCTION
int traverse(struct node *head){
	for(struct node *ptr=head;ptr;ptr=ptr->next){
	printf("%d ->",ptr->data);
	}
	printf("NULL\n");
	return 1;
}
int deleteByPosition(struct node **head,int pos,int *data){
	if (pos<1){
		data = NULL;//illegal position entered
		return 0;
	}
	struct node *pre = NULL;
	struct node *curr = *head;
	for (int i=1;i<pos;i++){
		pre = curr;
		curr = curr->next;
	}
	if(!pre){
		*head = (*head)->next;//delete at beginning
	}else{
		pre->next = curr->next;//delete at middle or end
	}
	*data = curr->data;
	free(curr);
	return 1;
}
int deleteItem(struct node **head, int data){
	struct node *pre = NULL;
	struct node *curr = *head;
	while(curr && curr->data != data){
		pre = curr;
		curr = curr->next;
	}
	if(!curr){
		return 0;//no such data present to delete
	}else{
		if(!pre){
			*head = (*head)->next;//delete at beginning
			free(curr);
			return 1;
		}else{
			pre->next = curr->next;//delete at middle or end
			free(curr);
			return 1;
		}
	}
}
int destroy(struct node **head){
	struct node *ptr = *head;
	while(*head){
		*head = (*head)->next;
		free(ptr);
		ptr = *head;
	}
	return 1;
}

int reverseList(struct node **head){
	if(!(*head))
		return 0;
	struct node *f=*head,*s=(*head)->next;//first and second ptrs
	while(s){
		f->next = s->next;
		s->next = *head;
		*head = s;
		s = f->next;
	}
	return 1;
}

int deleteKey(struct node **head, int key){
	struct node *pre = NULL;
	struct node *ptr = *head;
	if((*head)->data == key){
		*head = (*head)->next;//delete at beginning
			free(ptr);
			return 1;
	}
	while(ptr && ptr->data != key){
		pre = ptr;
		ptr = ptr->next;
	}
	if(!ptr)
		return 0;//key not present
	else{
		pre->next = ptr->next;//delete at middle or end
		free(ptr);
		return 1;
	}
}

int findKthNodeFromEnd(struct node *head,int k){
	struct node *f = head,*s = NULL;//first and second ptrs
	if(!head)
		return 0;
	for(int i=0;i<k-1;i++)
		f = f->next;
	if(!f)
		return 0;
	s = head;
	while(f->next){
		f = f->next;
		s = s->next;
	}
	printf("%d is at position %d from the end\n",s->data,k);
	return 1;
}


int main() {
	int data =0;
	struct node *head;
	init(&head);
	for (int i=1;i<=5;i++){
		insertByPosition(&head,i,i);
	}
	printf("Initial list: ");
	traverse(head);
	reverseList(&head);
	printf("Reversed list: ");
	traverse(head);
	int key;
	printf("Enter key to insert: ");
	scanf("%d",&key);
	int pos;
	printf("Enter pos to insert: ");
	scanf("%d",&pos);	
	insertByPosition(&head,pos,key);
	printf("New list: ");
	traverse(head);
	
	insertByPosition(&head,3,78);
	traverse(head);
	insertAfter(&head,78,66);
	traverse(head);	
	insertBefore(&head,4,53);
	traverse(head);	
	struct node **ptr;
	searchKey(&head,5,ptr);
	printf("%p\n",ptr);
	deleteByPosition(&head,2,&data);
	printf("%d is deleted from the list\n",data);
	deleteItem(&head,1);
	traverse(head);
	int d = destroy(&head);
	if (d = 1){
		printf("The list is destroyed\n");
	}else{
		printf("Failed to destroy the list\n");
	}
	return 1;
}