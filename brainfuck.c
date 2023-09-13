#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 3000

int main(){
    
    // declartions and such
    FILE *ptr; // file
    char ch[3000]; // ch is raw array with instructions 
    unsigned char tape[3000]; // tape for bf 
    tape[0] = 0;
    int cellIndex = 0; 
    int i = 0; // dont touch
    char single; // or this 
    int endOfInstruction = 0;
    char userInput; 
   


    // open bf file 
    ptr = fopen("test.txt", "r");
    if(ptr == NULL){
        printf("Error: File not found.");
    }
    // read bf file and put instructions into array

    while ((single = fgetc(ptr)) != EOF){
        // also idk how it did not work then it did work later but yay? 
        ch[i] = single;
        i++;
    }
    endOfInstruction = i; 
    

    // run through instructions 
    for(int z = 0; z < endOfInstruction; z++){
       // instruction for + 
       if (ch[z] == '+')
       {
        tape[cellIndex] += 1;

            if (tape[cellIndex] > 255){
            tape[cellIndex] = 0;
            }
       } 

       // instruction for -
       if (ch[z] == '-'){
        tape[cellIndex] -= 1;

            if(tape[cellIndex] < 0){
            tape[cellIndex] = 255;
            }
       }
       // instruction for <
       if (ch[z] == '<'){
        cellIndex -= 1;
       }
       if (ch[z] == '>'){
        cellIndex += 1;
       }

       // instructions for . 
        if(ch[z] == '.'){
            printf("%c", tape[cellIndex]);
        }
       // instructions for , 
       if (ch[z] == ','){
        scanf("%c", &userInput);
        tape[cellIndex] = userInput; 
       }
       
        //TODO make instructions for [
        // make use of a stack to check for equal bracket matching**
        // TODO make instructions for ]
       
    
    }

    //printf("index 0: %c\n", tape[0]);
    //printf("index 1: %c\n", tape[1]);
    //printf("index 2: %c\n", tape[2]);


 fclose(ptr);
 return 0;   
}
