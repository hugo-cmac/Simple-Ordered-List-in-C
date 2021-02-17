#include <stdio.h>
#include <stdlib.h>

typedef struct Ordered_Queue{
    int index;
    int data;
    struct Ordered_Queue *next;
}orderedqueue;

orderedqueue *head = NULL;

orderedqueue *newNode(int index, int data){
    orderedqueue *temp = malloc(sizeof(orderedqueue));
    temp->data = data;
    temp->index = index;
    temp->next = NULL;
    return temp;
}

void push(int index, int data){
    orderedqueue *temp = newNode(index, data);

    if (head == NULL){
        head = temp;
        head->next = NULL;
    }else{
        orderedqueue *now = head;
        orderedqueue *prev = NULL;

        while (now != NULL && index > now->index){
            prev = now;
            now = now->next;
        }

        if (now == NULL) { //Node goes to last position
            prev->next = temp;
        } else {
            if(prev != NULL){// Node goes somewhere in the Middle
                temp->next = now;
                prev->next = temp;
            }else{// Node goes to first position
                temp->next = head;
                head = temp;
            }
        }
    }
}

int pop(){
    if (head != NULL){
        orderedqueue* temp = head;
        head = head->next;
        int data = temp->data;
        free(temp);
        return data;
    }
    return -1;
}


void preview(){
    if (head == NULL){
        printf("Empty list.\n");
    }else{
        orderedqueue *now = head;
        while (now != NULL){
            printf("[%d] -> %d\n", now->index, now->data);
            now = now->next;
        }
    }
}

int main(int argc, char const *argv[]){

    int index, data;

    // Add 12 on position 5
    index = 5;
    data = 12;
    push(index, data);

    // Add 1  on position 7
    index = 7;
    data = 1;
    push(index, data);

    // Add 4  on position 80
    index = 80;
    data = 4;
    push(index, data);

    // Add 55 on position 35
    index = 35;
    data = 55;
    push(index, data);

    // Add 25 on position 30
    index = 30;
    data = 25;
    push(index, data);

    // Add 56 on position 12
    index = 12;
    data = 56;
    push(index, data);


    preview();    


    int value = 0;

    while ((value = pop()) != -1){
        printf(" -> %d\n", value);
    }
    
    return 0;
}
