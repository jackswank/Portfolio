#include <iostream>
#include <stdio.h>
#define MAX 6
using namespace std;

int stack [MAX];
int front = 0;
int rear = 0;
int d; //This is assigned to deleted elements so they aren't printed

int menu(){
    int ch;
    printf("\n1. Insert");
    printf("\n2. Delete");
    printf("\n3. Display");
    printf("\n4. Quit\n");
    scanf("%d", &ch);
    return ch;
}

void displayQ(){
    int i;
    if(front==rear){
        printf("\n Queue is empty");
        return;
    }
    else{
        printf("\n Element in queue: ");
        for(i=0;rear > i;i++)
            if(stack[i] == d){
                ; //This helps skip over deleted elements
            }
            else{
                printf("\t %d", stack[i]);
            }
    }
}

void deleteQ(){
    if (front==rear){
        printf("\n Queue is empty");
        return;
    }
    else
    {
        printf("\n Element that's being deleted: ");
        cout << stack[front]; 
        stack[front] = d; 
        front = front +1;
    }
}

void insertQ(){
    int data;
    if(front==MAX){
        printf("\n Queue overflow");
        return;
    }
    else{
        printf("\n Enter data: ");
        scanf("%d", &data);
        stack[rear] = data;
        rear = rear + 1;
        printf("\n Data inserted into the queue");
    }
}

void mainn(){
    int ch;
    do{
        ch=menu();
        switch(ch){
            case 1:
                insertQ();
                break;
            case 2:
                deleteQ();
                break;
            case 3:
                displayQ();
                break;
            case 4:
                exit(0);
        }
    }while(1);
}

int main()
{
    mainn();
    return 0;
}