#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node *next;
}node;
void insertLast(node *head, int a){
	node *temp;
	temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=malloc(sizeof(node));
	temp->next->val=a;
	temp->next->next=NULL;
}
void insertGivenLoc(node **head, node *temp,int konum){
	node *prev;
	node *current;
	current=*head;
	prev=NULL;
	int a=1;
	
	while(current!=NULL && a != konum){
		prev=current;
		current=current->next;
		a++;
	}
	if(prev==NULL){
		temp->next=*head;
		*head=temp;
	}
	else{
		temp->next=current;
		prev->next=temp;
	}
	
}
void bastir(node *head){
	while(head!=NULL){
		printf("%d ", head->val);
		head=head->next;
	}
	printf("\n");
}
int main(){
	node *head;
	head=malloc(sizeof(node));
	head->val=1;
	head->next=NULL;
	insertLast(head,1);
	insertLast(head,1);
	insertLast(head,1);
	insertLast(head,1);
	insertLast(head,1);
	bastir(head);
	int loc;
	scanf("%d", &loc);
	node *temp;
	temp=malloc(sizeof(node));
	temp->val=2;
	temp->next=NULL;
	insertGivenLoc(&head,temp,loc);
	bastir(head);
}
