#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int val;
	struct node *next;
}node;
node *head;
void print_linked_list(){
	node *iter;
	iter=head;
	if(head==NULL){
		printf("Linked list is empty.");
		return;
	}
	printf("Linked list items: ");
	while(iter!=NULL){
		printf("%d " ,iter->val);
		iter=iter->next;
	}
	printf("\n");
}
void insert_at_last(int value){
	node *temp;
	temp=head;
	if(head==NULL){
		head=malloc(sizeof(node));
		head->val=value;
		head->next=NULL;
	}
	else{	
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=malloc(sizeof(node));
	temp->next->val=value;
	temp->next->next=NULL;
}
}
void insert_at_first(int value){
	node *temp;
	temp=malloc(sizeof(node));
	temp->val=value;
	temp->next=head;
	head=temp;
}
void insert_after(int key,int value){
	node *temp;
	temp=head;
	while(temp->val!=key && temp!=NULL){
		temp=temp->next;
	}
	if(temp!=NULL){
		node *iter;
		iter=malloc(sizeof(node));
		iter->val=value;
		iter->next=temp->next;
		temp->next=iter;
	}
}
void delete_item(int value){
	node *temp; //node to be deleted
	if(head==NULL){
		printf("Element not found!");
		return;
	}
	if(head->val==value){
		temp=head;
		head=head->next;
		printf("%d is deleted from the list.", value);
		free(temp);
	}
	else{
		node *cur;
		node *prev;
		prev=NULL;
		cur=head;
		while(cur!=NULL && cur->val!=value){
			prev=cur;
			cur=cur->next;
		}
		if(cur!=NULL){
			temp=cur;
			prev->next=cur->next;
			printf("%d is deleted from the list.", value);
			free(temp);
		}
		else{
			printf("Element not found!");
		}
	}
}
void search_item(int value){
	node *temp;
	temp=head;
	int flag=0;
	while(temp!=NULL){
		if(temp->val==value){
			flag=1;
			break;
		}
		temp=temp->next;
	}
	if(flag==1)
	printf("%d is present in the list.", value);
	else
	printf("Element not found!");
}
int main(){
	head=NULL;	
	int key, val;
    char command[20];
	command[0] = '\0';
	while (strcmp(command, "bye")) {
		scanf("%s",command);		
		if(!strcmp(command,"insertLast")) {
			scanf("%d",&val);
			insert_at_last(val);
			printf("%d is inserted to the last.", val);
		}
		else if(!strcmp(command,"insertFirst")) {
			scanf("%d",&val);
			insert_at_first(val);
			printf("%d is inserted to the first.", val);
		}
		else if(!strcmp(command,"insertAfter")) {
			scanf("%d",&key);
			scanf("%d",&val);
			insert_after(key,val);
			printf("%d is inserted after %d.", val, key);
		}
		else if(!strcmp(command,"deleteItem")) {
			scanf("%d",&val);
			delete_item(val);
		}
		else if(!strcmp(command,"searchItem")) {
			scanf("%d",&val);
			search_item(val);
		}
		else if(!strcmp(command,"print")){
			print_linked_list();
		}
		else if (strcmp(command, "bye") == 0) {
            printf("End session.\n");
        }
		else{
			printf("No such command!");
		}
	} 
	}

