#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node *next;
}node;
node* concatenate (node *head1, node *head2){
	node *temp;
	temp=head1;
	while(temp->next!=NULL){		
	temp=temp->next;	
	}
	temp->next=head2;	
	return head1;	
}
void sonaekle(node *head, int a){
	node *temp;
	temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=malloc(sizeof(node));
	temp->next->val=a;
	temp->next->next=NULL;
}
void basaekle(node **head, int a){
	node *temp;
	temp=malloc(sizeof(node));
	temp->val=a;
	temp->next=*head;
	*head=temp;
}
void bastir(node *head){
	node *iter;
	iter=head;
	while(iter!=NULL){
		printf("%d ",iter->val);
		iter=iter->next;
	}
	printf("\n");
}

int main(){
	node *head1, *head2;
	head1=malloc(sizeof(node));
	head2=malloc(sizeof(node));
	head1->val=5;
	head2->val=10;
	head1->next=NULL;
	sonaekle(head1,25);
	sonaekle(head1,35);
	basaekle(&head1,85);
	head2->next=NULL;
	sonaekle(head2,45);
	sonaekle(head2,30);
	printf("head1 before concatenation:\n");
	bastir(head1);
	printf("head2 before concatenation:\n");
	bastir(head2);
	node *h3;
	h3=concatenate(head1,head2);
	printf("after concatenation:\n");
	bastir(h3);
}
