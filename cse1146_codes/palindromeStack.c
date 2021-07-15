#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100
char inputS[MAXSIZE*2];

struct lifo 
{
	char st[MAXSIZE];
	int top;
};
typedef struct lifo stack;
stack s;

void push (stack *s, int element){
    if(s->top==MAXSIZE-1){
        exit(-1);
    }
    else
    s->top++;
    s->st[s->top]=element;
}
int pop (stack *s){
    return s->st[s->top--];
}
int isEmpty(stack *s){
    if(s->top==-1)
        return 1;
    else
        return 0;
}
void create(stack *s){
    s->top=-1;
}

int main(){
    /*Get the input length*/
    scanf("%s", inputS);
    int len,i;
    len=strlen(inputS);
    /*Push first half to the stack*/
    for(i=0; i<len/2;i++){
        push(&s, inputS[i]);
    }
    int check=0;
    /*Pop and compare*/
    if(len%2==1)
    len++;
    for(i=len/2; i<len; i++){
        if(pop(&s)==inputS[i])
        check++;
    }
    if(check==len/2){
        printf("Text is palindrome!");
    }
    else
    printf("Text is not palindrome!");
}
