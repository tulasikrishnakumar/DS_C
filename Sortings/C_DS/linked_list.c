#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
int count=0;
void insertAtBegin(int x){
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=x;
    new->next=NULL;
    new->next=head;
    head=new;
    count++;
}
void insertAtEnd(int x){
    struct node *new =(struct node *)malloc(sizeof(struct node));
    new->data=x;
    new->next=NULL;
    struct node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new;
    count++;
}
void insertAtpos(int x,int pos){
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->next=NULL;
    if(pos==1){
        insertAtBegin(x);
    }
    else if (pos==count+1)
    {
        insertAtEnd(x);
    }
    else if(pos<=0 || pos>count+1){
        printf("!! INVALID POSITION !! \n");
        return;
    }
    else{
        struct node *temp=head;
        for(int i=1;i<(pos-1);i++){
            temp=temp->next;
        }
        new->next=temp->next;
        temp->next=new;
        count++;
    }
}
void display(){
    if(count==0){
        printf("THE LIST IS EMPTY\n");
        return;
    }
    struct node*temp=head;
    printf("\n THE ELEMENTS IN THE LIST ARE: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void delAtBegin(){
    if(count==0){
        printf("THE LIST IS EMPTY\n");
        return;
    }
    struct node *temp=head;
    printf("\n %d is deleted from the list\n",temp->data);
    head=head->next;
    count--;
}
void delAtEnd(){
    if(count==0){
        printf("THE LIST IS EMPTY\n");
        return;
    }
    if(count==1){
        delAtBegin();
    }
    else{
        struct node *temp=head;
        for(int i=1;i<count-1;i++){
            temp=temp->next;
        }
        int value =temp->next->data;
        printf("\n %d is deleted from the list \n",value);
        temp->next=NULL;
        count--;
    }
}
void delAtpos(int pos){
    if(pos==1 || count==0)
        delAtBegin();
    else if(pos==count)
        delAtEnd();
    else if(pos<=0 || pos>count){
        printf("!! INVALID POSITION !! \n");
        return;
    }
    else{
        struct node *temp=head;
        for(int i=1;i<(pos-1);i++){
            temp=temp->next;
        }
        int value=temp->next->data;
        printf("\n %d is deleted from the list \n",value);
        temp->next=temp->next->next;
        count--;
    }
}
int main(){
    int ch,data,pos;
    while(1){
        printf("\n ---LINKED LIST OPERATIONS--- ");
        printf("\n 1.INSERT AT BEGIN \n 2.INSERT AT POSITION \n 3.INSERT AT END \n");
        printf(" 4.DELETED AT BEGIN \n 5.DELETED AT POSITION \n 6.DELETED AT END \n");
        printf(" 7.DISPLAY \n 8.EXIT \n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("ENTER THE ELEMENT: ");
                scanf("%d",&data);
                insertAtBegin(data);
                break;
            case 2:
                printf("\nENTER THE ELEMENT: ");
                scanf("%d",&data);
                printf("\nENTER THE POSITION: ");
                scanf("%d",&pos);
                insertAtpos(data,pos);
                break;
            case 3:
                printf("ENTER THE ELEMENT: \n");
                scanf("%d",&data);
                insertAtEnd(data);
                break;
            case 4:
                delAtBegin();
                break;
            case 5:
                if(count==0){
                    printf("THE LIST IS EMPTY...");
                }
                else{
                    printf("ENTER THE POSITION: \n");
                    scanf("%d",&pos);
                    delAtpos(pos);
                }
                break;
            case 6:
                delAtEnd();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("---EXITING THE OPETARION---");
                exit(0);
                break;
            default:
                printf("!! INVALID INPUT please try again...\n");
        }
    }
    return 0;
}