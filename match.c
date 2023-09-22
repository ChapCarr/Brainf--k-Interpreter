#include <stdio.h>


char stack[512];
int location[512];
int lCount = 0;
int count = 0;

void push(char x){
    stack[count] = x;
    count++;
}
char pop(){
    char res = stack[count - 1]; 
    count--;
    return res;
}

int main(){

    char testInput[] = {'a','b','[','d',']','b','c','d',};
    int testSize = sizeof(testInput)/testInput[0];

    for(int i = 0; i < 8; i++){
        switch (testInput[i]){
        case '[':
           push(testInput[i]);
            break;
        case ']':
        pop(); 
        location[lCount] = i;
        printf("%d", location[lCount]);
        default:
            break;
        }
        
    }
    


    return 0; 
}