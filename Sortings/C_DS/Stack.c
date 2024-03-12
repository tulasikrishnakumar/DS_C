#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int str_arr[MAX];
int top = -1;
int isEmpty();
int isFull();

void push(int x){
    if(top == MAX){
        printf("The stack is full");
        return;
    }
    top += 1;
    str_arr[top] = x;
}
void display(){
    if(top == -1){
        printf("the stack is empty");
        return;
    }
    for(int i=0;i<=top;i++){
        printf("%d ",str_arr[i]);
    }
    printf("\n");
}
void pop(){
    int value;
    if(top==-1){
        printf("The stack is empty");
    }
    else{
        value=str_arr[top];
        top -= 1;
        printf("the element deleted %d", value);
    }
}
int isFull(){
    if(top==MAX)
        printf("The stack is full"); 
    else 
        printf("The stack is not full");
    return 0;
}
int isEmpty(){
    if(top==-1)
        printf("The Stack is empty");
    else
        printf("The Stack is not empty");
    return 0;
}

int main(){
    int choice,data;
    while(1){
        printf("\n");
        printf("---1.PUSH \n");
        printf("---2.POP\n");
        printf("---3.IS_EMPTY\n");
        printf("---4.IS_FULL\n");
        printf("---5.DISPLAY\n");
        printf("---6.EXIT\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the element to insert");
            scanf("%d",&data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            isEmpty();
            break;
        case 4:
            isFull();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("_---WRONG INPUT---_");
        }
    }
}
