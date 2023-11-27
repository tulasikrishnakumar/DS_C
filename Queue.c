#include<stdio.h>
#include<stdlib.h>

int rear=-1;
int front=-1;
int i;
int x;
int n[100];

void insert(int x){
    if(rear>=i-1){
        printf("The Queue is full\n");
    }
    else{
        rear++;
        printf("Enter the elemnt you want to insert:- \n");
        scanf("%d",&x);
        n[rear]=x;
    }
}
void delete(){
    if(front==rear){
        rear=-1;
        front=-1;
    }
    else{
        front++;
    }
}
void display(){
    if(rear==front){
        rear=front=-1;
        printf("The Queue is empty\n");
    }
    else{
        printf("The elements of Queue are:- \n");
        for(int j=front+1;j<=rear;j++){
            printf("%d ",n[j]); 
        }
    }
    printf("\n");
}
int main(){
    printf("\nEnter the size of the Queue:- \n");
    scanf("%d",&i);
    int n[i];
    int ch;
    
    while(1){
        printf("choose an option:-\n ");
        printf("1.INSERT\n 2.DELETE\n 3.DISPLAY\n 4.EXIT\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                insert(x);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("invalid input\n");
                break;
        }
    }
    return 0;
}