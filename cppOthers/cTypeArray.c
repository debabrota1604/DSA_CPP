#include<stdio.h>
#include<stdlib.h>

int main(){
    // Declaring a character array
    char *ch;
    int len=10;

    // malloc allocates uninitialized void* type memory.
    // User needs to cast them properly and initialize them
    ch = (char *) malloc(sizeof(char)*len);

    // initialize the array
    for(int iter=0; iter<len; iter++){
        ch[iter] = 'A' +iter;
    }
    ch[9] = '\0'; //this helps in pointer iterator

    //show the array contents
    for(int iter=0; iter<len; iter++){
        printf("%c", ch[iter]);
    }
    printf("\n");
    // another way to print the same
    char *iter = ch;
    while(*iter !='\0'){
        printf("%c", *iter++);
    }
    printf("\n");

    //Free the array
    free(ch);


    // Declaring a 2D array
    int row = 3, col = 4, **mat;
    mat = (int **) malloc(sizeof(int *) * row); //each row is an integer array
    for(int iter=0; iter<row; iter++){
        mat[iter] = (int *) malloc(sizeof(int) *col);
    }
    int val=0;
    for(int iter=0; iter<row; iter++){
        for(int iter2=0; iter2<col; iter2++){
            mat[iter][iter2] = ++val;
        }
    }
    for(int iter=0; iter<row; iter++){
        for(int iter2=0; iter2<col; iter2++){
            printf("%d\t",mat[iter][iter2]);
        }
        printf("\n");
    }
    printf("\n");

    // Free the 2D Array
    for(int iter=0; iter<row; iter++){
        free(mat[iter]);
    }
    free(mat);
    
    return 0;
}