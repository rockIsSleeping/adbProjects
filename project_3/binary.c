#include<stdio.h>
#define Datatype int


typedef struct _heap
{
    int capacity;
    int amount;
    Datatype* array;    /* First cell is empty.*/
}Heap;

int main(){

    return 0;
}



int Compare(Datatype a, Datatype b){   /* a>b return 1 */
    return a > b ? 1 : 0;
}

int Insertion(Heap* H, Datatype key){
    if(H->amount + 1 > H->capacity) return 0; /* Error */
    H->amount++;
    H->array[H->amount] = key;
    Increase_key(H, H->amount);
    return 1;
}

Datatype Delete_min(Heap* H){
    if(H->amount < 1) return NULL; /* Error */
    Datatype min = H->array[1];
    H->amount--;
    if(H->amount > 0){
        H->array[1] = H->array[H->amount + 1];
        Decrease_key(H, 1);
    }
    return min;
}

int Decrease_key(Heap* H, int number){
    while(1){
        if(number == 1 || Compare(H->array[number], H->array[number/2])) break;
        swap(&H->array[number/2], &H->array[number]);
        number = number/2;
    }
}

int Increase_key(Heap* H, int number){
    while(1){
        if(H->array[number*2] == NULL){
            break;
        }else if(H->array[number*2+1] == NULL){
            if(Compare(H->array[number], H->array[number*2])) swap(&H->array[number], &H->array[number*2]);
            break;
        }else{
            if(Compare(H->array[number*2], H->array[number*2+1])){
                if(Compare(H->array[number*2+1], H->array[number])){
                    break;
                }else{
                    swap(H->array[number], H->array[number*2+1]);
                    number = number*2 + 1;
                }
            }else{
                if(Compare(H->array[number*2], H->array[number])){
                    break;
                }else{
                    swap(H->array[number*2], H->array[number]);
                    number = number * 2;
                }
            }
        }
    }
}

void swap(Datatype* a, Datatype* b){
    Datatype temp = *a;
    *a = *b;
    *b = temp;
}